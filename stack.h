#pragma once
#include <iostream>
#include "node.h"

template <typename T>
struct Stack{
    Node<T>* first;

    Stack() : first(nullptr){}

    void SPUSH(const T& _data) {
        Node<T>* newNode = new Node(_data);
        newNode->next=first;
        first=newNode;
    return;
    }
    T SPOP(){
        if (first == nullptr) throw "Stack is empty";
        Node<T>* fNode=first;
        T temp=fNode->data;
        first=first->next;
        delete fNode;
        return temp;
    }
    
    bool isEmpty(){
        return first == nullptr;
}
    T top(){
        if (first == nullptr) throw "Stack is empty";
    
    return first->data;}

    T peek(){
        return first->data;
    }

    void clear(){
    Node<T> temp;
    temp=first;
    first=first->next;
    delete temp;
    }
};