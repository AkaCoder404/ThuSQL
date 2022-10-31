#ifndef TABLE
#define TABLE

#include "../../backend/PageManager/PageFile.h"   // interacts with backend
#include "../../backend/defs.h"
#include <stdint.h>
#include <string>

struct table_header {
    char table_name[MAX_TABLE_NAME_LEN];        // table name
    uint8_t col_num;                            // number of columns
    
    int records_num;                            // total number of records
    int primary_key_num;
    int check_constaint_num;
    int foreign_key_num;
	uint32_t flag_notnull;                      // flag which items are not null, 32 bits, one for each col
    uint32_t flag_primary;                      // flag primary col
    uint32_t flag_indexed;                      // flag which items are indexes
    uint32_t flag_unique;                       // flag which items must be unique
    uint32_t flag_default;                      // flag which items have default values

    int64_t auto_increment_row_id;              // track row_id
    

    int col_length[MAX_COL_NUM];
    int col_offset[MAX_COL_NUM];                // offset from start
    int col_not_null[MAX_COL_NUM];
    uint8_t col_type[MAX_COL_NUM];
    
    char col_name[MAX_COL_NUM][MAX_TABLE_NAME_LEN];
    char default_values[MAX_COL_NUM][MAX_DEFAULT_LEN];
};

class table {
    bool is_open;
    std::string table_name;
    table_header header;

    int tmp_record_size;                            // tmp_record buffer size
	char *tmp_record;                               // tmp_record (buffer to save to page file)      
private:
public:
    table();
    ~table();

    /* basic table manipulation */
    void create(const table_header *header);
    void open(const char *table_name);
    void drop();
    void close();  
    std::string get_table_name() { return table_name; }
    table_header get_table_header() { return header; }
    table_header* get_table_header_p() { return &header; }
    void increase_record_count() { header.records_num++; }

    /* page file system */
    PageFileSystem *pg;

    /* records */   
    void insert_record(char* buffer, int size);            // write to page file/cache
    void select_record(char* buffer, int size, int count);

    /* cache */ 

    /* index */ 
    bool has_index(const char *col_name);
    bool has_index(int col_index);
    void create_index(const char *col_name);
};



#endif 
