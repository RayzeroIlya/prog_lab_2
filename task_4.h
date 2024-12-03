#include <iostream>
using namespace std;
void findAllSubarraysWithSum(int arr[], int n, int targetSum) {
    bool found = false;

    // Используем два вложенных цикла для нахождения всех подмассивов
    for (int start = 0; start < n; ++start) {
        int currentSum = 0;

        for (int end = start; end < n; ++end) {
            currentSum += arr[end];

            // Если текущая сумма равна целевой, выводим подмассив
            if (currentSum == targetSum) {
                found = true;
                 cout << "Подмассив с индексами: [" << start << ", " << end << "] -> ";
                for (int i = start; i <= end; ++i) {
                     cout << arr[i] << " ";
                }
                 cout <<  endl;
            }
        }
    }

    if (!found) {
         cout << "Подмассивы с заданной суммой не найдены." <<  endl;
    }
}