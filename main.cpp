#include <QCoreApplication>
#include "filereader.h"
#include "db.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    db db1;
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
    QList <QStringList> testInsert;
    QString filename="test.csv";
    fileReader testFile;
    testFile.openFile(filename);
    testInsert = testFile.readFromFile(',');
    test2 ={"id","address","subject","text"};
    for (int i=0; i<testInsert.size();i++){
        db1.insertFromFile(test2, testInsert[i]);
    }
    return a.exec();
}
