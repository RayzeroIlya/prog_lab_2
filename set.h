#include <iostream> 
 
using namespace std; 
 
// Структура для хранения множества 
template <typename T> 
struct MySet { 
  T* data; 
  size_t size; 
  size_t capacity; 
}; 
 
// Инициализация множества 
template <typename T> 
MySet<T> createSet() { 
  MySet<T> set; 
  set.data = new T[1]; 
  set.size = 0; 
  set.capacity = 1; 
  return set; 
} 
 
// Освобождение памяти 
template <typename T> 
void destroySet(MySet<T>& set) { 
  delete[] set.data; 
} 
 
// Вспомогательная функция для поиска элемента в множестве 
template <typename T> 
size_t find(const MySet<T>& set, const T& value) { 
  for (size_t i = 0; i < set.size; ++i) { 
    if (set.data[i] == value) { 
      return i; 
    } 
  } 
  return set.size; 
} 
 
// Вспомогательная функция для увеличения емкости множества 
template <typename T> 
void resize(MySet<T>& set) { 
  set.capacity *= 2; 
  T* newData = new T[set.capacity]; 
  for (size_t i = 0; i < set.size; ++i) { 
    newData[i] = set.data[i]; 
  } 
  delete[] set.data; 
  set.data = newData; 
} 
 
// Добавление элемента в множество 
template <typename T> 
void insert(MySet<T>& set, const T& value) { 
  if (find(set, value) == set.size) { 
    if (set.size == set.capacity) { 
      resize(set); 
    } 
    set.data[set.size++] = value; 
  } 
} 
 
// Удаление элемента из множества 
template <typename T> 
void erase(MySet<T>& set, const T& value) { 
  size_t index = find(set, value); 
  if (index < set.size) { 
    for (size_t i = index; i < set.size - 1; ++i) { 
      set.data[i] = set.data[i + 1]; 
    } 
    --set.size; 
  } 
} 
 
// Проверка наличия элемента в множестве 
template <typename T> 
bool contains(const MySet<T>& set, const T& value) { 
  return find(set, value) != set.size; 
} 
 
// Размер множества 
template <typename T> 
size_t getSize(const MySet<T>& set) { 
  return set.size; 
} 
 
// Вывод элементов множества 
template <typename T> 
void print(const MySet<T>& set) { 
  cout << "Элементы множества: "; 
  for (size_t i = 0; i < set.size; ++i) { 
    cout << set.data[i] << " "; 
  } 
  cout << endl; 
} 
 
