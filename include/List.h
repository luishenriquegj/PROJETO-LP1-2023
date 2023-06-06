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

        List<T>& operator+(List<T>& secondlist) {
                Node<T>* current = head;
                if(current ==nullptr){
                       this->add(secondlist.head);
                       return *this;
                }
                while (current->next != nullptr) {
                        current = current->next;
                }
        
                Node<T>* secondCurrent = secondlist.head;
                while (secondCurrent != nullptr) {
                        current->next = new Node<T>(secondCurrent->data);
                        current = current->next;
                        secondCurrent = secondCurrent->next;
                }
        
                return *this;
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