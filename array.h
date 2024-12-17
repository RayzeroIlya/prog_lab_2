#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/stat.h>
using namespace std;


struct Array{
    int* arr;
    int size;

    Array(): size() {};

    void MINSERT (const int& index, const int& value){
                if (index < 0 || index > size) {
            cout << "Неверный индекс." << endl;
            return;
        }
      arr[index]=value;

    }
    void MPUSH(const int& value) {
      int*  newArr=new int[size+1];
      for (int i =0;i<size;i++) newArr[i]=arr[i];
      newArr[size]=value;
      delete[] arr;
      arr=newArr;
      size++;
    }

    int MAT(const int& index){
        if (index < 0 || index>size){
            cout << "Неверный индекс." << endl;
            return -1;
        }
        return arr[index];

    }

    void MDELETEAT (const int& index) {
        if (index < 0 || index>size){
            cout << "Неверный индекс." << endl;
            return;
        }
        int* newArr=new int[size-1];
        for (int i =0;i<index;i++) {
            newArr[i]=arr[i];
        }
        for (int i = index+1;i<size;i++){
            newArr[i-1]=arr[i];
        }
        delete[] arr;
        arr=newArr;
        size--;
    }
    int MSIZE() {
        return size;
    }
    void MGET(const string& file_name, const string& con_name){
        ifstream fin(file_name, ios_base::in);       
        string row;
        while (getline(fin,row)){
            stringstream ss(row);
            string val;
            getline(ss,val,' ');
            if( val== con_name) {
                while (getline(ss,val,' ')) {
                    MPUSH(stoi(val));
                 }
                 fin.close();
                 return;
            }
        }
       fin.close();
       throw runtime_error("Array doesnt exist");
    }
    void MOUT(const string& file_name, const string& con_name){
        ifstream fin(file_name);
        ofstream fout(file_name+".tmp", ios_base::app);
        string row;
        while(getline(fin,row)){
                string name;
                stringstream ss(row);
                getline(ss,name,' ');
                if (name==con_name) continue;
                fout<<row<<endl;
        }
        fout << con_name << " ";
        for (int i =0 ; i<size;i++) {
            fout << arr[i] << " ";
        }
        fout << endl;
        remove(file_name.c_str());
        rename((file_name+".tmp").c_str(), file_name.c_str());
    }

    Array MINIT(const string& file_name, const string& con_name,const int& size){
        ofstream fout (file_name, ios_base::app);
        Array arr;
        arr.size=size;
        arr.arr=new int[size];
        for (int i =0;i<size;i++) arr.arr[i]=0;
        return arr;
    }
    int& operator[](const int& index){
        if (index < 0 || index >=size) throw range_error("Invalid index");
        return arr[index];
    }
};