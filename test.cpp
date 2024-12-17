/*

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "hashtable.h" // Подключаем вашу хеш-таблицу

using namespace std;

// Хеш-таблица для хранения потомков
HashTable<string, vector<string>>* tree= new HashTable<string,vector<string>>(100); // Размер таблицы можно выбрать произвольно

// Хеш-таблица для хранения количества потомков
HashTable<string, int>* descendantsCount = new HashTable<string,int>(100); // Размер таблицы можно выбрать произвольно

// Функция для подсчета потомков
int countDescendants(const string& name) {
    // Проверяем, есть ли уже подсчитанное количество потомков
    try {
        return descendantsCount->HGET(name);
    } catch (const runtime_error&) {
        // Если ключ не найден, продолжаем подсчет
    }

    int count = 0;
    // Рекурсивно считаем потомков для каждого потомка
    try {
        vector<string> children = tree->HGET(name);
        for (const string& child : children) {
            count += 1 + countDescendants(child);
        }
    } catch (const runtime_error&) {
        // Если ключ не найден, просто пропускаем
    }

    descendantsCount->HINSERT(name, count); // Сохраняем результат
    return count;
}

int main() {
    int N;
    cout << "Input number of elemets: ";
    cin >> N;

    cout << "Input chiled parent : \n";
    // Чтение входных данных
    for (int i = 0; i < N - 1; ++i) {
        string child, parent;
        cin >> child >> parent;
        try {
            vector<string> children = tree->HGET(parent);
            children.push_back(child);
            tree->HINSERT(parent, children);
        } catch (const runtime_error& ex) {
            // Если родитель не найден, создаем новую запись
            tree->HINSERT(parent, vector<string>{child});
        }
    }

    // Подсчет потомков для каждого элемента
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name; // Считываем имена для подсчета потомков
        countDescendants(name);
    }

    // Сбор всех уникальных имен
    vector<string> names;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name; // Считываем имена для вывода
        names.push_back(name);
    }

    // Удаляем дубликаты
    sort(names.begin(), names.end());
    names.erase(unique(names.begin(), names.end()), names.end());

    // Вывод результата
    for (const string& name : names) {
        int count = 0;
        try {
            count = descendantsCount->HGET(name);
        } catch (const runtime_error&) {
            count = 0; // Если не найдено, потомков 0
        }
        cout << name << " " << count << endl;
    }

    return 0;
}

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "hashtable.h" // Подключаем вашу хеш-таблицу
#include "set.h"
#include "linkedlist.h"
using namespace std;



// Функция для подсчета потомков
int countDescendants(const string& name, HashTable<string,int>* descendantsCount, HashTable<string, LinkedList<string>>* tree) {
    // Проверяем, есть ли уже подсчитанное количество потомков
    try {
        return descendantsCount->HGET(name);
    } catch (const exception&) {
        // Если ключ не найден, продолжаем подсчет
    }

    int count = 0;
    // Рекурсивно считаем потомков для каждого потомка
    try {
        LinkedList<string> children = tree->HGET(name);
        for (const string& child : children) {
            count += 1 + countDescendants(child, descendantsCount,tree);
        }
    } catch (const exception&) {
        // Если ключ не найден, просто пропускаем
    }

    descendantsCount->HINSERT(name, count); // Сохраняем результат
    return count;
}

int main() {

// Хеш-таблица для хранения потомков
HashTable<string, LinkedList<string>>* tree = new HashTable<string,LinkedList<string>>(100); // Размер таблицы можно выбрать произвольно

// Хеш-таблица для хранения количества потомков
HashTable<string, int>* descendantsCount= new HashTable<string,int>(100); // Размер таблицы можно выбрать произвольно

    Set<string>* names = new Set<string>();

    int N;
    cout << "Count of elemnts: ";
    cin >> N;

    // Чтение входных данных
    for (int i = 0; i < N - 1; ++i) {
        cout << i << endl;
        string child, parent;
        cin >> child >> parent;
        names->SETADD(child);
        names->SETADD(parent);
        try {
            LinkedList<string> children = tree->HGET(parent);
            children.SLPUSH(child);
            tree->HINSERT(parent, children);
        } catch (const exception& ex) {
            // Если родитель не найден, создаем новую запись
            tree->HINSERT(parent, LinkedList<string>(child));
        }
    }

    // Подсчет потомков для каждого элемента
    Node<string>* cur=names->head;
    for (int i = 0; i < N; ++i) {
        countDescendants(cur->data,descendantsCount,tree);
        cur=cur->next;
    }



    // Вывод результата
    cur=names->head;
    while (cur) {
        int count = 0;
        try {
            count = descendantsCount->HGET(cur->data);
        } catch (const runtime_error&) {
            count = 0; // Если не найдено, потомков 0
        }
        cout << cur->data << " " << count << endl;
        cur=cur->next;
    }

    return 0;
}