#include "database.h"
#include "../../../third-party/tabulate/table.hpp"
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <fstream>

database::database() { 
    is_opened = false;
}

database::~database() {
    // dprint("Closed Database");
    if(is_opened) close();
}

void database::create(const char* name) {
    assert(!is_opened);
    memset(&info, 0, sizeof(info));    // alloc space for info
    memset(tables, 0, sizeof(tables)); // alloc space for tables
    strncpy(info.database_name, name, MAX_DB_NAME_LEN);
    is_opened = true;

}

bool database::open(const char* name) {
    assert(!is_opened);
    std::string filename = name;
    filename += ".db"; 

    FILE *fp = fopen(filename.c_str(), "rb");
    if (fp == NULL) {
        return false;
    }


    memset(&info, 0, sizeof(info));
    fread(&info, sizeof(info), 1, fp);
    fclose(fp);
    // read tables
    memset(tables, 0, sizeof(tables));
	for(int i = 0; i < info.table_num; ++i) {
		tables[i] = new table;
		tables[i]->open(info.table_names[i]);
	}
    is_opened = true;
    return true;
}

void database::close() {
    tprint("closing db");
    assert(is_opened);
    // close all tables
    for(table *tb : tables) {
		if(tb != nullptr){
			tb->close();
			delete tb;
			tb = nullptr;
		}
	}

    std::string filename = info.database_name;
    filename += ".db";
    FILE *fp = fopen(filename.c_str(), "wb");
    fwrite(&info, sizeof(info), 1, fp);
    fclose(fp);
    is_opened = false;

}

void database::drop() {
    assert(is_opened);
    for(table *tb: tables) {
        if (tb != nullptr) {
            tb->drop();
            delete tb;
            tb = nullptr;
        }
    }
    std::string filename = info.database_name;
    filename += ".db";
    std::remove(filename.c_str());
    is_opened = false;
}

void database::show_database_info(bool show_tables) {
    tabulate::Table database_info;
    const char* title = "Database Info"; 
    database_info.add_row({title});
    database_info.format()
      .multi_byte_characters(true)
      // Font styling
      .font_style({tabulate::FontStyle::bold, tabulate::FontStyle::dark})
      .font_align(tabulate::FontAlign::center)
      .font_color(tabulate::Color::red)
      //.font_background_color(tabulate::Color::yellow)
      // Corners
      .corner_top_left("ᛰ")
      .corner_top_right("ᛯ")
      .corner_bottom_left("ᛮ")
      .corner_bottom_right("ᛸ")
      .corner_top_left_color(tabulate::Color::cyan)
      .corner_top_right_color(tabulate::Color::yellow)
      .corner_bottom_left_color(tabulate::Color::green)
      .corner_bottom_right_color(tabulate::Color::red)
      // Borders
      .border_top("ᛜ")
      .border_bottom("ᛜ")
      .border_left("ᚿ")
      .border_right("ᛆ")
      .border_left_color(tabulate::Color::yellow)
      .border_right_color(tabulate::Color::green)
      .border_top_color(tabulate::Color::cyan)
      .border_bottom_color(tabulate::Color::red);

    database_info[0].format().width(61);
    std::cout << database_info << std::endl;
    
    tabulate::Table db_info;
    db_info.add_row({"Database_name", info.database_name});
    db_info.add_row({"Number of Tables", std::to_string(info.table_num)});
    db_info[0].format().width(30);
    db_info[1].format().width(10);
    std::cout << db_info << std::endl;

    // print all tables
    if (!show_tables) return;
    tabulate::Table tables;
    tables.add_row({"#", "Table Name"});
    for (int i = 0; i < info.table_num; i++) {
        tables.add_row({std::to_string(i + 1), info.table_names[i]});
        tables[i+1][0].format().width(4);
        tables[i+1][1].format().width(56);
    }
    std::cout << tables << std::endl;
}

void database::create_table(table_header *header) {
    assert(is_opened);
    if (get_table(header->table_name)) {
        eprint("Table already exists");
    } else {
        printf("create table %d\n", info.table_num);
        int id = info.table_num++;
        strncpy(info.table_names[id], header->table_name, MAX_TABLE_NAME_LEN);
        tables[id] = new table;
        tables[id]->create(header);
    }
}

void database::show_table(const char*name) {
    assert(is_opened);
    int id = get_table_id(name);
    if (id == -1) {
        eprint("Table does not exist");
    } else { 
        tprint("Found table");

        tabulate::Table table_info;
        std::string name = tables[id]->get_table_name();


        table_info.add_row({name});
        table_info.format()
            .multi_byte_characters(true)
            // Font styling
            .font_style({tabulate::FontStyle::bold, tabulate::FontStyle::dark})
            .font_align(tabulate::FontAlign::center)
            .font_color(tabulate::Color::red)
            //.font_background_color(tabulate::Color::yellow)
            // Corners
            .corner_top_left("ᛰ")
            .corner_top_right("ᛯ")
            .corner_bottom_left("ᛮ")
            .corner_bottom_right("ᛸ")
            .corner_top_left_color(tabulate::Color::cyan)
            .corner_top_right_color(tabulate::Color::yellow)
            .corner_bottom_left_color(tabulate::Color::green)
            .corner_bottom_right_color(tabulate::Color::red)
            // Borders
            .border_top("ᛜ")
            .border_bottom("ᛜ")
            .border_left("ᚿ")
            .border_right("ᛆ")
            .border_left_color(tabulate::Color::yellow)
            .border_right_color(tabulate::Color::green)
            .border_top_color(tabulate::Color::cyan)
            .border_bottom_color(tabulate::Color::red);
        table_info[0].format().width(61);
        std::cout << table_info << "\n";

        tabulate::Table thead;
        thead.add_row({"NAME", "FIELD TYPE", "LENGTH", "NOT NULL", "DEFAULT", "OFFSET"});
        std::string arr[3] = {"INT", "FLOAT", "VARCHAR"};
        
        table_header header = tables[id]->get_table_header();

        for (int i = 0; i < header.col_num; i++) {
            thead.add_row({header.col_name[i], 
                arr[header.col_type[i]], 
                std::to_string(header.col_length[i]), 
                std::to_string(header.col_not_null[i]), 
                header.default_values[i],
                std::to_string(header.col_offset[i])
                });

        }   
        std::cout << "Flag NotNull " << header.flag_notnull << "\n";
        std::cout << "Flag Primary " << header.flag_primary << "\n";
        std::cout << "Flag Indexed " << header.flag_indexed << "\n";
        std::cout << "Flag Unique " << header.flag_unique << "\n";
        std::cout << "Flag Default " << header.flag_default << "\n";  
        std::cout << "Record Num "  << header.records_num << "\n"; 

        // center-align and color header cells
	    for (size_t i = 0; i < 5; ++i) {
            thead[0][i].format()
            .font_color(tabulate::Color::yellow)
            .font_align(tabulate::FontAlign::center)
            .font_style({tabulate::FontStyle::bold});
	    }
        std::cout << thead << "\n";
    }
}

table* database::get_table(const char* name) {
    assert(is_opened);
	int id = get_table_id(name);
	return id >= 0 ? tables[id] : nullptr;
}

table* database::get_table(int id) {
	assert(is_opened);
	if(id >= 0 && id < info.table_num)
		return tables[id];
	else return nullptr;
} 

int database::get_table_id(const char *name) {
	assert(is_opened);
	for(int i = 0; i < info.table_num; ++i) {
		if(strcmp(name, info.table_names[i]) == 0) {
			return i;
        }
	}
	return -1;
}

void database::drop_table(const char *table_name) {
    assert(is_opened);

    if (!get_table(table_name)) {
        eprint("Table Does Not Exists");
        return;
    }
    int row = get_table_id(table_name);
    table* t = get_table(row);
    std::cout << row << table_name << info.table_num << "\n";

    // switch table names
    memset(info.table_names[row], 0, 32 * sizeof(char));
    memcpy(info.table_names[row], info.table_names[info.table_num - 1], 32 * sizeof(char));
    memset(info.table_names[info.table_num - 1], 0, 32 * sizeof(char));
    // switch table
    tables[row] = tables[info.table_num - 1];
    tables[info.table_num - 1]  = nullptr;
    info.table_num--;
    t->drop();
    dprint("Dropped Table");
}