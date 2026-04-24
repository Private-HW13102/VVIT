#include "Logic.h"

int findMaxSequence(const QString& text, QChar target) {
    int maxLen = 0;
    int currentLen = 0;
    
    for (int i = 0; i < text.length(); ++i) {
        if (text.at(i) == target) {
            currentLen++;
            if (currentLen > maxLen) maxLen = currentLen;
        } else {
            currentLen = 0;
        }
    }
    
    return maxLen;
}
