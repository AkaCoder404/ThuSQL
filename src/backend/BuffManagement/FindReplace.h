#ifndef FIND_REPLACE
#define FIND_REPLACE

#include "../Utils/MyLinkList.h"
#include "../Utils/MyHashMap.h"
#include "../defs.h"

// provides a interface for replacement algorithm, LRU is implemented here
class FindReplace{
private:
    MyLinkList* list;
    int CAP_;

public:
    FindReplace(int c);
    ~FindReplace();

    void free(int index);
    void access(int index);
    int find();
};



#endif