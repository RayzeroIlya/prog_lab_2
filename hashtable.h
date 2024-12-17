#pragma once
#include <iostream> 
#include <fstream> 
 
template <typename Key, typename Value> 
struct HNode { 
    Key key; 
    Value value; 
    HNode* next; 
 
    HNode(const Key& _key, const Value& _value) : key(_key), value(_value), next(nullptr) {} 
}; 
 
template <typename Key, typename Value> 
struct HashTable { 
    HNode<Key, Value>** table; 
    int size; 
 
    HashTable(int _size) : size(_size) { 
        table = new HNode<Key, Value>*[_size]; 
        for (int i = 0; i < _size; i++) { 
            table[i] = nullptr; 
        } 
    } 
 
    ~HashTable() { 
        for (int i = 0; i < size; ++i) { 
            HNode<Key, Value>* current = table[i]; 
            while (current != nullptr) { 
                HNode<Key, Value>* next = current->next; 
                delete current; 
                current = next; 
            } 
        } 
        delete[] table; 
    } 
 

    int hash(const std::string& key) { 
     int sum = 0; 
     for (char c : key) { 
       sum += c; 
     } 
    return std::abs(sum) % size; 
    }    
 
    // Добавление элемента 
    void HINSERT(const Key& key, const Value& value) { 
        int index = hash(key); 
        HNode<Key, Value>* newNode = new HNode<Key, Value>(key, value); 
        HNode<Key, Value>* current = table[index]; 
        HNode<Key, Value>* prev = nullptr; 
 
        while (current != nullptr) { 
            if (current->key == key) { 
                delete newNode; 
                std::cerr << "Key already exists" << std::endl; 
                return; 
            } 
            prev = current; 
            current = current->next; 
        } 
 
        newNode->next = current; 
        if (prev == nullptr) { 
            table[index] = newNode; 
        } else { 
            prev->next = newNode; 
        } 
    } 
 
    // Получение значения по ключу 
    Value HGET(const Key& key) { 
        int index = hash(key); 
        HNode<Key, Value>* current = table[index]; 
        while (current != nullptr) { 
            if (current->key == key) { 
                return current->value; 
            } 
            current = current->next; 
        } 
        throw std::runtime_error("Key not found"); 
    } 
 
    // Удаление элемента по ключу 
    void HREMOVE(const Key& key) { 
        int index = hash(key); 
        HNode<Key, Value>* current = table[index]; 
        HNode<Key, Value>* previous = nullptr; 
 
        while (current != nullptr) { 
            if (current->key == key) { 
                if (previous == nullptr) { 
                    table[index] = current->next; 
                } else { 
                    previous->next = current->next; 
                } 
                delete current; 
                return; 
            } 
            previous = current; 
            current = current->next; 
        } 
        throw std::runtime_error("Key not found"); 
    } 
 
    // Запись в файл (без изменений) 
    void saveToFile(const std::string& filename) const { 
        std::ofstream file(filename); 
        if (!file.is_open()) { 
            throw std::runtime_error("Cannot open file for writing"); 
        } 
        file << size << std::endl; 
        for (int i = 0; i < size; i++) { 
            HNode<Key, Value>* current = table[i]; 
            while (current != nullptr) { 
                file << current->key << " " << current->value << " "; 
                current = current->next; 
            } 
            file << std::endl; 
        } 
        file.close(); 
    } 
 
    // Чтение из файла 
    void loadFromFile(const std::string& filename) { 
        std::ifstream file(filename); 
        if (!file.is_open()) { 
            throw std::runtime_error("Cannot open file for reading"); 
        } 
        int _size; 
        file >> _size; 
        if (_size != size) { 
            throw std::runtime_error("Table size mismatch"); 
        } 
 
        // Правильное очищение таблицы: 
        for (int i = 0; i < size; i++) { 
            HNode<Key, Value>* current = table[i]; 
            while (current != nullptr) { 
                HNode<Key, Value>* next = current->next; 
                delete current; 
                current = next; 
            } 
            table[i] = nullptr; 
        } 
 
        Key key; 
        Value value; 
        while (file >> key >> value) { 
            HINSERT(key, value); 
        }
        file.close(); 
    } 
};