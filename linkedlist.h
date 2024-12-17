#pragma once
#include <iostream>
#include "node.h"
using namespace std;
template <typename T>
struct LinkedList{
    Node<T>* head;
    Node<T>* tail;
    LinkedList<T>(): head(nullptr), tail(nullptr){}
    LinkedList<T> (): head(T elem), tail(nullptr) {
        head->data=elem;
        tail=head;
    } 

    void SLINSERT(const T& data){
        Node<T>* newNode = new Node(data);
        if (head == nullptr){
            head = newNode;
            tail= newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    
        return;
    }
    void SLPUSH(const T& _data) {
        Node<T>* newNode = new Node(_data);
                if (head == nullptr){
            head = newNode;
            tail= newNode;
            return;
        }
        tail->next=newNode;
        tail=newNode;
        return;
    }
    void SLDELHEAD(){
            if (head == nullptr) return;
            Node<T> *temp=head;
            head=temp->next;
            delete temp;
    }
    void SLDELTAIL(){
        if (head==nullptr) return;
        if(head==tail){
            SLDELHEAD();
            return;
        }
        Node<T>* temp=head;
        while (temp->next!=tail) temp=temp->next;
        temp->next=nullptr;
        delete tail;
        tail=temp;
    }
    void SLDEL(const T& _data){
        if (head==nullptr) return;
        if(head==tail && head->data==_data){
            SLDELHEAD();
            return;
        }else if (tail->data==_data){
            SLDELTAIL();
            return;
        }
    Node<T>* one=head;
    Node<T>* two = head->next;
    while (two && two->data!=_data) { //идем пока two есть и его дата не равна искомой
        one=one->next;
        two=two->next;
    }
    if(!two) {
        cout << "Такого элемента нет"<< endl;
        return;
    }
    one->next=two->next;
    delete two;
    }
    Node<T>* SLFIND(const T& _data){
        Node<T>* temp=head;
        while (temp && temp->data!=_data) temp=temp->next;
        return (temp&&temp->data==_data) ? temp : nullptr; //Если нода есть и дата равна искомой

    }

    LinkedList<T>* SLINIT(const string& file_name, const string& con_name){
        ofstream fout(file_name, ios_base::app);
        LinkedList<T>* SList=new LinkedList<T>();
        return SList;
    }

        LinkedList<T>* SLGET(const string& file_name, const string& con_name){
        fstream fin(file_name);
        LinkedList<T>* list = new LinkedList<T>();
        string row;
        while(getline(fin,row)){
        stringstream ss(row);
        string val;
        getline(ss,val,' ');
        if(val==con_name){
            while(getline(ss,val,' ')){
            list->SLPUSH(val);
            }
            fin.close();
            return list;
        }
        }
        fin.close();
        throw runtime_error("SList doesnt exist");
    }
    void SLOUT(const string& file_name, const string& con_name){
        ifstream fin(file_name);
        ofstream fout(file_name+".tmp", ios_base::app);
        string row;
        while(getline(fin,row)){
            string name;
            stringstream ss(row);
            getline(ss,name,' ');
            if (name==con_name) continue;
            fout << row<< endl;
        }
        fout << con_name<< " ";
        Node<string>* cur=head;
        while (cur){
            fout << cur->data << " ";
            cur = cur->next;
        }
        fout << endl;
        remove (file_name.c_str());
        rename ((file_name+".tmp").c_str(),file_name.c_str());
    }
};