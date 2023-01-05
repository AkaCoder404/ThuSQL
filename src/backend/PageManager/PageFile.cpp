#include "PageFile.h"
#include <iostream>
#include <vector>

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
    // set up file header
    return true;
}


bool PageFileSystem::close() {
    bpm->close();
    return true;
}

//page size = 8192 bytes
BufType b;
//page system data
int available_index = 0; 
int bytes_remaining = 8192;
bool page_available = false;

bool PageFileSystem::write(const char* buffer, int size) {
    // TODO: multiple records per page
    int curr_index; // index of record being written
    if(bytes_remaining < size || page_available == false){ //if the page cannot fit another row make new page
        new_page(curr_index);
    }
    //update available page metadata and write to page
    bytes_remaining -= size; 
    available_index += size;
    memcpy(b + available_index*8, buffer, size);
    return true;
}

bool PageFileSystem::flush(const char* buffer, int size, int curr_index) { //TODO: store whatever is in the buffer into page
    //check if can fit buffer into flush then store, if not then make new page
    if(bytes_remaining < size || page_available == false){
        new_page(curr_index);
    }
    //update local page system info and write to page
    bytes_remaining -= size; 
    available_index += size;
    memcpy(b + available_index*8, buffer, size);
    return true;
}

bool PageFileSystem::new_page(int curr_index) {//make fresh page and set local page system info
    b = bpm->allocPage(fileId, pageId++, curr_index, false);
    available_index = 0;
    bytes_remaining = 8192;
    bpm->markDirty(curr_index);
    page_available = true;
    return true;
}

bool PageFileSystem::free_page() {
    return true;
}

bool PageFileSystem::read(char *buffer, int size, int pageId) {
    std::cout << "Page Id: " << pageId << " FileId: " << fileId << "\n";
    int curr_index;
    BufType b = bpm->getPage(fileId, pageId, curr_index);
    memcpy(buffer, b, size);                         // cpy out
    bpm->access(curr_index);                         // update cache
    return true;
}

bool PageFileSystem::mark_dirty() {
    return true;
}