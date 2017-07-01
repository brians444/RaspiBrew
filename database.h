#ifndef DATABASE_H
#define DATABASE_H

#include <QDebug>
#include <QMessageBox>

#include <QString>
#include <QStringList>

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>

#include <QDateTime>

#include "definitions.h"

class DataBase
{

public:
    DataBase();
    void conectar();
    QStringList drivers();
    void crearDb();

    int conexion();

    bool addTemperatures(sensores values);
    QList<historic_record> getHistory(int fermentador, QDateTime f1, QDateTime f2);

private:
    int port;
    QString ip;
    QString user, pass;
    QString database;
    QString driv;

    QSqlDatabase db;
    QStringList datos;


};

#endif // DATABASE_H
