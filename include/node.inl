template <typename U> 
Node<U>::Node(){
    U data = 0;
    next = nullptr;
}
template <typename U> 
Node<U>::Node( U data){
    this->data = data;
    this->next = nullptr;
}