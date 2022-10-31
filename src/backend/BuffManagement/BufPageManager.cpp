#include "BufPageManager.h"

BufPageManager::BufPageManager(FileManager* fm) {
    int c = MAX_CACHE_CAP;           
    int m = CACHE_MOD;
    last = -1; 
    fileManager = fm;
    dirty = new bool[MAX_CACHE_CAP];
    addr = new BufType[MAX_CACHE_CAP];
    hash = new MyHashMap(c, m);
    replace = new FindReplace(c);
    for (int i = 0; i < MAX_CACHE_CAP; ++ i) {
        dirty[i] = false;
        addr[i] = NULL;
    }
}

BufType BufPageManager::allocMem() {
    return new unsigned int[(PAGE_SIZE >> 2)]; // 2048 array of 4-byte integers (unsigned)
    // 2048 is also maximum length of one record (sum of columns)
}

/**
 * @name 
 * @brief 
 * @param typeID 
 * @param pageID 
 * @param index 
 * @return BufType 
 */
BufType BufPageManager::fetchPage(int typeID, int pageID, int &index) {
    BufType b;
    index = replace->find();                        // get next avail cache space
    b = addr[index];                                // check if in cache
    if (b == NULL) {                                // if null, allocate memory
        b = allocMem();                             // allocate 2048 bytes
        addr[index] = b;                            // set new address to cache
    }
    else {                                           // exists in cache
        if (dirty[index]) {                          // if dirty, then 
            int k1, k2;
            hash->getKeys(index, k1, k2);
            fileManager->writePage(k1, k2, b, 0);
            dirty[index] = false;
        }
    }
    hash->replace(index, typeID, pageID);
    return b;
}

/**
* @name allocpage
* @param FileID: File ID, Indicates the file being used.
* @param PageID: file page number, indicates the nth page in the file specified by FileID.
* @param Index: When the function returns, it is used to record the index in the cache page array
* @param ifRead: Do you want to read the content in the file page into the cache
* @return The first address of the cache page
* @brief Function: Get a pages in the cache cache pages in the buffer pages in the buffer page array in the file in the file.Pages
* @note Before calling the function allocpage, the caller must be convinced that the file page specified by FileId, Pageid does not have a cache. If the specified file page is not in the cache, then you do not need to find in the Hash table. Call the algorithm directly to the algorithm algorithm.,save time
*/
BufType BufPageManager::allocPage(int fileID, int pageID, int& index, bool ifRead) {
    BufType b = fetchPage(fileID, pageID, index);
    if (ifRead) {
        fileManager->readPage(fileID, pageID, b, 0);
    }
    return b;
}


/**
 * @name
 * @brief Find the corresponding cached page in the cache page array for a page in a file
 * @param fileID 
 * @param ID 
 * @param index 
 * @return BufType 
 */
BufType BufPageManager::getPage(int fileID, int pageID, int& index) {
    index = hash->findIndex(fileID, pageID);                // find corresponding cache index for given fileID, pageID
    if (index != -1) {
        tprint("Found in Cache");
        access(index);
        return addr[index];
    }
    else {
        tprint("Not in Cache");
        BufType b = fetchPage(fileID, pageID, index);
        fileManager->readPage(fileID, pageID, b, 0);
        return b;
    }
}

/**
 * @name
 * @brief The cached page is accessed, and the replacement algorithm is updated
 * @param index 
 */
void BufPageManager::access(int index) {
    if (index == last) {
        return;
    }
    replace->access(index);
    last = index;
}

/**
 * @name
 * @brief Mark the cached page as dirty
 * @param index 
 */
void BufPageManager::markDirty(int index) {
    dirty[index] = true;
    access(index);
}

/**
 * @name 
 * @brief Release the cached page
 * @param index 
 */
void BufPageManager::release(int index) {
    dirty[index] = false;
    replace->free(index);
    hash->remove(index);
}

/**
 * @name writeBack
 * @brief Write the cached page back to the file
 * @param index 
 */
void BufPageManager::writeBack(int index) {
    if (dirty[index]) {
        tprint("Write Back Cache");
        int f, p;   // file, page
        hash->getKeys(index, f, p);
        fileManager->writePage(f, p, addr[index], 0);
        dirty[index] = false;
    }
    replace->free(index);
    hash->remove(index);
}

/**
 * @name close
 * @brief Close the file
 */
void BufPageManager::close() {
    for (int i = 0; i < MAX_CACHE_CAP; ++i){
        writeBack(i);
    }
 }

void BufPageManager::getKey(int index, int& fileID, int& pageID) {
    hash->getKeys(index, fileID, pageID);
}