#ifndef FILE_TABLE
#define FILE_TABLE
#include <string>
#include <map>
#include <vector>
#include <set>
#include <fstream>

#include "../Utils/MyBitMap.h"


class FileTable {
private:
    std::multiset<std::string> isExist;
    std::multiset<std::string> isOpen;
    std::vector<std::string> fname;
    std::vector<std::string> format;
    std::map<std::string, int> nameToID;
    std::string* idToName;
    MyBitMap* ft, *ff;
    int n;
public:
    FileTable(int fn, int tn);
    ~FileTable();
    void load(); 
    void save();
    int newTypeID();
    int newFileID(const std::string& name);
    bool ifexist(const std::string& name);
    void addFile(const std::string& name, const std::string& fm);
    int getFileID(const std::string& name);
    void freeTypeID(int typeID);
    void freeFileID(int fileID);
    std::string getFormat(std::string name);
};
#endif