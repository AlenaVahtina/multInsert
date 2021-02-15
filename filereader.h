#ifndef FILEREADER_H
#define FILEREADER_H

#include <QDebug>
#include <QFile>
#include <QStringList>


class FileReader
{
public:
    FileReader(){};
    QFile file;
    void openFile(QString fileName);
    QList <QStringList> readFromFile(QChar delimiter, QList<QList<QVariant>> &testInsert);
};

#endif // FILEREADER_H
