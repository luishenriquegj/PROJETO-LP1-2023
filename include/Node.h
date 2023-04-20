#ifndef NODE_H
#define NODE_H


template <typename U> 
 
class Node {    
    private:
        <U> data;
        Node* next;
    public:
        Node();
        Node(U data);
    
        
        #include "node.inl"
};


#endif