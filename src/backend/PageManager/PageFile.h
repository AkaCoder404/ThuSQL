// page file system
#ifndef PAGE_FILE_SYSTEM
#define PAGE_FILE_SYSTEM


#include "../BuffManagement/BufPageManager.h"
#include "../defs.h"
#include <string>

// manage file id
class FID {
private:
    int free_num;
    int free[MAX_FILE_NUM];
    char used[MAX_FILE_NUM + 1];
public:
};

struct PageHeader {
    int page_number;
    int first_free_page;
};
// interface between frontend and bakend
class PageFileSystem {
private:
    int fileId;
    int pageId;
    std::string currpath;
    
public:
    PageFileSystem();
    PageFileSystem(const char* filename);
    ~PageFileSystem();

    // interface
    bool open(const char* filename);                    // TODO: open file to write pages to
    bool close();                                       // TODO: close file, and write everything to it
    bool write(const char* buffer, int size);           // TODO: write to cache
    bool flush();                                       // TODO: flush cache, write to file
    bool new_page(int curr_index);                                    // TODO: allocate new page
    bool free_page();                                   //
    bool read(int start, char *buffer, int size, int pageId);
    bool read_for_write();
    bool mark_dirty();

    // 
    PageHeader page_headers[MAX_FILE_NUM];  // contains details about each page

    int bytes_remaining = 8192;
    int empty_position = 0;
    bool uninitialized = true;
    BufType b; 



    // our backend
    // MyBitMap::initConst();   //新加的初始化
	FileManager* fm; // = new FileManager();
	BufPageManager* bpm ; // = new BufPageManager(fm);

    // static PageFileSystem* get_instance() {
    //     static PageFileSystem pf;
    //     return &pf;
    // }
};
#endif