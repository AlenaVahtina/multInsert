#ifndef FILEREADER_H
#define FILEREADER_H

#include <QDebug>
#include <QFile>
#include <QStringList>


class fileReader
{
public:
    QFile file;
    fileReader();
    void openFile(QString fileName);
    QList <QStringList> readFromFile();
};

#endif // FILEREADER_H
