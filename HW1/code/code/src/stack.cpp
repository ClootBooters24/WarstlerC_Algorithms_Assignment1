#include <stack.hpp>

template<class T>
StackNode<T>::StackNode(T value, StackNode<T> *next, StackNode<T> *prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
StackNode<T>::~StackNode() {
    this->next = this->prev = NULL;
}

template<class T>
Stack<T>::Stack() : head(nullptr), tail(nullptr) {

}

template<class T>
Stack<T>::~Stack() {
    while(head != NULL){
        StackNode<T> *temp = head;
        head = head->next;
        delete temp;
    }

    head = NULL;
}

template<class T>
bool Stack<T>::empty() {
    return (head == NULL);
}

template<class T>
T Stack<T>::pop() {
    // YOUR CODE HERE
    if(empty()) {
        return 0;
    }
    else{
        T poppedValue = this->head->value;
        StackNode<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;

        std::cout << poppedValue << std::endl;
        return poppedValue;
    }
}


template<class T>
void Stack<T>::push(T value) {
    StackNode<T> *p = new StackNode<T>(value, NULL, NULL);
    if(empty()) {
        this->head = this->tail = p;
    }
    else {
        p->next = this->head;
        this->head->prev = p;
        this->head = p;
    }
}

template class Stack<int>;
