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
    database db;
    db.open(database_name);
    db.show_database_info(true);
}

void dbms::drop_database(const char *database_name) {}

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

void dbms::select_rows(const char * table_name) {
    tprint("Selecting rows");   
    table* tb = curr_db->get_table(table_name);
    table_header *th = tb->get_table_header_p();
    std::cout << "Total Records in this table " << th->records_num << "\n";
 

    int size = th->col_offset[th->col_num - 1] + th->col_length[th->col_num - 1];
    std::cout << "Size of one record in bytes: " << size << "\n";
    char *buffer = new char[size * 3];
    tb->select_record(buffer, size, 3); // TODO support not continuous storage

    // TODO only return wanted cols
    tabulate::Table select;
    std::vector<variant<std::string, const char *, string_view, tabulate::Table>> header = {"rowid"};
    for (int i = 0; i < th->col_num; i++) {
        header.push_back(th->col_name[i]);
    }

    select.add_row(header);

    // TODO limit 
    for (int i = 0; i < 2; i++) {
        std::vector<variant<std::string, const char *, string_view, tabulate::Table>> row = {};
        int rowid; memcpy(&rowid, buffer + i * size, 4);
        row.push_back(std::to_string(rowid));

        for (int j = 0; j < th->col_num; j++) {
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
    }

    for (size_t i = 0; i < th->col_num + 1; ++i) {
        select[0][i].format()
        .font_color(tabulate::Color::yellow)
        .font_align(tabulate::FontAlign::center)
        .font_style({tabulate::FontStyle::bold});
    }
    std::cout << select << "\n";
}


void dbms::update_rows() {}