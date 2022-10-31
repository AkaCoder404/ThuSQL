#ifndef BUF_PAGE_MANAGER
#define BUF_PAGE_MANAGER

#include "../FileManagement/FileManager.h"
#include "../defs.h"
#include "../Utils/MyHashMap.h"
#include "../Utils/MyBitMap.h"
#include "../Utils/MyLinkList.h"
#include "FindReplace.h"



/*
 * BufPageManager
 * Implement a cache management system
 */

struct BufPageManager {
public:
    int last;
    FileManager* fileManager;
    MyHashMap* hash;
    FindReplace* replace;
    // When page is written to cache, set corresponding dirty marker to true
    bool* dirty;                      
    // Cache page array
    BufType *addr;
    BufPageManager(FileManager* fm);
    ~BufPageManager();
    BufType allocMem();
    BufType fetchPage(int typeID, int pageID, int& index);
    BufType allocPage(int fileID, int PageID, int& index, bool ifRead = false);
    BufType getPage(int fileID, int pageID, int& index);
    void access(int index);
    void markDirty(int index);
    void release(int index);
    void writeBack(int index);
    void close();
    void getKey(int index, int& fileID, int& pageID);
    
};

#endif