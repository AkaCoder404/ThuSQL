#include "FileTable.h"



FileTable::FileTable(int fn, int tn) {
    load();
    ft = new MyBitMap(tn, 1);
    ff = new MyBitMap(fn, 1);
    idToName = new std::string[fn];
    isOpen.clear();
}
FileTable::~FileTable() {
    save();
}
void FileTable::load() {
    std::ifstream fin("filenames");
    fin >> n;
    for (int i = 0; i < n; ++i) {
        std::string s, a;
        fin >> s;
        isExist.insert(s);
        fname.push_back(s);
        fin >> a;
        format.push_back(a);
    }
    fin.close();
}
void FileTable::save() {
	std::ofstream fout("filenames");
    fout << fname.size() << std::endl;
    for (uint i = 0; i < fname.size(); ++ i) {
        fout << fname[i] << std::endl;
        fout << format[i] << std::endl;
    }
    fout.close();
}
int FileTable::newTypeID() {
    int k = ft->findLeftOne();
    ft->setBit(k, 0);
    return k;

}
int FileTable::newFileID(const std::string& name) {
    int k = ff->findLeftOne();
    ff->setBit(k, 0);
    nameToID[name] = k;
    isOpen.insert(name);
    idToName[k] = name;
    return k;
}
bool FileTable::ifexist(const std::string& name) {
    return (isExist.find(name) != isExist.end());
}
void FileTable::addFile(const std::string& name, const std::string& fm) {
 	isExist.insert(name);
    fname.push_back(name);
    format.push_back(fm);
}
int FileTable::getFileID(const std::string& name) {
    if (isOpen.find(name) == isOpen.end()) {
        return -1;
    }
    return nameToID[name];
}
void FileTable::freeTypeID(int typeID) {
    ft->setBit(typeID, 1);
}
void FileTable::freeFileID(int fileID) {
    ff->setBit(fileID, 1);
    std::string name = idToName[fileID];
    isOpen.erase(name);
}
std::string FileTable::getFormat(std::string name) {
    for (uint i = 0; i < fname.size(); ++ i) {
        if (name == fname[i]) {
            return format[i];
        }
    }
    return "-";
}