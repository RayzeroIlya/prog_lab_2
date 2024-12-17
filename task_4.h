#include <iostream>
#include <sstream>
#include "array.h"
#include <string>
using namespace std;
void task_4() {

    Array* marr= new Array();
    cout << "Input array: ";
    string str_arr;
    getline(cin,str_arr);
    stringstream ss(str_arr);
    
    while (getline(ss,str_arr,' ')){
        marr->MPUSH(stoi(str_arr));
    }

    int n= marr->MSIZE();
    cout << "Input target sum: ";
    int targetSum ; // Целевая сумма
    cin >> targetSum;

    bool found = false;

    // Используем два вложенных цикла для нахождения всех подмассивов
    for (int start = 0; start < n; ++start) {
        int currentSum = 0;

        for (int end = start; end < n; ++end) {
            currentSum += marr->MAT(end);

            // Если текущая сумма равна целевой, выводим подмассив
            if (currentSum == targetSum) {
                found = true;
                 cout << "Подмассив с индексами: [" << start << ", " << end << "] -> ";
                for (int i = start; i <= end; ++i) {
                     cout << marr->MAT(i) << " ";
                }
                 cout <<  endl;
            }
        }
    }

    if (!found) {
         cout << "Подмассивы с заданной суммой не найдены." <<  endl;
    }
}