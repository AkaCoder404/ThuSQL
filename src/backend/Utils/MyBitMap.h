#ifndef MY_BIT_MAP
#define MY_BIT_MAP

#include "../defs.h"

// 
#define LEAF_BIT 32
#define MAX_LEVEL 5
#define MAX_INNER_NUM 67
#define BIAS 5

class MyBitMap {
protected:
    static uint getMask(int k);
    uint* data;
    int size;
    int rootBit; 
    int rootLevel;
    int rootIndex;
    uint inner[MAX_INNER_NUM];
    uint innerMask;
    uint rootMask;
    // virtual 
    uint getLeafData(int index);
    void setLeafData(int index, uint v);
    int setLeafBit(int index, uint k);
    uint childWord(int start, int bitNum, int i, int j);
    void init();
    int _setBit(uint* start, int index, uint k);
    void updateInner(int level, int offset, int index, int levelCap, uint k);
    int _findLeftOne(int level, int offset, int pos, int prevLevelCap);
public:
    static int _hash(uint i);
    static void initConst();
    static int getIndex(uint k);
    static uint lowbit(uint k);
    static void getPos(int index, int& pos, int &bit);
    uint data0();
    void setBit(int index, uint k);
    int findLeftOne();
    MyBitMap(int cap, uint k);
    MyBitMap(int cap, uint* da);
    void reLoad(uint* da);

};


#endif 

