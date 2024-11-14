#ifndef SLLNODE_HPP
#define SLLNODE_HPP

#include <iostream>
using namespace std;

template <class T>
class SLLNode {
    private:
        T data;
        SLLNode<T> *next;
    public:
        SLLNode(): data(), next(nullptr) {}
        SLLNode(T data, SLLNode<T> *next): data(data), next(next) {}
        T getData() const { return data; }
        SLLNode<T> *getNext() const { return next; }
        void setData(T data) { this->data = data; }
        void setNext(SLLNode<T> *next) { this->next = next; }
};

#endif