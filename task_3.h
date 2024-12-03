#pragma once
#include <iostream>
#include <numeric>
#include "set.h"

using namespace std;

const int MAX_SIZE = 100; // Максимальный размер множества

void findMinDifferenceSubsets(const Set<int>& inputSet) {
    int nums[MAX_SIZE];
    int n = 0;
    
    // Преобразуем множество в массив
    Node<int>* current = inputSet.head;
    while (current != nullptr) {
        nums[n++] = current->data;
        current = current->next;
    }

    int totalSum = accumulate(nums, nums + n, 0);
    int halfSum = totalSum / 2;

    // Создаем таблицу для динамического программирования
    bool dp[MAX_SIZE + 1][halfSum + 1] = {false};
    dp[0][0] = true;

    // Заполняем таблицу
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= halfSum; j++) {
            dp[i][j] = dp[i - 1][j]; // Не берем текущий элемент
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]]; // Берем текущий элемент
            }
        }
    }

    // Находим максимальную сумму, которая может быть достигнута
    int sum1;
    for (sum1 = halfSum; sum1 >= 0; sum1--) {
        if (dp[n][sum1]) break;
    }

    int sum2 = totalSum - sum1;
    int difference = abs(sum1 - sum2);

    // Восстанавливаем подмножества
    int subset1[MAX_SIZE], subset2[MAX_SIZE];
    int index1 = 0, index2 = 0;
    int w = sum1;
    for (int i = n; i > 0 && w >= 0; i--) {
        if (!dp[i - 1][w]) { // Если элемент был включен
            subset1[index1++] = nums[i - 1];
            w -= nums[i - 1];
        } else {
            subset2[index2++] = nums[i - 1];
        }
    }

    // Выводим результаты
    cout << "Подмножество 1: { ";
    for (int i = 0; i < index1; i++) {
        cout << subset1[i] << " ";
    }
    cout << "}" << endl;

    cout << "Подмножество 2: { ";
    for (int i = 0; i < index2; i++) {
        cout << subset2[i] << " ";
    }
    cout << "}" << endl;

    cout << "Разница между суммами: " << difference << endl;
}
