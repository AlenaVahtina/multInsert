#include <QCoreApplication>
#include "filereader.h"
#include "database.h"
#include <QDateTime>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DataBase db1;
    if (db1.connectDB("localhost", "5432", "test_db", "test", "test")){
        qDebug()<<"Sucsess connect";
    }
    else{
        qDebug()<<"Can't connect";
    }
     QSqlQuery query("SELECT * FROM mail");
     while (query.next()) {
             QString test = query.value(0).toString();
             qDebug()<<test;
         }
    QList <QString> test2;

    test2 ={"id","address","subject","text"};
    QList<QList<QVariant>> testInsert;
    for (int i=0; i<test2.size(); i++){
        testInsert.append(QList<QVariant>());
    }
    QString filename="test.csv";

    QList<QStringList> old;
    for (int i=0; i<10000; i++){
        FileReader testFile;
        testFile.openFile(filename);
        old.append(testFile.readFromFile(',', testInsert));
    }
    QDateTime dateTime1 = QDateTime::currentDateTime();
    db1.insertFromFile(test2, testInsert);
    qDebug()<< dateTime1.msecsTo(QDateTime::currentDateTime());
    dateTime1 = QDateTime::currentDateTime();
    for (int i=0; i<old.size();i++){
        db1.insertFromFileold(test2, old[i]);
    }


    qDebug()<< dateTime1.msecsTo(QDateTime::currentDateTime());
    return a.exec();
}
