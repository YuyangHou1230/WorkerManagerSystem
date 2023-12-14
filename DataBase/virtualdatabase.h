#ifndef VIRTUALDATABASE_H
#define VIRTUALDATABASE_H

#include "table.h"
#include <QSqlQuery>
#include <QSqlDatabase>

class VirtualDataBase
{
public:
    VirtualDataBase();

    virtual void initTables(QList<Table> tables);
    virtual Table queryPatters(QList<Key> keys, Table tableName);

private:
    void createTables(QStringList tableList, QSqlQuery &query, QString tabeName, QString sql);

protected:
    QSqlQuery m_query;
    QSqlDatabase m_db;

};

#endif // VIRTUALDATABASE_H
