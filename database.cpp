#include "database.h"


bool DataBase::connectDB(QString HOST,QString PORT,QString  DBNAME, QString USER, QString PASSWORD){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setConnectOptions("host="+HOST+"port="+PORT+"dbname="+DBNAME+"user="+USER+"password="+PASSWORD);
    db.setHostName(HOST);
    db.setPort(PORT.toInt());
    db.setDatabaseName(DBNAME);
    db.setUserName(USER);
    db.setPassword(PASSWORD);
    return db.open();
}


void DataBase::insertFromFile(QList <QString> atribute, QList <QString> value){
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
