/*
 * Node.h
 *
 *  Created on: Nov 6, 2016
 *      Author: songjiguo
 */

#ifndef LIST_NODE_H_
#define LIST_NODE_H_

#include <iostream>
#include <random>

using namespace std;

/*
 *
 *    This is the list node object
 *
 * */

template<class T>
class ListNode {
public:
    ListNode();

    ListNode(const T &item, ListNode<T> *ptrnetxt = NULL);

    T data;

    // access the next node
    ListNode<T> *NextNode();

    void print_list();

    // modify methods
    void InsertAfter(ListNode<T> *p);

    ListNode<T> *DeleteAfter();

    ListNode<T> *GetNode(const T &item, ListNode<T> *nextptr = NULL);

//private:  // I do not like this to be private
    ListNode<T> *next;
};

template<class T>
ListNode<T>::ListNode() {
    next = nullptr;
}

template<class T>
ListNode<T>::ListNode(const T &item, ListNode<T> *ptrnext) {
    this->data = item;
    this->next = ptrnext;
}

template<class T>
ListNode<T> *ListNode<T>::NextNode() {
    return this->next;
}

template<class T>
void ListNode<T>::print_list() {
    ListNode<int> *tmp = this;
    while (tmp) {
        cout << tmp->data << ' ';
        tmp = tmp->NextNode();
    }
    cout << endl;
}

template<class T>
void ListNode<T>::InsertAfter(ListNode<T> *p) {
    p->next = this->next;
    this->next = p;
}

template<class T>
ListNode<T> *ListNode<T>::DeleteAfter() {
    ListNode<T> *tmp = next;
    if (next != NULL)
        next = next->next;
    return tmp;
}

template<class T>
ListNode<T> *GetNode(const T &item, ListNode<T> *nextptr = NULL) {
    ListNode<T> *newnode; // Local ptr for new node
    newnode = new ListNode<T>(item, nextptr);
    if (newnode == NULL) {
        cerr << "Memory allocation failed." << endl;
        exit(1);
    }
    return newnode;
}

/*
 *
 *    This is the list object
 *
 * */

template<class T>
class List {
public:
    List();

    List(unsigned int list_sz, T __lower, T __upper) :
            length(list_sz), head(nullptr), lower(__lower), upper(__upper) {
        head = GenerateList();
    }

    ~List() { }

    ListNode<T> *head;
private:
    T lower;
    T upper;

    unsigned int length;

    ListNode<T> *GenerateList();

    ListNode<T> *Generate_List_Helper(ListNode<T> *head, int listLen, T low,
                                      T high);

    T getRandom();
};


template<class T>
List<T>::List() :
        length(0), head(nullptr), lower(0), upper(0) {
};

template<class T>
T List<T>::getRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution <T> dist(this->lower, this->upper);
    return dist(gen);
}

template<class T>
ListNode<T> *List<T>::Generate_List_Helper(ListNode<T> *head, int listLen,
                                           T lower, T upper) {
    if (head == nullptr || listLen == 0)
        return head;

    T item = getRandom();

    head->next = GetNode(item);
    --listLen;
    return Generate_List_Helper(head->next, listLen, lower, upper);
}

template<class T>
ListNode<T> *List<T>::GenerateList() {
    T item = getRandom();

    ListNode<T> *head = GetNode(item);
    Generate_List_Helper(head, this->length - 1, this->lower, this->upper);
    return head;
}

#endif /* LIST_NODE_H_ */
