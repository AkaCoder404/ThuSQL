#include "PageFile.h"
#include <iostream>
#include <filesystem>

PageFileSystem::PageFileSystem() {}

PageFileSystem::PageFileSystem(const char *filename) {
    MyBitMap::initConst();
    fm = new FileManager();
    bpm = new BufPageManager(fm);
    pageId = 0;
    open(filename);
}
PageFileSystem::~PageFileSystem() {}

bool PageFileSystem::open(const char* filename) {
    // allocate file id and open file
    fm->createFile(filename);
    fm->openFile(filename, fileId);
    currpath = filename;
    // set up file header
    return true;
}


bool PageFileSystem::close() {
    bpm->close();
    return true;
}


/*
bool PageFileSystem::write(const char* buffer, int size) {
    // TODO: multiple records per page
    int curr_index; // index of record being written
    if(bytes_remaining < size || uninitialized == true){
        new_page(curr_index);
        uninitialized = false;
    }
    memcpy(b + empty_position, buffer, size);
    empty_position +=size;
    bytes_remaining-=size;
    return true;
} 
*/
bool PageFileSystem::write(const char* buffer, int size) {
    // TODO: multiple records per page
    int curr_index; // index of record being written
    int eof = std::filesystem::file_size(currpath);
    lseek(fm->fd[fileId], eof, SEEK_SET);
    ::write(fm->fd[fileId], buffer, size);
    return true;
} 

bool PageFileSystem::flush() {
    return true;
}

bool PageFileSystem::new_page(int curr_index) {
    printf("alloc new page\n");
    b = bpm->allocPage(fileId, pageId++, curr_index, false);
    bpm->markDirty(curr_index);
    return true;
}

bool PageFileSystem::free_page() {

    return true;
}

/*
bool PageFileSystem::read(char *buffer, int size, int pageId) {
    std::cout << "Page Id: " << pageId << " FileId: " << fileId << "\n";
    int curr_index;
    BufType ba = bpm->getPage(fileId, pageId, curr_index);
    memcpy(buffer, ba, size);                         // cpy out
    memcpy(buffer + size, ba + size, size);   //


    bpm->access(curr_index);                          // update cache
    return true;
}
*/
bool PageFileSystem::read(char *buffer, int size, int count) {
    std::cout << " FileId: " << fileId << "\n";
    int curr_index;
    lseek(fm->fd[fileId], 0, SEEK_SET);
    ::read(fm->fd[fileId], buffer, size*count);
    return true;
}



bool PageFileSystem::mark_dirty() {
    return true;
}