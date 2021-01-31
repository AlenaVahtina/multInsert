#include "filereader.h"

fileReader::fileReader()
{

}

void fileReader::openFile(QString fileName){
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }
    return;
}


QStringList fileReader::readFromFile(QFile file){
    QStringList wordList;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        wordList.append(line.split(',').first());
    }
    qDebug() << wordList;
    return wordList;
}
