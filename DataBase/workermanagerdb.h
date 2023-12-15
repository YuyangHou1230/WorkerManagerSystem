#ifndef WORKERMANAGERDB_H
#define WORKERMANAGERDB_H

#include "mysql.h"

namespace CustomDB
{
class WorkerManagerImpl
{
public:
    enum LoginRet
    {
        LoginSuccess,
        LoginErrorUser,
        LoginErrorPswd,
        LoginQueryFailed,
    };

    WorkerManagerImpl();

    // 登录
    virtual LoginRet validateLogin(QString user, QString name) = 0;
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
    LoginRet validateLogin(QString user, QString name);
    void     validateRegister(QString user, QString name);

private:
    Table userTable;
};
}   // namespace CustomDB

#endif   // WORKERMANAGERDB_H
