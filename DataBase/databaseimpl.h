#ifndef DATABASEIMPL_H
#define DATABASEIMPL_H

#include "defs.h"

#include <QObject>
#include <QSqlQuery>
#include <QSqlDatabase>

namespace CustomDB {

class DataBaseImpl
{

public:
    enum LoginRet
    {
        LoginSuccess,
        NoUser,
        PasswordIncorrect,
        SqlError
    };

    DataBaseImpl();
    ~DataBaseImpl();

    // 初始化表
    void initTables();

    virtual void queryUser(QString name){};
    virtual void allUser(){};
    bool registerUser(const QString& username, const QString& password, const QString& email, const QString& address);
    LoginRet login(const QString& username, const QString& password);

private:
    void createTables(QStringList tableList, QSqlQuery &query, QString tabeName, QString sql);

protected:
    QSqlQuery m_query;
    QSqlDatabase m_db;
};

}

#endif // DATABASEIMPL_H
