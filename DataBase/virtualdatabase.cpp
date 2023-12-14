#include "virtualdatabase.h"

#include <QDebug>
#include <QSqlError>

VirtualDataBase::VirtualDataBase()
{

}

void VirtualDataBase::initTables(QList<Table> tables)
{
    if(!m_db.isValid())
    {
        return;
    }
    if(!m_db.isOpen())
    {
        return;
    }

    // 初始化表
    qDebug() << "initial tables";
    QStringList tableList = m_db.tables(QSql::AllTables);

    for(auto p : tables)
    {
        createTables(tableList, m_query, p.name(), p.getCreateSql());
    }

    qDebug() << "initial tables end!";
}

Table VirtualDataBase::queryPatters(QList<Key> keys, Table table)
{
    Key key = keys.first();
    QString queryStr ;
    for(auto p : table.getKeys())
    {
        if(p.name == key.name)
        {
            key.type = p.type;
        }
    }

    switch (key.type) {
        case VARCHAR:
            queryStr = QString("SELECT * FROM %1 WHERE %2 = '%3'").arg(table.name()).arg(keys.first().name).arg(keys.first().value.toString());
            break;
        case INTEGER:
            queryStr = QString("SELECT * FROM %1 WHERE %2 = '%3'").arg(table.name()).arg(keys.first().name).arg(keys.first().value.toInt());
            break;
        case DATE:
            break;

    }

    Table ret;

    QSqlQuery query(queryStr);
    if (query.exec()) {
        if (query.next()) {
            ret = table;
            // 循环赋值
            for(int i=0; i < table.getKeys().size(); i++)
            {
                ret.m_keys[i].value = query.value(table.getKeys()[i].name);
            }
        }
    }

    return ret;
}

void VirtualDataBase::createTables(QStringList tableList, QSqlQuery &query, QString tabeName, QString sql)
{
    if(!tableList.contains(tabeName)){
        qDebug() << QString("%1表不存在，开始创建：%2").arg(tabeName).arg(sql);
        bool ret = query.exec(sql);
        QString statusText = ret ? "成功" : "失败";
        qDebug() << QString("%1表创建%2").arg(tabeName).arg(statusText);
        if(!ret)
        {
            qDebug() << query.lastError().text();
        }
    }
}
