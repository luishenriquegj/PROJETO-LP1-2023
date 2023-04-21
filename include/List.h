#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <typename T> 

class List {    
    public:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* data;
        List();
        void print();
        void add(T data);
        void setTail(Node<T>* tail);
        void setHead(Node<T>* head);
        

};
        #include"list.inl"


#endif