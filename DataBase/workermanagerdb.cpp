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

    initTables(  QList<Table>() << userTable);
}

bool WorkerManagerDB::validateLogin(QString user, QString password)
{
    Key key = Key::KeyValue("user", user);
    Table table = queryPatters(QList<Key>() << key, userTable);
    if(table.getIsValid()){
        if(table.value("password") == password)
        {
            return true;
        }
    }

    return false;
}

void WorkerManagerDB::validateRegister(QString user, QString name)
{

}

}
