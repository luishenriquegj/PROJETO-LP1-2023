#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <string>
#include <iostream>

template <typename T> 

class List {
    public:
        Node<T>* head;
        Node<T>* tail;
        List();
        List( List <T> *listToCopy);
        void print();
        //passa end memoria
        void add(Node<T> *newNode);
        void add(List<T> *newList);
        int printItem();
        Node<T>* findItem(std::string key);
        int removeItem(std::string key);
        int removeItem(List<T>& musicList);

        ~List();


        List<T>* operator+(List<T> &secondlist) {
                Node<T>* current = secondlist.head;
                List<T>* newList = this;

                while(current!=nullptr){
                        newList->add(current);
                        current = current->next;
                }

                return newList;
        }

        

        void operator>>(Node<T> *node) {
                if(head==nullptr){
                        node = nullptr;
                }
                else{
                        Node<T>* current = head;
                        while(current->next != nullptr){
                                current = current->next;
                        }
                        node->data= current->data;
                        node->next = nullptr;

                }
        }
       
        void operator<<(Node<T>* node) {
                if(node == nullptr){
                        return;
                }
                this->add(node);
        }
};
        #include"list.inl"


#endif