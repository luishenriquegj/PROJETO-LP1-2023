/*!
    List() é a estrutura de dados que armazena as musicas e as playlists, 
    *deve ser inicializada sem argumentos, para sempre termos uma lista nova
*/

#include "List.h"
#include "Node.h"
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>

/**
* @brief List() é um construtor padrao, responsavel por instanciar uma nova lista sem valores atribuidos.

*/

template <typename T>
List<T>::List() {
    this->head = nullptr;
    this->tail = nullptr;
};

/**
* @brief List(List<T> *listToCopy) é um construtor copia, responsavel por instanciar uma nova lista copiando os valores de outra.
* @param List<T> *listToCopy

*/

template <typename T>
List<T>::List(List<T> *listToCopy) {
    this->head = listToCopy->head;
    this->tail = listToCopy->tail;
};

/**
* @brief add() é uma função template responsavel por inserir um novo Node na List,este novo node deve vir populado com suas informações (data);
* para manter a  reusabilidade é imporante utilizar o nome dos atributios de maneira identica aos usados na classe Music.
* @param Node<T> *newNode
*/
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
   
};

template <typename T>
void List<T>::add(List<T> *newList){
    Node<T>* current = newList->head;

    while(current->next !=nullptr){
        this->add(current);
        current = current->next;
    }
};

/**
* @brief print() é uma função template responsavel por printar todos os elementos presentes em uma List;    
*/

template<typename T>
void List<T>::print() {
    if(this->head == nullptr) {
        std::cout<<"unable to display playlist, playlist is empty"<<std::endl;
        return;
    }
    Node<T>* current = this->head;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        std::cout << "--------------------------------"<< std::endl;
        current = current->next;
    }
    return;
}

/**
* @brief findItem() é uma função template que recebe um elemento do tipo string e tem como finalidade 
* identificar se o nome está correspondete ao nome playlist ou ao titulo de uma música por exemplo;    
*/

template<typename T>
Node<T>* List<T>::findItem(std::string key) {
    if(this->head == nullptr) {
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

/**
* @brief printItem() é uma função template responsavel por printar um elemento, 
* podendo ele ser uma música, ou uma playlist;
*/

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

/**
* @brief removeItem() é uma função template responsavel por apagar uma musica do sistema.
* @return retorne 1, significa que ela está apagando a musica;
* @return retorne 0, significa que ela ou não encontrou a musica ou o sistema esta vazio
*/

template<typename T>
int List<T>::removeItem(std::string key) {
    if(this->head== nullptr) {
        std::cout<<"unable to remove song, playlist is already empty"<<std::endl;
        return 0;
    }
    Node<T>* current = this->head;
    Node<T>* previous = nullptr;
    
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
int List<T>::removeItem(List<T> &musicList) {
    
    if(this->head== nullptr) {
        std::cout<<"unable to remove song, playlist is already empty"<<std::endl;
        return 0;
    }

    Node<T>* current = this->head;
    Node<T>* previous = nullptr;
    Node<T>* currentMusicList = musicList.head;
    int count =0;
    
    
    while (currentMusicList != nullptr) {
        if (current->data.getKey() == currentMusicList->data.getKey()) {
            count++;
            std::cout << "Found song: " << current->data.getKey() << std::endl;
            
            if (current == this->head) {
                // Remove first node
                this->head = current->next;
            } else {
                // Remove non-first node
                previous->next = current->next;
                //updates the tail
                if (current->data.getKey() == this->tail->data.getKey()) {
                    this->tail = previous;
                }

            }
            delete current;
        }
        if (current == this->tail) {
                // Remove first node
               currentMusicList = currentMusicList->next;
               current = this->head;
               previous = nullptr;
        }else{
            previous = current;
            current = current->next;
        }
    }
    std::cout<<"removed a total of "<< count<< " musics" <<std::endl;
    return 0; 
}

/*!
    ~List() é uma destrutor responsavel por desalocar os elementos alocados na memória para essa lista;

*/

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

