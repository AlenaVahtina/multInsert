#include "filereader.h"


void FileReader::openFile(QString fileName){
    file.setFileName(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"Can't open file!";
        qDebug() << file.errorString();
        return;
    }
    return;
}


QList <QStringList> FileReader::readFromFile(QChar delimiter, QList<QList<QVariant>> &testInsert){
    QList <QStringList> wordList;

    while (!file.atEnd()) {
        QString line = QString::fromUtf8(file.readLine().trimmed());
        QStringList str;
        unsigned int pos = 0;
        bool quotes = false;
        QString field = "";
        while( pos < line.length()){
            QChar c = line[pos];
            if (!quotes && c == '"' ){
                quotes = true;
            } else if (quotes && c== '"' ){
                if (pos + 1 <line.length() && line[pos+1]== '"' ){
                   field.push_back(c);
                   pos++;
               } else {
                quotes = false;
                }
            } else if (!quotes && c == delimiter) {
                str.push_back(QString(field));
                field.clear();
            } else if (!quotes && ( c == 0x0A || c == 0x0D )){
                str.push_back(QString(field));
                field.clear();
            } else {
                    field.push_back(c);
               }
               pos++;
        }
        str.push_back(QString(field));
        for (int i=0; i<str.size(); i++){
            testInsert[i].append(str[i]);
        }
        wordList.append(str);
    }
    qDebug() << wordList;
    return wordList;
}
