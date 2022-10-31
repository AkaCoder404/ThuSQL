#ifndef MY_HASH_MAP
#define MY_HASH_MAP
#include "../defs.h"
#include "MyLinkList.h"

// hash table key
struct DataNode {
    int key1;
    int key2;
};

// Hash table with two keys
// The value of the hash table is a natural number, 
// and in the cache manager, 
// the value of the hash table is used to represent the index of the cache page array

class MyHashMap {
private: 
    static const int A = 1;
    static const int B = 1;
    int CAP_, MOD_;                             // hash table capacity, hash table mod
    MyLinkList* list;
    DataNode* a;
    // hash function
    int hash(int k1, int k2) {
        return (k1 * A + k2 * B) % MOD_;
    }
public:
    MyHashMap(int c, int m);                    //  constructor
    ~MyHashMap();                               //  deconstructor
    int findIndex(int k1, int k2);              //  given k1 and k2, find the corresponding hash value
    void replace(int index, int k1, int k2);     //  change the keys of the speciified value as k1, k2
    void remove(int index);                      //  delete the specified value in the hash table
    void getKeys(int index, int& k1, int& k2);   //  store k1 and k2 at specified value 

};

#endif