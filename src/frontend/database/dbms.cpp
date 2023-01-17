#include "dbms.h"
#include "filesystem"
#include "../../../third-party/tabulate/table.hpp"
#include <list>
#include <vector>
#include <string>


dbms::dbms() { }
dbms::~dbms() { 
    curr_db->close(); 
    dprint("Leaving ThuSQL DBMS, goodbye!!!");
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
    database db;
    db.open(database_name);
    db.show_database_info(true, true);

    // if (!curr_db) {
    //     eprint("use database before showing");
    //     return;
    // }
    // curr_db->show_database_info(true);
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

void dbms::show_tables() {
    tprint("show_tables");
    curr_db->show_database_info(true, false);
    curr_db->show_tables();
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
        temp_record = new char[size];
        
        // initialize
        // TODO: initialize defaults
        memset(temp_record, 0, size);
        memcpy(temp_record, &th->auto_increment_row_id, 4);
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
    std::string message = "Insert OK " + std::to_string(success) + " out of " + std::to_string(total);
    dprint(message.c_str());
}

bool check_where_op (std::string op, float value2, float value1) {
    // =, !=, >, >=, <, <=
    // std::cout << "checking where op: " << value1 << " " << op << " " << value2 << "\n";
    if (op == "=") {
        return value1 == value2;
    } else if (op == "!=") {
        return value1 != value2;
    } else if (op == ">") {
        return value1 > value2;
    } else if (op == "<") {
        return value1 < value2;
    } else if (op == ">=") {
        return value1 >= value2;
    } else if (op == "<=") {
        return value1 <= value2;
    }
    return true;
}

bool check_where(table_header* th, int record_size, int record_num, char* buffer, 
                std::vector<int> where_col_in_table, 
                std::vector<struct WhereContext>& where) {
    
    if (where.size() == 0) return true;

    bool check_is_true = true;
    for (int i = 0; i < where_col_in_table.size(); i++) {
        int col = where_col_in_table[i];
        if (th->col_type[col] == FIELD_TYPE_INT) {
            int s; memcpy(&s, buffer + record_num * record_size + th->col_offset[col], th->col_length[col]);
            check_is_true = check_where_op(where[i].op, stof(where[i].value), float(s));

        } else if (th->col_type[col] == FIELD_TYPE_FLOAT) {
            float s; memcpy(&s, buffer + record_num * record_size + th->col_offset[col], th->col_length[col]);
            check_is_true = check_where_op(where[i].op, stof(where[i].value), s);

        } else if (th->col_type[col] == FIELD_TYPE_VCHAR) {
            char s[th->col_length[col]];
            memcpy(s, buffer + record_num * record_size + th->col_offset[col], th->col_length[col]);
            check_is_true =where[i].value == s;
        }
        if (!check_is_true) return false;
    }


    return true;
}


void dbms::delete_rows(const char* table_name, std::vector<struct WhereContext>& where) {
    // table information
    table *tb = curr_db->get_table(table_name);
    table_header *th = tb->get_table_header_p();
    int total_cols = th->col_num - 1;
    int record_size = th->col_offset[total_cols] + th->col_length[total_cols];
    std::cout << "Total Records in this table: " << th->records_num << "\n";
    std::cout << "Size of one record in bytes: " << record_size  << "\n";

    // location of where column in table 
    std::vector<int> where_col_in_table;
    for (int i = 0; i < where.size(); i++) {
        for (int j = 0; j < th->col_num; j++ ) {
            if (th->col_name[j] == where[i].column) where_col_in_table.push_back(j);
        }
    }

    // read from mem, start reading from end 
    int records_deleted = 0;
    int records_per_read = RECORDS_PER_READ;

    int start_read, records_to_read;

    if (th->records_num < records_per_read) {
        start_read = 0;
        records_to_read = th->records_num;
    } else if (th->records_num % records_per_read == 0) {
        start_read = th->records_num - records_per_read;
        records_to_read = (th->records_num % records_per_read);
    } else {
        start_read = th->records_num - (th->records_num % records_per_read);
        records_to_read = (th->records_num % records_per_read);
    }

    // start reading from memory to buffer, then check buffer if meets where clause
    char *buffer = (char *)malloc(sizeof(char) * (record_size * records_per_read));
    while (start_read >= 0) {
        memset((void *)buffer, 0, (record_size * records_per_read));

        // 
        if (records_to_read == records_per_read) 
            tb->select_record(start_read, buffer, record_size, records_to_read);
        else tb->select_record(start_read, buffer, record_size, records_to_read);

        //
        int last_record = records_to_read;
        for (int i = last_record - 1; i >= 0; i--) {
            int rowid; memcpy(&rowid, buffer + i * record_size, 4);

            bool match_row = check_where(th, record_size, i, buffer, where_col_in_table, where);
            if (!match_row) continue;

            tb->delete_record(th->records_num, rowid, record_size);
            th->records_num--;
            th->auto_increment_row_id--;
            records_deleted++;
        }


        // update for next set
        if (records_to_read != records_per_read) {
            records_to_read = records_per_read;
        }
        start_read -= records_per_read;
    }

    free(buffer);
    std::string message = "deleted " + std::to_string(records_deleted) + " record(s)";
    dprint(message.c_str());
}

void dbms::select_rows(std::vector<std::string> selectors, std::vector<struct WhereContext>& where, const char* table_name) {
    // get table info
    table *tb = curr_db->get_table(table_name);
    table_header *th = tb->get_table_header_p();

    int total_cols = th->col_num - 1;
    int record_size = th->col_offset[total_cols] + th->col_length[total_cols];

    std::cout << "Total Records in this table " << th->records_num << "\n";
    std::cout << "Size of one record in bytes: " << record_size <<  "\n";

     // match where the column is in table
    std::vector<int> where_col_in_table;
    for (int i = 0; i < where.size(); i++) {
        for (int j = 0; j < th->col_num; j++ ) {
            if (th->col_name[j] == where[i].column) where_col_in_table.push_back(j);
        }
    }

   
    // output table header  
    int total_cols_selected = 0;
    tabulate::Table select;
    std::vector<variant<std::string, const char *, string_view, tabulate::Table>> header = {"rowid"};
    for (int i = 0; i < th->col_num; i++) {
        if (selectors.size() && std::find(selectors.begin(), selectors.end(), std::string(th->col_name[i])) == selectors.end()) continue;
        header.push_back(th->col_name[i]);
        total_cols_selected++;
    }
    select.add_row(header);


    // start reading
    int total_records = th->records_num;
    int start_read = 0;                     // [start, start + records_per_read]
    int rows_per_read = RECORDS_PER_READ;
    int rows_selected = 0;

    char *buffer = (char *)malloc(sizeof(char) * (record_size * rows_per_read));
    while (start_read < total_records && rows_selected < SELECT_LIMIT) {
        // if remaining records is less than the number of records_per_read;
        int remaining_records = total_records - start_read;
        if (remaining_records < rows_per_read) rows_per_read = remaining_records;

        // allocate and read from mem
        
        memset((void *)buffer, 0, record_size * rows_per_read);
        tb->select_record(start_read, buffer, record_size, rows_per_read);


        // populate rows
        for (int i = 0; i < rows_per_read && rows_selected < SELECT_LIMIT; i++) {
            std::vector<variant<std::string, const char *, string_view, tabulate::Table>> row = {};
            int rowid; memcpy(&rowid, buffer + i * record_size, 4);
            row.push_back(std::to_string(rowid));

            // check row matches where context
            bool match_row = check_where(th, record_size, i, buffer, where_col_in_table, where);
            if (!match_row) continue;

            // row matches, add columns based on selectors
            for (int j = 0; j < th->col_num; j++) {
                if (selectors.size() && std::find(selectors.begin(), selectors.end(), std::string(th->col_name[j])) == selectors.end()) continue;
                
                if (th->col_type[j] == FIELD_TYPE_INT) {
                    int s; memcpy(&s, buffer + i * record_size + th->col_offset[j], th->col_length[j]);
                    row.push_back(std::to_string(s));
                } else if (th->col_type[j] == FIELD_TYPE_FLOAT) {
                    float s; memcpy(&s, buffer + i * record_size + th->col_offset[j], th->col_length[j]);
                    row.push_back(std::to_string(s));
                } else if (th->col_type[j] == FIELD_TYPE_VCHAR) {
                    char s[th->col_length[j]];
                    memcpy(s, buffer + i * record_size + th->col_offset[j], th->col_length[j]);
                    row.push_back(std::string(s));
                }
            }

            select.add_row(row);
            rows_selected++;
        }
        
        start_read += rows_per_read;
    }
    free(buffer);


    for (size_t i = 0; i < total_cols_selected + 1; ++i) {
        select[0][i].format()
        .font_color(tabulate::Color::yellow)
        .font_align(tabulate::FontAlign::center)
        .font_style({tabulate::FontStyle::bold});
    }
    std::cout << select << "\n";
    std::string selected_message = "selected " + std::to_string(rows_selected) + " record(s) out of " + std::to_string(total_records) + " records";
    dprint(selected_message.c_str());
}

void dbms::update_rows(const char* table_name, std::vector<struct WhereContext>& where, std::vector<struct SetContext>& set) {
    // get table info
    table *tb = curr_db->get_table(table_name);
    table_header *th = tb->get_table_header_p();

    int total_cols = th->col_num - 1;
    int record_size = th->col_offset[total_cols] + th->col_length[total_cols];

    std::cout << "Total Records in this table " << th->records_num << "\n";
    std::cout << "Size of one record in bytes: " << record_size <<  "\n";

    // match where the column in table
    std::vector<int> where_col_in_table;
    for (int i = 0; i < where.size(); i++) {
        for (int j = 0; j < th->col_num; j++ ) {
            if (th->col_name[j] == where[i].column) where_col_in_table.push_back(j);
        }
    }

    // match set the column in table
    std::vector<int> set_col_in_table;
    for (int i = 0; i < where.size(); i++) {
        for (int j = 0; j < th->col_num; j++ ) {
            if (th->col_name[j] == set[i].column) set_col_in_table.push_back(j);
        }
    }

    // start reading
    int start_read = 0;
    int records_per_read = RECORDS_PER_READ;
    int rows_updated = 0;
    int total_records = th->records_num;

    char *buffer = (char *)malloc(sizeof(char) * (record_size * records_per_read));
    while (start_read < total_records) {
        // if remaining records is less than the number of records_per_read
        int remaining_records = total_records - start_read;
        if (remaining_records < records_per_read) records_per_read = remaining_records;

        // allocate and read from mem
        // char *buffer = (char *)malloc(sizeof(char) * (record_size * records_per_read));
        memset((void *)buffer, 0, record_size * records_per_read);
        tb->select_record(start_read, buffer, record_size, records_per_read);

        // scan through all records
        for (int i = 0; i < records_per_read; i++) {  
            int rowid; memcpy(&rowid, buffer + i * record_size, 4);

            // check row matches where context
            bool match_row = check_where(th, record_size, i, buffer, where_col_in_table, where);
            if (!match_row) continue;

            // row matches, update buffer based on select
            for (int j = 0; j < th->col_num; j++) {
                std::string col_name = std::string(th->col_name[j]);
                auto it = std::find_if(set.begin(), set.end(), [&col_name](const SetContext& obj) {return obj.column == col_name;});
                if (it == set.end()) continue;
                
            
                if (th->col_type[j] == FIELD_TYPE_INT) {
                    std::string s = (*it).value;
                    const char *t = s.c_str();
                    memcpy(buffer + i * record_size + th->col_offset[j], &t,th->col_length[j]);
                } else if (th->col_type[j] == FIELD_TYPE_FLOAT) {
                    std::string s = (*it).value;
                    const char *t = s.c_str();
                    memcpy(buffer + i * record_size + th->col_offset[j], &t,th->col_length[j]);
                } else if (th->col_type[j] == FIELD_TYPE_VCHAR) {
                    std::string s = (*it).value;
                    const char *t = s.c_str();
                    std::cout << j << ":" <<  s <<  "\n";
                    // memset(buffer + i * record_size + th->col_offset[j], 0, th->col_length[j]);
                    memcpy(buffer + i * record_size + th->col_offset[j], t, th->col_length[j]);
                }
            }
            // write back to memory
            tb->update_record(start_read, buffer, i, record_size, records_per_read);
            rows_updated++;
        }
        
        
    
        start_read += records_per_read;
        std::string selected_message = "updated " + std::to_string(rows_updated) + " record(s) out of " + std::to_string(total_records) + " records";
        dprint(selected_message.c_str());
    }
    free(buffer);
}