#include "MyHashMap.h"

MyHashMap::MyHashMap(int c, int m) {
    CAP_ = c;
    MOD_ = m;
    a = new DataNode[c];
    for (int i = 0; i < CAP_; ++ i) {
        a[i].key1 = -1;
        a[i].key2 = -1;
    }
    list = new MyLinkList(CAP_, MOD_);
}

int MyHashMap::findIndex(int k1, int k2) {
    int h = hash(k1, k2);
    int p = list->getFirst(h);
    while(!list->isHead(p)) {
        if (a[p].key1 == k1 && a[p].key2 == k2) {
            return p;
        }
        p = list->next(p);
    }
    return -1;
}

/**
* @name Replace
* @param index: specified Value
* @param K1: The first key specified
* @param k2: The specified second key
* @Brief: In the Hash table, the two key corresponding to Value is set to K1 and K2
*/
void MyHashMap::replace(int index, int k1, int k2) {
    int h = hash(k1, k2);
    list->insertFirst(h, index);
    a[index].key1 = k1;
    a[index].key2 = k2;
}

/**
* @Name Remove
* @param index: specified Value
* @Brief: In the HASH table, delete the specified value
*/
void MyHashMap::remove(int index) {
    list->del(index);
    a[index].key1 = -1;
    a[index].key2 = -1;
}

/**
* @Name Getkeys
* @param index: specified Value
* @param K1: Storage the first key corresponding to the specified value
* @param K2: Storage the second key corresponding to the specified value
*/void MyHashMap::getKeys(int index, int& k1, int& k2) {
    k1 = a[index].key1;
    k2 = a[index].key2;
}