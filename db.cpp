#include "db.h"

db::db()
{
}

//QString HOST="localhost";
//QString PORT="5432";
//QString DBNAME="test_db";
//QString USER="test";
//QString PASSWORD="test";

bool db::connectDB(QString HOST,QString PORT,QString  DBNAME, QString USER, QString PASSWORD){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setConnectOptions("host="+HOST+"port="+PORT+"dbname="+DBNAME+"user="+USER+"password="+PASSWORD);
    return db.open();
}


void db::insertFromFile(QList <QString> atribute, QList <QString> value){
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
