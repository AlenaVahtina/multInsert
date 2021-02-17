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

    QList <QString> atribute;

    atribute ={"id","address","subject","text"};
    QList<QList<QVariant>> testInsert;
    for (int i=0; i<atribute.size(); i++){
        testInsert.append(QList<QVariant>());
    }
    QString filename="test.csv";
    FileReader testFile;
    testFile.openFile(filename);
    testFile.readFromFile(',', testInsert);

    db1.insertFromFile(atribute, testInsert);

    return a.exec();
}
