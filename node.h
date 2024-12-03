    #ifndef NODE_H
    #define NODE_H
    
    #include <iostream>
    
    template <typename T>
    struct Node {
    T data;
    Node* next;
        Node() : next(nullptr){}
    Node(const T& val) : data(val), next(nullptr) {}
    };
    #endif