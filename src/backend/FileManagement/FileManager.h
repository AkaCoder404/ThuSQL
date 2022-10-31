#ifndef FILE_MANAGER
#define FILE_MANAGER
#include <string.h>
#include <stdio.h>
#include "../Utils/MyBitMap.h"
#include "../defs.h"

#include <fcntl.h>
#include <unistd.h>

class FileManager{
private:
    // FileTable* ftable;[]
   
    MyBitMap *fm;   // file management/map
    MyBitMap *tm;   // table management/map
    int _createFile(const char* name) {
        FILE* f = fopen(name, "a+"); // a+ reading at beg, writing at end, create if not created
        if (f == NULL) {
            printf("FAIL\n");
            return -1;
        }
        fclose(f);
        return 0;
    }
    int _openFile(const char* name, int fileID) {
        int f = open(name, O_RDWR); // https://linux.die.net/man/3/open
        if (f == -1) {
            return -1;
        }
        fd[fileID] = f;
        return 0;
    }

public: 
    int fd[MAX_FILE_NUM];
    FileManager();
    ~FileManager();
    int writePage(int fileID, int pageID, BufType buf, int off);
    int readPage(int fileID, int pageId, BufType buf, int off);
    int closeFile(int fileID);
    bool createFile(const char *filename);
    bool openFile(const char *name, int& fileID);
    int newType();
    void closeType(int typeID);
    void shutdown();
};
#endif