#include "table.h"
#include <cassert>
#include <iostream>

table::table() { 
    is_open = false; 
}
table::~table() { if(is_open) close(); }

void table::create(const table_header* header) {
    table_name = header->table_name;  
    this->header = *header;  

    std::string tdata_filename = table_name + ".tdata";
    pg = new PageFileSystem(tdata_filename.c_str());
    is_open = true;
}

void table::open(const char *name) {
    // read table header 
    table_name = name;
    std::string thead_filename = table_name + ".thead";
    FILE *fp = fopen(thead_filename.c_str(), "rb");
    fread(&header, sizeof(header), 1, fp);
    fclose(fp);

    // read data
    std::string tdata_filename = table_name + ".tdata";
    pg = new PageFileSystem(tdata_filename.c_str());
    is_open = true;
}

void table::drop() {
    assert(is_open);
    close();
    std::string thead = table_name + ".thead";
    std::string tdata = table_name + ".tdata";
    std::remove(tdata.c_str());
    std::remove(thead.c_str());
    // std::remove(tdata.c_str());
}

void table::close() {
    assert(is_open);
    // closing header
    std::string thead_filename = table_name + ".thead";
    FILE *fp = fopen(thead_filename.c_str(), "wb");
    fwrite(&header, sizeof(header), 1, fp);
    fclose(fp);

    // close data
    std::string tdata_filename = table_name + ".tdata";
    pg->close();
    is_open = false;
}

/* records */ 
void table::insert_record(char *buffer, int size) {
    tmp_record = new char[size];
    memcpy(tmp_record, buffer, size);
    pg->write(tmp_record, size);
}

void table::select_record(char *buffer, int size, int count) {
    pg->read(buffer, size, count);         // read from cache or file? temporarily directly read from file
    //for (int i = 0; i < count; i++) {       // read all records
    //    pg->read(buffer + size * i, size, i);
    //}
}

