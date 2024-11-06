#include <iostream>
#include "task_1.h"


int main() { 
    std::string corruptedXML; 
    std::getline(std::cin, corruptedXML); 
     
    std::string fixedXML = fixXML(corruptedXML); 
     
    if (fixedXML.empty()) { 
        std::cout << "Unable to fix XML" << std::endl; 
    } else { 
        std::cout << "Fixed XML: " << fixedXML << std::endl; 
    } 
     
    return 0; 
}