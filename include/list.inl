#include "List.h"
#include "Node.h"
#include <unistd.h>

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


template <typename T>
void List<T>::setTail(Node<T>* tail) {
    this->tail = tail;
};

template <typename T>
void List<T>::setHead(Node<T>* head) {
    this->head = head;
};
