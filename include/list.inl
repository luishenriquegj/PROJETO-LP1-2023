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
    std::cout<< "cbc "<< this->head->data.getTitle()<<std::endl;
    std::cout<< "cauda " << this->tail->data.getTitle()<<std::endl;
    Node<T>* current = this->head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        std::cout << "--------------------------------"<< std::endl;
        current = current->next;
        sleep(1);
    }
    return 1;
}

template<typename T>
int List<T>::findSong() {
     if(this->head == nullptr) {
            std::cout<<"unable to display playlist, it might be empty or song name is wrong"<<std::endl;
            return 0;
    }
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
    if(this->head== nullptr) {
            std::cout<<"unable to remove song, playlist is already empty"<<std::endl;
            return 0;
    }
    Node<T>* current = this->head;
    Node<T>* previous = nullptr;
    std::string musicTitle;

    std::cout << "What song are you looking for?" << std::endl;
    getline(std::cin, musicTitle);
    while (current != nullptr) {
        if (current->data.getTitle() == musicTitle) {
            std::cout << "Found song: " << musicTitle << std::endl;
            if (current == this->head) {
                // Remove first node
                this->head = current->next;
            } else {
                // Remove non-first node
                previous->next = current->next;
               if (current->data.getTitle() == this->tail->data.getTitle()) {
                    this->tail = previous;
               }

            }
            delete current;
            return 1; // song removed successfully
        }
        previous = current;
        current = current->next;
    }

    std::cout << "Song not found: " << musicTitle << std::endl;
    return 0; // song not found
}


