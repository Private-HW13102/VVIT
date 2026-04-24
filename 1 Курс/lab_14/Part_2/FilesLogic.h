#ifndef FILESLOGIC_H
#define FILESLOGIC_H

#include <QString>

// GUI part logic: analyze file line by line for max character sequence (summed)
int analyzeFileSequences(const QString &inPath, QChar target);

#endif
