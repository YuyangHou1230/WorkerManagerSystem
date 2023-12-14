#include "table.h"


Table::Table()
{
    isValid = false;
}

Table::Table(QString name, QList<Key> keys, int primaryIndex)
{
    m_name = name;
    m_keys = keys;
    m_primaryIndex = primaryIndex;
    isValid = true;
}

Table Table::createTable(QString name, QList<Key> keys, int primaryIndex)
{
    Table table(name, keys, primaryIndex);
    return table;
}

QVariant Table::value(QString keyName)
{
    for(auto p: m_keys)
    {
        if(p.name == keyName)
        {
            return p.value;
        }
    }

    return QVariant();
}

QString Table::name()
{
    return m_name;
}

QString KeyTypeName(KeyType type)
{
    QString ret;
    switch (type) {
        case VARCHAR:
            ret = "VARCHAR(255)";
            break;
        case INTEGER:
            ret = "INTEGER";
            break;
        case DATE:
            ret = "DATE";
            break;

    }

    return ret;
}

QString Table::getCreateSql()
{
    QString sql;

    QString content;
    for(int i=0; i < m_keys.size(); i++)
    {
        Key key = m_keys[i];
        content += QString("%1 %2").arg(key.name).arg(KeyTypeName(key.type));
        if(i != m_keys.size() - 1)
        {
            content += ", ";
        }
    }

    sql = QString("CREATE TABLE %1 ( %2 )").arg(m_name).arg(content);

    return sql;
}

bool Table::getIsValid() const
{
    return isValid;
}

QList<Key> Table::getKeys() const
{
    return m_keys;
}
