#include <iostream>
#include "task_1.h"
#include "task_3.h"
using namespace std;
int main() { 

    /*//task1
    std::string corruptedXML = "<a> </a> <a> <ab> </ab> <c> </c> </a> <a> <aa> <a> </a> <a> </a>";
    std::string restoredXML = restoreXML(corruptedXML);
    std::cout << restoredXML << std::endl;
    //task1
    */



    Set<int> inputSet;
    inputSet.SETADD(5);
    inputSet.SETADD(8);
    inputSet.SETADD(1);
    inputSet.SETADD(14);
    inputSet.SETADD(7);

    findMinDifferenceSubsets(inputSet);

    return 0;
    
    
    return 0;
}