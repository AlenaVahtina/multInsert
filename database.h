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
    void insertFromFile(QList <QString> atribute, QList <QString> value);
};

#endif // DB_H
