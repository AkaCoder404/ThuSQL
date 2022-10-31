/*
 * testfilesystem.cpp
 *
 *  Created on: 2015年10月6日
 *      Author: lql
 *          QQ: 896849432
 * 各位同学十分抱歉，之前给的样例程序不支持同时打开多个文件
 * 是因为初始化没有做，现在的程序加上了初始化（main函数中的第一行）
 * 已经可以支持多个文件的维护
 *
 * 但是还是建议大家只维护一个文件，因为首先没有必要，我们可以把数据库中
 * 的索引和数据都放在同一个文件中，当我们开启一个数据库时，就关掉上一个
 * 其次，多个文件就要对应多个fileID，在BufPageManager中是利用一个hash函数
 * 将(fileID,pageID)映射为一个整数，但由于我设计的hash函数过于简单，就是fileID和
 * pageID的和，所以不同文件的页很有可能映射为同一个数，增加了hash的碰撞率，影响效率
 * 
 * 还有非常重要的一点，BufType b = bpm->allocPage(...)
 * 在利用上述allocPage函数或者getPage函数获得指向申请缓存的指针后，
 * 不要自行进行类似的delete[] b操作，内存的申请和释放都在BufPageManager中做好
 * 如果自行进行类似free(b)或者delete[] b的操作，可能会导致严重错误
 */ 

#include "BuffManagement/BufPageManager.h"
#include "FileManagement/FileManager.h"
#include "defs.h"
#include <iostream>
using namespace std;

struct Person {
	int age;
	char name[20];
};

struct TableHeader {
	uint8_t col_num; // 1 byte unsigned int
	uint8_t main_index;

	int records_num, primary_key_num, check_contraints_num, foreign_key_num;

	char table_name[MAX_TABLE_NAME_LEN];
	char col_names[MAX_COL_NUM][MAX_TABLE_NAME_LEN];
	uint8_t col_type[MAX_COL_NUM]; 
};

void test1(FileManager* fm, BufPageManager *bpm) {
	int fileID, pageID, index;
	pageID = 0;
	fm->createFile("Persons2.tdata");
	fm->openFile("Persons2.tdata", fileID);
	BufType b = bpm->allocPage(fileID, pageID, index, false);
	
	printf("fileID : %d | pageID : %d | index : %d \n", fileID, pageID, index);
	// create record
	struct Person *p1 = new Person();
	strcpy(p1->name, "Happy");
	p1->age = 0;


	// write p1 to file
	memcpy(b, p1, sizeof(Person));
	fm->writePage(fileID, pageID, b, 0);
	bpm->markDirty(index);
	
	// create another record
	struct Person *p2 = new Person();
	strcpy(p2->name, "If");
	p2->age = 1;
	// allocate space and write
	b = bpm->allocPage(fileID, 1, index, false);
	
	b = b + 1 * PAGE_SIZE;
	memcpy(b, p2, sizeof(Person));
	fm->writePage(fileID, 1, b, 0);
	bpm->markDirty(index);
	printf("fileID : %d | pageID : %d | index : %d \n", fileID, pageID, index);

	struct Person *p3 = new Person();
	fm->readPage(fileID, pageID, (BufType)p3, 0);
	printf("%d, %s\n", p3->age, p3->name);

	fm->readPage(fileID, pageID, b + 1 * PAGE_SIZE, 0);
	memcpy(p3, b, sizeof(Person));
	printf("%d, %s\n", p3->age, p3->name);

	// close file
	fm->closeFile(fileID);

	
	


	// int fileID2, index2, pageID2;
	// pageID2 = 0;
	// fm->createFile("Class.tdata");
	// fm->openFile("Class.tdata", fileID2);
	// BufType b2 = bpm->allocPage(fileID2, pageID2, index2, false);
	// printf("fileID2 : %d\nindex2 : %d\npageID2 : %d\n", fileID2, index2, pageID2);

	// for (int i = 0; i < 100; i++ ) {
	// 	printf("%d ", b[i]);
	// 

}
// save one item per page
void test2(FileManager* fm, BufPageManager *bpm) {
	int fileID, pageID, index;
	
	fm->createFile("Person2.tdata");
	fm->openFile("Person2.tdata", fileID);
	printf("\n%lu\n", sizeof(Person));
	

	char s[30] = "HelloFromTheOutside";
	BufType b = bpm->allocPage(fileID, 0, index, false);
	for (int i = 0; i < 10; i++) {
		struct Person *p = new Person();
		strcpy(p->name, s);
		p->age = i + 1;

		pageID = i;
		// BufType b = bpm->allocPage(fileID, i, index, false);
		// printf("Buftype %u ", b); // step size of 8192
		// b = b + i * sizeof(Person);
		memcpy(b + i * sizeof(Person), p, sizeof(Person));
		bpm->markDirty(index);

		printf("fileID : %d | pageID : %d | index : %d \n", fileID, 0, index);
	}
	// bpm->writeBack(index);
	// fm->closeFile(fileID);
	// writeback and release all from cache
	for (int i = 0; i < 12; i++) {
		bpm->writeBack(i);
	}

	// read
	b = bpm->getPage(fileID, 0, index);
	// fm->closeFile(fileID);
	for (int i = 0; i <10; i++) {
		struct Person *p = new Person();
		// b = b + i * sizeof(Person);
		memcpy(p, b + i *sizeof(Person), sizeof(Person));
		printf("index: %d | %d, %s\n", index, p->age, p->name);
	}
}

int d_main() {
    printf("Hello World!\n");
	MyBitMap::initConst();   //新加的初始化
	FileManager* fm = new FileManager();
	BufPageManager* bpm = new BufPageManager(fm);

	// test reading/writing
	// test1(fm, bpm); // doesn't close, fileID increases by one, but you should close
	test2(fm, bpm);
	test2(fm, bpm);

	return 0;
	fm->createFile("testfile.txt"); //新建文件
	fm->createFile("testfile2.txt");
	int fileID, f2;
	fm->openFile("testfile.txt", fileID); //打开文件，fileID是返回的文件id
    fm->openFile("testfile2.txt", f2);
	for (int pageID = 0; pageID < 1000; ++ pageID) {
		int index;
		//为pageID获取一个缓存页
		BufType b = bpm->allocPage(fileID, pageID, index, false);
		//注意，在allocPage或者getPage后，千万不要进行delete[] b这样的操作
		//内存的分配和管理都在BufPageManager中做好，不需要关心，如果自行释放会导致问题
		b[0] = pageID; //对缓存页进行写操作
		b[1] = fileID;
		bpm->markDirty(index); //标记脏页
		//在重新调用allocPage获取另一个页的数据时并没有将原先b指向的内存释放掉
		//因为内存管理都在BufPageManager中做好了
		b = bpm->allocPage(f2, pageID, index, false);
		b[0] = pageID;
		b[1] = f2;
		bpm->markDirty(index);
	}
	for (int pageID = 0; pageID < 1000; ++ pageID) {
		int index;
		//为pageID获取一个缓存页
		BufType b = bpm->getPage(fileID, pageID, index);
		//注意，在allocPage或者getPage后，千万不要进行delete[] b这样的操作
		//内存的分配和管理都在BufPageManager中做好，不需要关心，如果自行释放会导致问题
		cout << b[0] << ":" << b[1] << endl; 		//读取缓存页中第一个整数
		bpm->access(index); //标记访问
		b = bpm->getPage(f2, pageID, index);
		cout << b[0] << ":" << b[1] << endl;
		bpm->access(index);
	}
	//程序结束前可以调用BufPageManager的某个函数将缓存中的内容写回
	//具体的函数大家可以看看ppt或者程序的注释
	bpm->writeBack(102);
	return 0;
}
