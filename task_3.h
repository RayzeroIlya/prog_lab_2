#include <iostream>
#include "set.h"

template <typename T> 
void splitSetMinDiff(const MySet<T>& originalSet, MySet<T>& set1, MySet<T>& set2) { 
    // Считаем общую сумму всех элементов 
    T totalSum = 0; 
    for (size_t i = 0; i < originalSet.size; ++i) { 
        totalSum += originalSet.data[i]; 
    } 
     
    // Сортируем элементы по убыванию 
    T* sortedData = new T[originalSet.size]; 
    for (size_t i = 0; i < originalSet.size; ++i) { 
        sortedData[i] = originalSet.data[i]; 
    } 
     
    for (size_t i = 0; i < originalSet.size - 1; ++i) { 
        for (size_t j = 0; j < originalSet.size - i - 1; ++j) { 
            if (sortedData[j] < sortedData[j + 1]) { 
                T temp = sortedData[j]; 
                sortedData[j] = sortedData[j + 1]; 
                sortedData[j + 1] = temp; 
            } 
        } 
    } 
     
    // Распределяем элементы по подмножествам 
    T sum1 = 0, sum2 = 0; 
    for (size_t i = 0; i < originalSet.size; ++i) { 
        if (sum1 <= sum2) { 
            insert(set1, sortedData[i]); 
            sum1 += sortedData[i]; 
        } else { 
            insert(set2, sortedData[i]); 
            sum2 += sortedData[i]; 
        } 
    } 
     
    delete[] sortedData; 
} 
 
// Функция для подсчета суммы элементов множества 
template <typename T> 
T getSum(const MySet<T>& set) { 
    T sum = 0; 
    for (size_t i = 0; i < set.size; ++i) { 
        sum += set.data[i]; 
    } 
    return sum; 
} 
 
// Функция для вывода результата 
template <typename T> 
void printSplitResult(const MySet<T>& originalSet) { 
    MySet<T> set1 = createSet<T>(); 
    MySet<T> set2 = createSet<T>(); 
     
    splitSetMinDiff(originalSet, set1, set2); 
     
    cout << "Первое подмножество: "; 
    print(set1); 
     
    cout << "Второе подмножество: "; 
    print(set2); 
     
    T sum1 = getSum(set1); 
    T sum2 = getSum(set2); 
     
    cout << "Сумма первого подмножества: " << sum1 << endl; 
    cout << "Сумма второго подмножества: " << sum2 << endl; 
    cout << "Разница сумм: " << abs(sum1 - sum2) << endl; 
     
    // Освобождаем память 
    destroySet(set1); 
    destroySet(set2); 
}