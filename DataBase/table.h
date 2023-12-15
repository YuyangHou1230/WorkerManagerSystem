#ifndef TABLE_H
#define TABLE_H

#include <QList>
#include <QString>
#include <QVariant>

enum KeyType
{
    VARCHAR,
    INTEGER,
    DATE,
};

struct Key
{
    KeyType  type;
    QString  name;
    QVariant value;
    Key()
    {
    }

    Key(QString _name, KeyType _type)
    {
        type = _type;
        name = _name;
    }

    static Key KeyValue(QString _name, QVariant value)
    {
        Key key;
        key.name  = _name;
        key.value = value;

        return key;
    }
};

class Table
{
public:
    friend class VirtualDataBase;
    Table();
    Table(QString name, QList<Key> keys, int primaryIndex);

    static Table createTable(QString name, QList<Key> keys, int primaryIndex = -1);

    QVariant value(QString keyName);

    QString name();
    QString getCreateSql();

    bool getIsValid() const;

    QList<Key> getKeys() const;

    bool getIsEmpty() const;

private:
    QString    m_name;
    QList<Key> m_keys;
    int        m_primaryIndex;

    bool isValid;
    bool isEmpty;
};

#endif   // TABLE_H
