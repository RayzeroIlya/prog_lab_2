#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node{
    T data;
    Node<T>* next;
    Node() : next(nullptr){}
    Node(T _data): data(_data) , next(nullptr){}

};