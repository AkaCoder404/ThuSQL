#ifndef DEFS
#define DEFS
#include "stdio.h"
/* database information */
#define MAX_DB_NAME_LEN 32
#define MAX_TABLE_NUM 32

/* page information */
#define PAGE_SIZE 8192        // 8KB
#define PAGE_INT_NUM 2048     // number of ints in a page
#define PAGE_SIZE_IDX 13      // log2(PAGE_SIZE)
#define MAX_FMT_INT_NUM 128   // max number of ints in a format


/* table information */
#define MAX_COL_NUM 32        // max number of columns in a table
#define MAX_TABLE_NAME_LEN 32
#define MAX_DEFAULT_LEN 32


/* cache information */
#define MAX_CACHE_CAP 60000             // cache capacity
#define CACHE_MOD 60000                 // cache hash mod
#define CACHE_HASH(x) ((x) % CACHE_MOD) // cache hash function

/* debug information */
#define IN_DEBUG 0
#define DEBUG_DELETE 0
#define DEBUG_ERASE 1
#define DEBUG_NEXT 1

/* */
#define PAGE_SIZE_IDX 13
#define MAX_FMT_INT_NUM 128
#define MAX_FILE_NUM 128
#define MAX_TYPE_NUM 256

/* column types */
#define FIELD_TYPE_INT 0
#define FIELD_TYPE_FLOAT 1
#define FIELD_TYPE_VCHAR 2


/* read from file */
#define RECORDS_PER_READ 20

/* display information */
#define SELECT_LIMIT 20


/* data types */
typedef unsigned int* BufType;      // buffer type 4, unsigned int 4 bytes
typedef unsigned int uint;          // unsigned int type, 4 bytes
typedef unsigned short ushort;      // unsigned short type
typedef unsigned char uchar;        // unsigned char type
typedef unsigned long long ull;     // unsigned long long type
typedef long long ll;               // long long type
typedef double db;                  // double type
// typedef int INT;                    // int type
typedef int(cf)(uchar*, uchar*);    // compare function type
// int current = 0;                    // current page number
// int tt = 0;                         // 



/* debugging */
void eprint(const char *mes); // error
void dprint(const char *mes); // done
void vprint(const char *mes); // visit
void tprint(const char *mes); // trace


int d_main();
#endif