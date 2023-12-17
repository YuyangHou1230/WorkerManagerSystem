#ifndef WORKERMANAGERDB_H
#define WORKERMANAGERDB_H

#include "mysql.h"
#include "Utility/singleton.h"
#include "defs.h"

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

    // 添加员工
    virtual bool addEmployee(const Employee &employee) = 0;
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

    bool addEmployee(const Employee &employee);

private:
    Table userTable;
    Table m_employeeTable;
};
}   // namespace CustomDB

#endif   // WORKERMANAGERDB_H
