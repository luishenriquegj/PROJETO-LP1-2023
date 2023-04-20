#ifndef LIST_INL
#define LIST_INL

#include "List.h"

template <typename Y>
List<Y>::List() {
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename Y>
List<Y>::List(Node<Y>* head) {
    this->head = head;
    this->tail = nullptr;
}

template <typename Y>
void List<Y>::setTail(Node<Y>* tail) {
    this->tail = tail;
}

template <typename Y>
void List<Y>::setHead(Node<Y>* head) {
    this->head = head;
}

#endif