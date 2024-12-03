#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

bool isValidXML(const string& xml) {
    Stack< string> tags;
     string tag;
    size_t pos = 0;
    while ((pos = xml.find('<', pos)) !=  string::npos) {
        size_t endPos = xml.find('>', pos + 1);
        if (endPos ==  string::npos) return false; // Незакрытый тег

        tag = xml.substr(pos + 1, endPos - pos - 1);
        if (tag[0] == '/') {
            if (tags.isEmpty() || tags.peek() != tag.substr(1)) return false; // Несоответствие закрывающего тега
            tags.SPOP();
        } else {
            tags.SPUSH(tag);
        }
        pos = endPos + 1;
    }
    return tags.isEmpty();
}

 string restoreXML(const  string& damagedXML) {
     string originalXML = damagedXML;
    for (size_t i = 0; i < damagedXML.length(); ++i) {
        char originalChar = damagedXML[i];
        for (char replacement = 'a'; replacement <= 'z'; ++replacement) {
            originalXML[i] = replacement;
            if (isValidXML(originalXML)) return originalXML;
            
            // Проверяем символы <, >, /
            for (char special_char : {'<', '>', '/'}) {
                originalXML[i] = special_char;
                if (isValidXML(originalXML)) return originalXML;
            }

        }
        originalXML[i] = originalChar; // Восстанавливаем исходный символ после проверки замены

    }
    return damagedXML; // Возвращаем поврежденную строку, если восстановление не удалось
}