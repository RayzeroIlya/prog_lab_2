#ifndef SET_H
#define SET_H
#include <iostream>
#include "node.h"


template <typename T>
struct Set {
    Node<T>* head;
    int size=0;
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
            size++;
        }
    }

    bool SETDEL(const T& element) {
        if (head == nullptr) return false;

        if (head->data == element) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
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
            size--;
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
    int sum() {
        Node<T>* temp= head;
        int sum=0;
        while (temp ) {
            sum+= temp->data;
            temp=temp->next;
        }
        return sum;
    }

    int get_size() { return size;}
    int AT_INDEX(int index){
        if(size<=index) {
            throw std::invalid_argument("Invalid index.\n");
        }

        int pos=0;
        Node<T>* temp=head;

        while (temp) {
            if (pos == index) return temp->data;
            else {
                temp=temp->next;
                pos++;
            }
        }

    }
};
#endif