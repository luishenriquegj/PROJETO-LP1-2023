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
void List<T>::add(Node <T> *newNode) { 
    if ( this->head == nullptr) {
        this->head = newNode;
    } 
    else {
        Node<T>* current =  this->head;
        while   (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        this->tail = newNode;
       
    }
   
}



template<typename T>
int List<T>::print() {
    if(this->head == nullptr) {
            std::cout<<"unable to display playlist, playlist is empty"<<std::endl;
            return 0;
    }
    Node<T>* current = this->head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        std::cout << "--------------------------------"<< std::endl;
        current = current->next;
    }
    return 1;
}

template<typename T>
Node<T>* List<T>::findItem(std::string key) {
    if(this->head == nullptr) {
        std::cout<<"unable to get playlist/song, playlist be empty or song name was misspelled"<<std::endl;
        return nullptr;
    }
    Node<T>* current = this->head;

    while (current != nullptr) {
        if(current->data.getKey() == key){
            return  current;
        }
        current = current->next;
    }

    return nullptr;
}

template<typename T>
int List<T>::printItem() {
     if(this->head == nullptr) {
            std::cout<<"unable to display playlist, it might be empty or song name is wrong"<<std::endl;
            return 0;
    }
    Node<T>* current = this->head;
    std::string key;

    std::cout<<"search by song/playlist name:"<<std::endl;
    getline(std::cin,key);
    while (current != nullptr) {
        if(current->data.getKey() == key){
            std::cout<<" found: "<<current->data<<"\n"<<std::endl;
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
    if(this->head== nullptr) {
            std::cout<<"unable to remove song, playlist is already empty"<<std::endl;
            return 0;
    }
    Node<T>* current = this->head;
    Node<T>* previous = nullptr;
    std::string key;

    std::cout << "What song are you looking for?" << std::endl;
    getline(std::cin, key);
    while (current != nullptr) {
        if (current->data.getKey() == key) {
            std::cout << "Found song: " << key << std::endl;
            if (current == this->head) {
                // Remove first node
                this->head = current->next;
            } else {
                // Remove non-first node
                previous->next = current->next;
               if (current->data.getKey() == this->tail->data.getKey()) {
                    this->tail = previous;
               }

            }
            delete current;
            return 1; // song removed successfully
        }
        previous = current;
        current = current->next;
    }

    std::cout << "Song not found: " << key << std::endl;
    return 0; // song not found
}

template<typename T>
List<T>::~List() {
    Node<T>* current = this->head;
    while(current!=nullptr){
        Node<T>* aux = current;
        current = current->next;
        delete aux;
    }
    this->head = nullptr;
    

}

