
template <typename T> 
Node<T>::Node(){
    data = 0;
    next = nullptr;
}
template <typename T> 
Node<T>::Node(T data){
    this->data = data;
    this->next = nullptr;
}
        
