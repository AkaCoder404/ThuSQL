#ifndef MY_LINK_LIST
#define MY_LINK_LIST

class MyLinkList {
private:
    struct ListNode {
        int next;
        int prev;
    };
    int cap;
    int LIST_NUM;
    ListNode* a;
    void link(int prev, int next);

public:
    void del(int index);                    // delete the element from the list at index
    void insert(int listID, int ele);       // insert the element at index ele to the list at index listID
    void insertFirst(int listID, int ele);  // insert the element at the head of the list at listID
    int getFirst(int listID);               // get the first element of the list at listID
    int next(int index);                    // get the next element of the element at index
    bool isHead(int index);                 // check if the element at index is the head of the list
    bool isAlone(int index);                // check if the element at index is the only element in the list
    MyLinkList(int c, int n);               // constructor

};

#endif
