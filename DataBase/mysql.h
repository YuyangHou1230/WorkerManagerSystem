#ifndef MYSQL_H
#define MYSQL_H

#include "databaseimpl.h"

namespace CustomDB
{
class Mysql : public DataBaseImpl
{
public:
    Mysql();
    ~Mysql();
    void setDBParams(QString ip, int port, QString name, QString username, QString password);

    // 连接
    bool connect();

    void disConnect();

private:
    bool hasSetParams;
};

}   // namespace CustomDB

#endif   // MYSQL_H
