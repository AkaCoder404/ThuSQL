#include "FindReplace.h"

FindReplace::FindReplace(int c) {
    CAP_ = c;
    list = new MyLinkList(c, 1);
    for (int i = 0; i < CAP_; ++ i) {
        list->insert(0, i);
    }
}

FindReplace::~FindReplace() {}

/**
 * @brief Reclaim the cache space of the index-th page in the cache page array
 * @param index the index of the page in the cached array
 */
void FindReplace::free(int index) {
    list->insertFirst(0, index);
}

/**
 * @brief Mark the index-th page in the cache page array as accessed
 * @param index the index of the page in the cached array
 */
void FindReplace::access(int index) {
    list->insert(0, index);
}

/**
 * @brief Return the index of the page to be replaced according to the replacement algorithm
 * @return int the index of the page to be replaced
 */
int FindReplace::find() {
    int index = list->getFirst(0);
    list->del(index);
    list->insert(0, index);
    return index;
}

