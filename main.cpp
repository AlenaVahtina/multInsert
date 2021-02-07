#include <QCoreApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include "filereader.h"



bool connectDB(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions("host=localhost port=5432 dbname=test_db user=test password=test");
    return db.open();
}

void insertFromFile(QList <QString> atribute, QList <QString> value){
    QSqlQuery query;
    QStringList text4;
    for (int i=0; i<atribute.size();i++){
        text4.append("?");
    }
    QString text1="INSERT INTO mail(" + atribute.join(",") + ") VALUES (" + text4.join(",") + ")";
    qDebug()<<text1;
    query.prepare(text1);
    for (int i=0; i<atribute.size();i++){

        query.addBindValue(value[i]);
    }
    if(!query.exec())
            {
                qWarning() << strerror(errno);
                qWarning() << query.lastError();
                qWarning() << "Unable to create table. Query failed:";
                qWarning() << query.executedQuery();
                return;
            }
    return;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (connectDB()){
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
    QList <QStringList> testInsert;
    QString filename="test.csv";
    fileReader testFile;
    testFile.openFile(filename);
    testInsert = testFile.readFromFile();

    test2 ={"id","address","subject","text"};
    for (int i=0; i<testInsert.size();i++){
        insertFromFile(test2, testInsert[i]);
    }
    return a.exec();
}
