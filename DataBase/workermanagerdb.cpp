#include "workermanagerdb.h"

namespace CustomDB
{
WorkerManagerImpl::WorkerManagerImpl()
{
}

WorkerManagerDB::WorkerManagerDB()
{
}

void WorkerManagerDB::initSystemTable()
{
    QList<Table> tables;

    // 用户表
    QList<Key> keys;
    keys.append(Key("id", INTEGER));
    keys.append(Key("user", VARCHAR));
    keys.append(Key("password", VARCHAR));

    userTable = Table::createTable("users", keys, 0);
    tables.append(userTable);


    // 员工表
    QList<Key> employeeKeys;
    employeeKeys.append(Key("id", INTEGER));
    employeeKeys.append(Key("name", VARCHAR));
    employeeKeys.append(Key("age", INTEGER));
    employeeKeys.append(Key("number", VARCHAR));
    employeeKeys.append(Key("gender", INTEGER));
    employeeKeys.append(Key("birthDay", INTEGER));
    employeeKeys.append(Key("avatar", BLOB));

    m_employeeTable = Table::createTable("employees", employeeKeys, 0);
    tables.append(m_employeeTable);

    initTables(tables);
}

WorkerManagerDB::LoginRet WorkerManagerDB::validateLogin(QString user, QString password)
{
    LoginRet ret = LoginQueryFailed;

    Key   key   = Key::KeyValue("user", user);
    Table table = queryPatters(QList<Key>() << key, userTable);
    if ( table.getIsValid() )
    {
        if ( !table.getIsEmpty() )
        {
            if ( table.value("password") == password )
            {
                ret = LoginSuccess;
            }
            else
            {
                ret = LoginErrorPswd;
            }
        }
        else
        {
            ret = LoginErrorUser;
        }
    }

    return ret;
}

void WorkerManagerDB::validateRegister(QString user, QString name)
{
}

bool WorkerManagerDB::addEmployee(const Employee &employee)
{
    bool ret  = false;

    // 开启事务

    // 操作用户表

    // 操作员工表

    // 提交事务


    return ret;
}

}   // namespace CustomDB
