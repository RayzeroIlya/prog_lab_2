#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Хеш-таблица для хранения потомков
unordered_map<string, vector<string>> tree;

// Хеш-таблица для хранения количества потомков
unordered_map<string, int> descendantsCount;

// Функция для подсчета потомков
int countDescendants(const string& name) {
    // Если уже посчитано, возвращаем сохраненное значение
    if (descendantsCount.find(name) != descendantsCount.end()) {
        return descendantsCount[name];
    }

    int count = 0;
    // Рекурсивно считаем потомков для каждого потомка
    for (const string& child : tree[name]) {
        count += 1 + countDescendants(child);
    }

    descendantsCount[name] = count; // Сохраняем результат
    return count;
}

int main() {
    int N;
    cin >> N;

    // Чтение входных данных
    for (int i = 0; i < N - 1; ++i) {
        string child, parent;
        cin >> child >> parent;
        tree[parent].push_back(child);
    }

    // Подсчет потомков для каждого элемента
    for (const auto& pair : tree) {
        const string& parent = pair.first;
        countDescendants(parent);
    }

    // Сбор всех уникальных имен
    vector<string> names;
    for (const auto& pair : descendantsCount) {
        names.push_back(pair.first);
    }
    for (const auto& pair : tree) {
        names.push_back(pair.first);
    }

    // Удаляем дубликаты
    sort(names.begin(), names.end());
    names.erase(unique(names.begin(), names.end()), names.end());

    // Вывод результата
    for (const string& name : names) {
        cout << name << " " << descendantsCount[name] << endl;
    }

    return 0;
}