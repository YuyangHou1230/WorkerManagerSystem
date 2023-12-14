#ifndef WORKERMANAGERDB_H
#define WORKERMANAGERDB_H

#include "mysql.h"

namespace CustomDB
{
class WorkerManagerImpl
{
public:
    WorkerManagerImpl();

    // 登录
    virtual bool validateLogin(QString user, QString name) = 0;
    // 注册
    virtual void validateRegister(QString user, QString name) = 0;
};

class WorkerManagerDB : public WorkerManagerImpl, public Mysql
{
public:
    WorkerManagerDB();

    void initSystemTable();

    // WorkerManagerImpl interface
public:
    bool validateLogin(QString user, QString name);
    void validateRegister(QString user, QString name);

private:
    Table userTable;
};
}

#endif // WORKERMANAGERDB_H
