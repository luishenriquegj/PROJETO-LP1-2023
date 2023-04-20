#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <typename Y> 

class List {    
    private:
        Node<Y>* head;
        Node<Y>* tail;
    public:
        List();
        List(Node<Y>* head);    
        void setTail(Node<Y>* tail);
        void setHead(Node<Y>* head);
        
    #include "list.inl"
};


#endif