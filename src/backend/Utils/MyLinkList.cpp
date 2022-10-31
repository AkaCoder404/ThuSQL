#include "MyLinkList.h"

MyLinkList::MyLinkList(int c, int n) {
    cap = c;
    LIST_NUM = n;
    a = new ListNode[n + c];
    for (int i = 0; i < cap + LIST_NUM; ++ i) {
        a[i].next = i;
        a[i].prev = i;
    }
}

void MyLinkList::link(int prev, int next) {
    a[prev].next = next;
    a[next].prev = prev;
}

void MyLinkList::del(int index) {
    if (a[index].prev == index) {
        return;
    }
    link(a[index].prev, a[index].next);
    a[index].prev = index;
    a[index].next = index;
}

void MyLinkList::insert(int listID, int ele) {
    del(ele);
    int node = listID + cap;
    int prev = a[node].prev;
    link(prev, ele);
    link(ele, node);
}

void MyLinkList::insertFirst(int listID, int ele) {
    del(ele);
    int node = listID + cap;
    int next = a[node].next;
    link(node, ele);
    link(ele, next);
}

int MyLinkList::getFirst(int listID) {
    return a[listID + cap].next;
}

int MyLinkList::next(int index) {
    return a[index].next;
}

bool MyLinkList::isHead(int index) {
    if (index < cap) {
        return false;
    } else {
        return true;
    }
}

bool MyLinkList::isAlone(int index) {
    return (a[index].next == index);
}