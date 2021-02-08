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


std::vector<std::string> tokenize(const std::string& str,char delimiter) {
 std::vector<std::string> tokens;

 unsigned int pos = 0;
 bool quotes = false;
 std::string field = "";

 while(str[pos] != 0x00 && pos < str.length()){
     char c = str[pos];
     if (!quotes && c == '"' ){
         quotes = true;
     } else if (quotes && c== '"' ){
         if (pos + 1 <str.length() && str[pos+1]== '"' ){
            field.push_back(c);
            pos++;
        } else {
            quotes = false;
        }
    } else if (!quotes && c == delimiter) {
        tokens.push_back(std::string(field));
        field.clear();
    } else if (!quotes && ( c == 0x0A || c == 0x0D )){
        tokens.push_back(std::string(field));
        field.clear();
    } else {
         field.push_back(c);
    }
    pos++;
 }
 return tokens;
}

QList <QStringList> fileReader::readFromFile(QChar delimiter){
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
        wordList.append(str);
    }
    qDebug() << wordList;
    return wordList;
}
