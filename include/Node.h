#ifndef NODE_H
#define NODE_H


template <typename T> 
 
class Node {    
    private:
        T data;
        Node* next;
    public:
        Node();
        Node(T data);
    
        
};
#include "node.inl"


#endif