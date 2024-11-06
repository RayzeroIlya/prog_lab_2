#include <iostream> 
#include "stack.h" 
#include <string> 
 
bool isValidXML(const std::string& xml) { 
    Stack<std::string> tags; 
    bool inTag = false; 
     
    for (int i = 0; i < xml.length(); ++i) { 
        if (xml[i] == '<') { 
            inTag = true; 
        } else if (xml[i] == '>') { 
            inTag = false; 
        } else if (!inTag) { 
            continue; 
        } else { 
            if (xml[i] == '/') { 
                if (tags.isEmpty()) { 
                    return false; 
                } 
                 
                std::string closingTag = tags.top(); 
                tags.SPOP(); 
                 
                if (closingTag != xml.substr(i + 1, closingTag.length())) { 
                    return false; 
                } 
                 
                i += closingTag.length(); 
            } else { 
                size_t tagEnd = xml.find('>', i); 
                 
                if (tagEnd == std::string::npos || tagEnd-i <= 1) { 
                    return false; 
                } 
                 
                tags.SPUSH(xml.substr(i + 1, tagEnd-i-1)); 
            } 
        } 
    } 
     
    return tags.isEmpty(); 
} 
 
std::string fixXML(const std::string& corruptedXML) { 
    for (int i = 0; i < corruptedXML.length(); ++i) { 
        std::string fixed = corruptedXML; 
         
        if (corruptedXML[i] == '<') { 
            if (corruptedXML[i + 1] == '/') { 
                fixed[i+1] = '>'; 
            } else { 
                fixed.insert(i, "/"); 
            } 
             
            if (isValidXML(fixed)) { 
                return fixed; 
            } 
        } 
    } 
     
    return ""; 
} 
 
