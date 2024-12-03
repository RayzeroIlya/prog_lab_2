#include <iostream>
#include "task_1.h"
#include "task_4.h"
using namespace std;
int main() { 

    /*//task1
    std::string corruptedXML = "<a> </a> <a> <ab> </ab> <c> </c> </a> <a> <aa> <a> </a> <a> </a>";
    std::string restoredXML = restoreXML(corruptedXML);
    std::cout << restoredXML << std::endl;
    //task1
    */



    const int n = 10; // Размер массива
    int arr[n] = {4, -7, 1, 5, -4, 0, -3, 2,4 ,1}; // Инициализация массива
    int targetSum = 5; // Целевая сумма

    findAllSubarraysWithSum(arr, n, targetSum);
    
    return 0;
}