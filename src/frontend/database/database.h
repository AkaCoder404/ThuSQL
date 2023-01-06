#ifndef DATABASE
#define DATABASE

#include "table.h"
#include "../../backend/defs.h"

class database {
    struct database_info {
        int table_num;
        char database_name[MAX_DB_NAME_LEN];                 // 32
        char table_names[MAX_TABLE_NUM][MAX_TABLE_NAME_LEN]; // 32 x 32
    } info;

    bool is_opened;
    table *tables[MAX_TABLE_NUM];                            // 32
   
private:
public:
    database();
    ~database();
    /* database */
    void create(const char *name);          // create database
    bool open(const char *name);            // open database
    void drop();                            // delete database
    void close();                           // close (current) database
    void show_database_info(bool show_tables);

    /* table */ 
    void create_table(table_header *header);
    void show_table(const char *name);
    void drop_table(const char *name);
    table* get_table(const char *name);
    table* get_table(int id);
    int get_table_id(const char *name);

    /* records */
};



#endif