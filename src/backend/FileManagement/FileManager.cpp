#include "FileManager.h"
#include "../defs.h"

FileManager::FileManager() {
    fm = new MyBitMap(MAX_FILE_NUM, 1);
    tm = new MyBitMap(MAX_TYPE_NUM, 1);
}
FileManager::~FileManager() {
    this->shutdown();
}

/**
* @name name writePage
* @param fileID: File ID, used to distinguish the file that has been opened
* @param pageID: page number of file
* @param buf: Caches for storing information (4 -byte unsigned integer array)
* @param off: offset
* @brief: Write the 2048 four -byte integer (8KB information) starting BUF+OFF in the file page specified by FileId and Pageid
* @return: Successful operation Return 0
*/

int FileManager::writePage(int fileID, int pageID, BufType buf, int off) {
    int f = fd[fileID];
    off_t offset = pageID;
    offset = (offset << PAGE_SIZE_IDX); // offset = page_number * 8192
    off_t error = lseek(f, offset, SEEK_SET);  // seek to position (file, offset)
    if (error != offset) {
        return -1;
    }   
    BufType b = buf + off;                      
    error = write(f, (void*) b, PAGE_SIZE);    // wrike to position (file, offset), with length buf
    return 0;
}

/**
* @name name ReadPage
* @param fileID: File ID, used to distinguish the file that has been opened
* @param pageID: file page number
* @param buf: Caches for storing information (4 -byte unsigned integer array)
* @param off: offset
* @brief: Read the 2048 four -byte integer (8KB) in the file page specified by FileId and Pageid into the memory starting by BUF+OFF
* @return: Successful operation Return 0
*/
int FileManager::readPage(int fileID, int pageID, BufType buf, int off) {
    //int f = fd[fID[type]];
    int f = fd[fileID];
    off_t offset = pageID;
    offset = (offset << PAGE_SIZE_IDX);
    off_t error = lseek(f, offset, SEEK_SET);
    if (error != offset) {
        return -1;
    }
    BufType b = buf + off;
    error = read(f, (void*) b, PAGE_SIZE);
    return 0;
}

/**
* @name name Createfile
* @param name: file name
* @brief: Create the file name specified by name
* @return: successful operation, return True
*/
bool FileManager::createFile(const char *name) {
    _createFile(name);
    return true;
}

/**
* @name name OpenFile
* @param name: file name
* @param fileID: When the function returns, if the file is successfully opened, then a ID is allocated to the file and recorded in the FileID
* @brief Open the file
* @return: If you open it successfully, store the ID assigned to the file in FileID and return to TRUE, otherwise return False
*/
bool FileManager::openFile(const char *name, int& fileID) {
    fileID = fm->findLeftOne();
    fm->setBit(fileID, 0);
    _openFile(name, fileID);
    return true;
}

/**
* @name name closefile
* @param FileID: For the differential file that has been opened
* @brief Close the file
* @return successful operation, return 0
*/
int FileManager::closeFile(int fileID) {
    fm->setBit(fileID, 1);
    int f = fd[fileID];
    close(f);
    return 0;
}
int FileManager::newType() {
    int t = tm->findLeftOne();
    tm->setBit(t, 0);
    return t;
}

void FileManager::closeType(int typeID) {
    tm->setBit(typeID, 1);
}

void FileManager::shutdown() {
    delete tm;
    delete fm;
}