#ifndef FILEREADER_H
#define FILEREADER_H

#include <QDebug>
#include <QFile>
#include <QStringList>


class fileReader
{
public:
    fileReader();
    void openFile(QString fileName);
    QStringList readFromFile(QFile file);
};

#endif // FILEREADER_H
