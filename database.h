#ifndef DB_H
#define DB_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>


class DataBase : public QObject
{
public:
    DataBase(){};
    QString HOST;
    QString PORT;
    QString DBNAME;
    QString USER;
    QString PASSWORD;
    bool connectDB(QString HOST,QString PORT,QString  DBNAME, QString USER, QString PASSWORD);
    void insertFromFile(QList <QString> atribute,QList<QList<QVariant>> value);
    void insertFromFileold(QList <QString> atribute, QList<QString> value);
    QString selectParam(QString column, QString tableName);
};

#endif // DB_H
