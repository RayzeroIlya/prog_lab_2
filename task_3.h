#include <iostream>
#include <limits>
#include "set.h"
#include <sstream>

using namespace std;
int tasK_3() {
    Set<int>* nums = new Set<int>();
    cout << "Input set: ";
    string str_set;
    getline (cin,str_set);
    stringstream ss(str_set);

    while (getline(ss,str_set,' ')){
        nums->SETADD(stoi(str_set));
    }


    int n = nums->get_size();
    int totalSum = nums->sum();
    int minDifference = std::numeric_limits<int>::max();
    Set<int>* bestSubset1= new Set<int>();
    Set<int>* bestSubset2= new Set<int>();

    // Перебор всех возможных подмножеств
    for (int mask = 0; mask < (1 << n); ++mask) {
        Set<int>* subset1= new Set<int>();
        Set<int>* subset2= new Set<int>();
        int sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset1->SETADD(nums->AT_INDEX(i));
                sum1 += nums->AT_INDEX(i);
            } else {
                subset2->SETADD(nums->AT_INDEX(i));
                sum2 += nums->AT_INDEX(i);
            }
        }

        int difference = std::abs(sum1 - sum2);
        if (difference < minDifference) {
            minDifference = difference;
            bestSubset1 = subset1;
            bestSubset2 = subset2;
        }
    }
    // Вывод результатов

    bestSubset1->print();

    bestSubset2->print();

    std::cout << "Разница между суммами: " << minDifference << std::endl;

    return 0;
}