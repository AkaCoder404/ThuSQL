#ifndef DBMS
#define DBMS

#include "database.h"
#include "table.h"
#include "../../backend/defs.h"

// 
#include "../parser/SQLBaseVisitor.h"


class dbms {
private:
    FILE *output_file;
    database *curr_db;
public:
    dbms();
    ~dbms();

    /* load/dump to file */
    void dump_data(const char *file_name, const char *table_name); // TODO
    void load_data(const char *file_name, const char *table_name); // TODO

    /* database */
    void create_database(const char *database_name);
    void open_database(const char *database_name);
    void show_database(const char *database_name);
    void drop_database(const char *database_name);
    void close_database();
    void show_databases(); 

    /* table */
    void create_table(table_header *header);
    void show_table(const char *table_name);
    void drop_table(const char *table_name);

    /* TODO index */ 
    void create_index();
    void drop_index();

    /* TODO records/rows */
    void insert_rows(SQLParser::Insert_into_tableContext *ctx);
    void delete_rows();
    void select_rows(std::string cols, std::string where, const char *table_name);
    void update_rows();

    static dbms* get_instance() {
        static dbms ms;
        return &ms;
    }
};

#endif