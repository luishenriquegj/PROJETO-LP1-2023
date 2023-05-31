#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include "Playlist.h"
#include <string>

template <typename T> 

class List {    
    public:
        Node<T>* head;
        Node<T>* tail;
        List();
        void print();
        //passa end memoria
        void add(Node<T> *newNode);
        void add(List<T> *newList);
        int printItem();
        Node<T>* findItem(std::string key);
        int removeItem(std::string key);
        
        ~List();
};
        #include"list.inl"


#endif