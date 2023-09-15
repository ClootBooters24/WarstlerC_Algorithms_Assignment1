#include <linked_list.hpp>

template<class T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode<T>* next, LinkedListNode<T>* prev) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

template<class T>
LinkedListNode<T>::~LinkedListNode() {
    this->next = NULL;
}


template<class T>
LinkedList<T>::LinkedList() {
     this->root = NULL;
}

template<class T>
LinkedList<T>::~LinkedList() {
    // YOUR CODE HERE
    LinkedListNode<T>* p = this->root;
    while(p != NULL){
        LinkedListNode<T>* temp = p->next;
        delete p;
        p = temp;
    }

}


template<class T>
LinkedListNode<T>* LinkedList<T>::insert(T value) {
    // YOUR CODE HERE
    LinkedListNode<T>* p = this->root;
    while(p != NULL) {
        if (p->value == value)
            return p;

        p = p->next;
    }

    LinkedListNode<T>* x = new LinkedListNode<T>();
    x->value = value;
    x->next = this->root;
    this->root = x;
    return this->root;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::find(T value) {
    // YOUR CODE HERE
    LinkedListNode<T>* p = this->root;
    while(p != NULL){
        if(p->value == value) break;
        p = p->next;
    }
    return p;
}

template<class T>
LinkedListNode<T>* LinkedList<T>::remove(T value) {
    // YOUR CODE HERE
    LinkedListNode<T>* p = this->root;
    LinkedListNode<T>* q = NULL;
    while(p != NULL){
        if(p->value == value){
            if(q == NULL)
                this->root = p->next;
            else
                q->next = p->next;
            delete p;
            break;
        }
        q = p;
        p = p->next;
    }
    return this->root;
}

template<class T>
int LinkedList<T>::size() {
    // YOUR CODE HERE
    LinkedListNode<T>* p = this->root;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

template class LinkedListNode<int>;
template class LinkedList<int>;
