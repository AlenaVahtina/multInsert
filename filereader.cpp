#include "filereader.h"



fileReader::fileReader()
{

}

void fileReader::openFile(QString fileName){
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Can't open file!";
        qDebug() << file.errorString();
        return;
    }
    return;
}


QList <QStringList> fileReader::readFromFile(){
    QList <QStringList> wordList;
    while (!file.atEnd()) {
        QString line = QString::fromUtf8(file.readLine().trimmed());
        wordList.append(line.split(','));
    }
    qDebug() << wordList;
    return wordList;
}
