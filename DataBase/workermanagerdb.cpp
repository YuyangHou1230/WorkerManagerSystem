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
    QList<Key> keys;
    keys.append(Key("id", INTEGER));
    keys.append(Key("user", VARCHAR));
    keys.append(Key("password", VARCHAR));

    userTable = Table::createTable("users", keys, 0);

    initTables(QList<Table>() << userTable);
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

}   // namespace CustomDB
