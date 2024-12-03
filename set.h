#ifndef SET_H
#define SET_H
#include <iostream>
#include "node.h"


template <typename T>
struct Set {
    Node<T>* head;

    Set() : head(nullptr) {}

    ~Set() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void SETADD(const T& element) {
        if (!SET_AT(element)) {
            Node<T>* newNode = new Node<T>(element);
            newNode->next = head;
            head = newNode;
        }
    }

    bool SETDEL(const T& element) {
        if (head == nullptr) return false;

        if (head->data == element) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != element) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        return false;
    }


    bool SET_AT(const T& element) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const {
        std::cout << "{ ";
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "}" << std::endl;
    }
};
#endif