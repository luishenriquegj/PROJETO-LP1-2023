#ifndef LIST_H
#define LIST_H

#include "Node.h"
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
        int removeItem(List<T>& musicList);

        ~List();

        List<T>* operator+(List<T> &secondlist) {
                Node<T>* current = head;
                List<T>* newList = new List<T>();
                while(current!=nullptr){
                        newList->add(current);
                        current = current->next;
                }
                current = secondlist.head;
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
                if(head->next!=nullptr){
                        Node<T>* current = head;
                        while(current->next != nullptr){
                                current = current->next;
                        }
                }else{
                        head->next = node;
                }
        }
};
        #include"list.inl"


#endif