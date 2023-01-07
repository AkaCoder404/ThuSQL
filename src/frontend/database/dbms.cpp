#include "dbms.h"
#include "filesystem"
#include "../../../third-party/tabulate/table.hpp"
#include <list>
#include <vector>
#include <string>


dbms::dbms() { }
dbms::~dbms() { 
    curr_db->close(); 
    dprint("Good bye!!!");
}

void dbms::create_database(const char *database_name) {
    std::string name = database_name;
    name += ".db";
    if (std::filesystem::exists(name)) {
        eprint("Database already exists");
        return;
    }
    database db;
    db.create(database_name);
    db.close();
}

void dbms::open_database(const char *database_name) {
    if (curr_db) {
        curr_db->close();
        delete curr_db;
        curr_db = nullptr;
    }

    curr_db = new database();
    curr_db->open(database_name);
}

void dbms::show_database(const char *database_name) {
    // database db;
    // db.open(database_name);
    // db.show_database_info(true);

    if (!curr_db) {
        eprint("use database before showing");
        return;
    }
    curr_db->show_database_info(true);
}

void dbms::drop_database(const char *database_name) {
    database db;
    bool success = db.open(database_name);
    if (!success) {
        eprint("database does not exist, cannot drop");
        return;
    }
    db.drop(); 
}

void dbms::close_database() {
    if (curr_db) {
        curr_db->close();
        delete curr_db;
        curr_db = nullptr;
    }
}

void dbms::show_databases() {
    std::string path = "./";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::string temp = entry.path();
        if (temp.find(".db")  != std::string::npos) {
            temp = temp.substr(0,  temp.length() - 3);
            temp = temp.substr(2);
            show_database(temp.c_str());
        }
    }
}

void dbms::create_table(table_header *header) {
    curr_db->create_table(header);
}

void dbms::show_table(const char *table_name) {
    curr_db->show_table(table_name);
}

void dbms::drop_table(const char *table_name) {
    curr_db->drop_table(table_name);
}

void dbms::insert_rows(SQLParser::Insert_into_tableContext *ctx) {
    tprint("Inserting rows");
    const char *table_name = ctx->Identifier()->getText().c_str();
    table* tb = curr_db->get_table(table_name);
    
    table_header *th = tb->get_table_header_p();

    std::cout << "Inserting into " << th->table_name << "\n";
    int success = 0;
    int total = 0;

    // do checks
    auto value_lists = ctx->value_lists()->value_list();
   
    for (auto & e : value_lists) {                  // for each record
        total++;
        // std::cout << e->getText() << "\n";
                                
        if (e->value().size() != th->col_num) {
            std::cout << "Col number mismatch, will not insert: " <<  e->getText() << "\n";
            continue;
        }

        // check correct type of each col
        int col = 0;
        bool succ = true;
        for (auto & d : e->value()) {               // for each col
            if (th->col_type[col] == FIELD_TYPE_INT && d->Integer() == 0) {
                std::cout << "Col Type INT mismatch, will not insert: " << e->getText() << "\n";
                succ = false;
                break;
            }
            else if (th->col_type[col] == FIELD_TYPE_FLOAT && d->Float() == 0) {
                std::cout << "Col Type FLOAT mismatch, will not insert: " << e->getText() << "\n";
                succ = false;
                break;
            }
            else if (th->col_type[col] == FIELD_TYPE_VCHAR && d->String() == 0) {
                succ = false;
                std::cout << "Col Type VCHAR mismatch, will not insert: " << e->getText() << "\n";
                break;
            }
            else if (th->col_type[col] == FIELD_TYPE_VCHAR && d->String() != 0) {
                if (d->getText().length() > th->col_length[col]) {
                    succ = false;
                    std::cout << "VCHAR too long, will not insert: " << e->getText() << "\n";
                    break;
                }
            } // TODO check not null
            col++;
        }   

        if (succ) {
            std::cout << "Record " << total << " has been successfully inserted" << "\n";
            success += 1;
        } 
        else continue;

        // pass all checks
        // allocate 
        char *temp_record;
        int size = th->col_offset[th->col_num - 1] + th->col_length[th->col_num - 1];
        std::cout << "size of record:" << size << "\n";
        temp_record = new char[size];
        
        // initialize
        // TODO initialize defaults
        memset(temp_record, 0, size);
        memcpy(temp_record, &th->auto_increment_row_id, 4); 
        std::cout << "init tmp record: " << th->auto_increment_row_id << "\n";
        th->auto_increment_row_id++;
        th->records_num++;
        // tb->increase_record_count();
        // table_header *t = tb->get_table_header_p();
        // t->records_num++;
       

        // go
        col = 0;
        for (auto & cols : e->value()) {
            if (cols->Integer()) {
                int s = std::stoi(cols->getText());
                std::memcpy(temp_record + th->col_offset[col], &s, th->col_length[col]);
            }
            else if (cols->Float()) {
                float s = std::stof(cols->getText());
                std::memcpy(temp_record + th->col_offset[col], &s, th->col_length[col]);
            }
            else if (cols->String()) {
                const char *s = cols->getText().c_str();
                std::memcpy(temp_record + th->col_offset[col], s, th->col_length[col]);

            }
            col++;
        }
        tb->insert_record(temp_record, size);
        delete []temp_record;
    }
    // 
    std::cout << "Successfully inserted " << success << " out of " << total << "\n";
}

void dbms::delete_rows(std::string where, const char *table_name) {
    tprint("deleting rows");
    table* tb = curr_db->get_table(table_name);
    table_header *th = tb->get_table_header_p();

    int size_of_record = th->col_offset[th->col_num - 1] + th->col_length[th->col_num - 1];
    std::cout << "Total Records in this table: " << th->records_num << "\n";
    std::cout << "Size of one record in bytes: " << size_of_record << "\n";

    // WHERE columns
    std::vector<std::pair<int, std::string>> vec = {};
    for (int i = 0; i < th->col_num; i++) {
        std::string str(th->col_name[i]);
        if (where.find("D" + str + "=") != std::string::npos) { //ANDcolname=5
            int start = where.find(str) + strlen(th->col_name[i]) + 1;
            std::string remaining = where.substr(start, where.length() - start);
            int length = remaining.find("AND") == std::string::npos ? remaining.length() : remaining.find("AND");
            // std::cout << "found " << th->col_name[i] << "\n";
            vec.push_back(std::make_pair(i, where.substr(start, length)));
            continue;
        }
        if (where.find(str + "=") == 0) {                       // first entry
            // std::cout << "found " << th->col_name[i] << "\n";
            int start = strlen(th->col_name[i]) + 1;
            int length = where.find("AND") == std::string::npos ? where.length() - start : where.find("AND") - start;
            vec.push_back(std::make_pair(i, where.substr(start, length)));
        }
    }

    // for (int i = 0; i < vec.size(); i++) {
    //     std::cout << vec[i].first << vec[i].second << "\n";
    // }
    // read backwards
    int count_deleted = 0;
    int read_rows = RECORDS_PER_READ;         // read bytes from [start, start + 20 * size]

    int start, records_to_read;
    if (th->records_num < read_rows) {
        start = 0;
        records_to_read = th->records_num;
    }
    else if (th->records_num % read_rows == 0) {
        start = th->records_num - read_rows;
        records_to_read = read_rows;
    }
    else {
        start = th->records_num - (th->records_num % read_rows);
        records_to_read = (th->records_num % read_rows);
    }
    char *buffer = (char *)malloc(sizeof(char) * (size_of_record * read_rows));
    while (start >= 0) {
        std::cout << "start: " << start << "\n";
        memset((void *)buffer, 0, size_of_record * read_rows);

        if (records_to_read == read_rows) tb->select_record(start, buffer, size_of_record, read_rows);
        else tb->select_record(start, buffer, size_of_record, records_to_read);

        // delete
        int last_record = records_to_read;
        for (int i = last_record; i >= 0; i--) {
            int rowid; memcpy(&rowid, buffer + i * size_of_record, 4);
            std::cout << "rowid" << rowid << "\n";

            // see if row matches
            bool match_row = true;
            for (int j = 0; j < vec.size(); j++) {
                if (th->col_type[vec[j].first] == FIELD_TYPE_INT) {
                    int s; memcpy(&s, buffer + i * size_of_record + th->col_offset[vec[j].first], th->col_length[vec[j].first]);
                    if (stoi(vec[j].second) != s) {
                        match_row = false;
                        break;
                    }
                } else if (th->col_type[vec[j].first] == FIELD_TYPE_FLOAT) {
                    float s; memcpy(&s, buffer + i * size_of_record + th->col_offset[vec[j].first], th->col_length[vec[j].first]);
                    if (stof(vec[j].second) != s) {
                        match_row = false;
                        break;
                    }
                } else if (th->col_type[vec[j].first] == FIELD_TYPE_VCHAR) {
                    char s[th->col_length[vec[j].first]];
                    memcpy(s, buffer + i * size_of_record + th->col_offset[vec[j].first], th->col_length[vec[j].first]);
                    if (vec[j].second != s) {
                        match_row = false;
                        break;
                    }
                }
            }

            if (!match_row) continue;
            
            // row matches
            tb->delete_record(rowid, size_of_record);
            th->records_num--;
            th->auto_increment_row_id--;
            count_deleted++;
        }
        free(buffer);
        start -= read_rows;
    }
    std::string message = "deleted total rows of " + std::to_string(count_deleted);
    dprint(message.c_str());
}


void match_rows() {

}

bool select_row_by_cols(std::string cols, char *col) {
    // if column name matches 
    std::string match = "\"" + std::string(col) + "\"";
    if (cols.find(match) == std::string::npos && cols != "\"*\"") return true;
    return false;  
}


void dbms::select_rows(std::string cols, std::string where, const char * table_name) {
    tprint("Selecting rows");   
    int total_rows = 5;
    table* tb = curr_db->get_table(table_name);
    table_header *th = tb->get_table_header_p();
  
    int size = th->col_offset[th->col_num - 1] + th->col_length[th->col_num - 1];
    std::cout << "Total Records in this table " << th->records_num << "\n";
    std::cout << "Size of one record in bytes: " << size << "\n";

    // OUTPUT: table header
    int total_cols_selected = 0;        // SELECT col1, col2 FROM
    tabulate::Table select;
    std::vector<variant<std::string, const char *, string_view, tabulate::Table>> header = {"rowid"};
    for (int i = 0; i < th->col_num; i++) {
        if (select_row_by_cols(cols, th->col_name[i])) continue;
        header.push_back(th->col_name[i]);
        total_cols_selected++;
    }
    select.add_row(header);

    // HANDLE WHERE columns
    // find which column it is, TODO handle errors in where (column might not exists)
    std::vector<std::pair<int, std::string>> vec = {};
    for (int i = 0; i < th->col_num; i++) {
        std::string str(th->col_name[i]);
        if (where.find("D" + str + "=") != std::string::npos) { //ANDcolname=5
            int start = where.find(str) + strlen(th->col_name[i]) + 1;
            std::string remaining = where.substr(start, where.length() - start);
            int length = remaining.find("AND") == std::string::npos ? remaining.length() : remaining.find("AND");
            // std::cout << "found " << th->col_name[i] << "\n";
            vec.push_back(std::make_pair(i, where.substr(start, length)));
            continue;
        }
        if (where.find(str + "=") == 0) {                       // first entry
            // std::cout << "found " << th->col_name[i] << "\n";
            int start = strlen(th->col_name[i]) + 1;
            int length = where.find("AND") == std::string::npos ? where.length() - start : where.find("AND") - start;
            vec.push_back(std::make_pair(i, where.substr(start, length)));
        }
    }

    // total rows to read
    total_rows = th->records_num;


    int start = 0;      
    int rows_per_read = RECORDS_PER_READ;            // read from file [start, size * rows_per_read];
    int rows_added = 0;
    while (start < total_rows && rows_added < SELECT_LIMIT) {
        // if remaining rows less than rows_per_read
        if (total_rows - start < rows_per_read) rows_per_read = total_rows - start;
        char *buffer = (char *)malloc(sizeof(char) * (size * rows_per_read));
        memset((void *)buffer, 0, size * rows_per_read);
        tb->select_record(start, buffer, size, rows_per_read);

        // populate rows
        for (int i = 0; i < rows_per_read && rows_added < SELECT_LIMIT; i++) {
            std::vector<variant<std::string, const char *, string_view, tabulate::Table>> row = {};
            int rowid; memcpy(&rowid, buffer + i * size, 4);
            row.push_back(std::to_string(rowid));

            // TODO WHERE
            bool match_row = true;
            for (int j = 0; j < vec.size(); j++) {
                if (th->col_type[vec[j].first] == FIELD_TYPE_INT) {
                    int s; memcpy(&s, buffer + i * size + th->col_offset[vec[j].first], th->col_length[vec[j].first]);
                    if (stoi(vec[j].second) != s) {
                        match_row = false;
                        break;
                    }
                } else if (th->col_type[vec[j].first] == FIELD_TYPE_FLOAT) {
                    float s; memcpy(&s, buffer + i * size + th->col_offset[vec[j].first], th->col_length[vec[j].first]);
                    if (stof(vec[j].second) != s) {
                        match_row = false;
                        break;
                    }
                } else if (th->col_type[vec[j].first] == FIELD_TYPE_VCHAR) {
                    char s[th->col_length[vec[j].first]];
                    memcpy(s, buffer + i * size + th->col_offset[vec[j].first], th->col_length[vec[j].first]);
                    if (vec[j].second != s) {
                        match_row = false;
                        break;
                    }
                }
            }
            if (!match_row) continue;

            // row matches
            for (int j = 0; j < th->col_num; j++) {
                if (select_row_by_cols(cols, th->col_name[j])) continue; 
                
                if (th->col_type[j] == FIELD_TYPE_INT) {
                    int s; memcpy(&s, buffer + i * size + th->col_offset[j], th->col_length[j]);
                    row.push_back(std::to_string(s));
                } else if (th->col_type[j] == FIELD_TYPE_FLOAT) {
                    float s; memcpy(&s, buffer + i * size + th->col_offset[j], th->col_length[j]);
                    row.push_back(std::to_string(s));
                } else if (th->col_type[j] == FIELD_TYPE_VCHAR) {
                    char s[th->col_length[j]];
                    memcpy(s, buffer + i * size + th->col_offset[j], th->col_length[j]);
                    row.push_back(std::string(s));
                }
            }
            select.add_row(row);
            rows_added++;
        }

        // 
        free(buffer);
        start += rows_per_read;
    }



    // char *buffer = (char *)malloc(sizeof(char) * (size * total_rows));
    // memset((void *)buffer, 0, size * total_rows);
    // tb->select_record(buffer, size, total_rows);

   

   
    // for (int i = 0; i < vec.size(); i++) {
    //     std::cout << vec[i].first << vec[i].second << "\n";
    // }



    // style header
    for (size_t i = 0; i < total_cols_selected + 1; ++i) {
        select[0][i].format()
        .font_color(tabulate::Color::yellow)
        .font_align(tabulate::FontAlign::center)
        .font_style({tabulate::FontStyle::bold});
    }
    std::cout << select << "\n";
    // free(buffer);
}

void dbms::update_rows() {}