#include "List.h"
#include "Node.h"
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>

template <typename T>
List<T>::List() {
    this->head = nullptr;
    this->tail = nullptr;
};

template <typename T>
void List<T>::add(T data) {
    Node<T>* newNode = new Node<T>{data};
    if ( this->head == nullptr) {
        this->head = newNode;
    } else {
        Node<T>* current =  this->head;
      while   (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template<typename T>
void List<T>::print() {
    Node<T>* current = this->head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        std::cout << "--------------------------------"<< std::endl;
        current = current->next;
        sleep(1);
    }
}

template<typename T>
int List<T>::findSong() {
    Node<T>* current = this->head;
    std::string musicTitle;

    std::cout<<"what song are you looking for?"<<std::endl;
    getline(std::cin,musicTitle);
    while (current != nullptr) {
        
        if(current->data.getTitle() == musicTitle){
            std::cout<<"song found:"<<"\n"<<"title:"<<current->data.getTitle()<<"\n"<<"author:"<<current->data.getAuthor()<<std::endl;
            std::cout << "Press any key to continue...";
            std::cin.ignore();
            system("clear");
            return  1;
        }
        current = current->next;
    }
    return 0;
}

template<typename T>
int List<T>::removeSong() {
    Node<T>* current = this->head;
    int* aux =nullptr;
    std::string musicTitle;

    std::cout<<"what song are you looking for?"<<std::endl;
    getline(std::cin,musicTitle);


    while (current != nullptr) {
        if(current->data.getTitle() == musicTitle){
             std::cout<<"cheguei title aq"<<std::endl;
            if(current->next == nullptr) {
                std::cout<<"cheguei 1 aq"<<std::endl;
                Node<T>* current2 = this->head;
                while(current2 != nullptr){
                    if(current2->next->next == nullptr){
                        std::cout<<"cheguei 2 aq"<<std::endl;
                        delete current2->next->next;
                        current2->next = nullptr;
                    }
                    current2 = current2->next;
                }

            }
            
            
        }
        current = current->next;
    }
    
    return 0;
}


