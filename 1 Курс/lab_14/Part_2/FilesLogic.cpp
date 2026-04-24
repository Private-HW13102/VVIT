#include "FilesLogic.h"
#include <QFile>
#include <QTextStream>

int analyzeFileSequences(const QString& inPath, QChar target) {
    QFile inFile(inPath);
    if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text)) return -1;
    
    QTextStream in(&inFile);
    int totalSum = 0;
    
    auto findMax = [](const QString& text, QChar t) {
        int maxLen = 0;
        int curr = 0;
        for (QChar c : text) {
            if (c == t) { 
                curr++; 
                if (curr > maxLen) maxLen = curr; 
            } else {
                curr = 0;
            }
        }
        return maxLen;
    };
    
    while (!in.atEnd()) {
        totalSum += findMax(in.readLine(), target);
    }
    
    inFile.close();
    return totalSum;
}
