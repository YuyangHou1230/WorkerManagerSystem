#include "mysql.h"

#include <QDebug>
#include <QSqlError>

namespace CustomDB {


Mysql::Mysql()
{

}

Mysql::~Mysql()
{
    m_db.close();
}

void Mysql::setDBParams(QString ip, int port, QString name, QString username, QString password)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL"); // 使用mysql数据库驱动
    m_db.setDatabaseName(name);
    m_db.setHostName(ip);
    m_db.setPort(port);
    m_db.setUserName(username);
    m_db.setPassword(password);
}

bool CustomDB::Mysql::connect()
{
    bool ret = m_db.open();
    if(!ret)
    {
        qDebug() << m_db.lastError().text();
    }
    return ret;
}

void CustomDB::Mysql::disConnect()
{
    m_db.close();
}

}
