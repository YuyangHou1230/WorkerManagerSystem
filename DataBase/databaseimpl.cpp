#include "databaseimpl.h"

#include <QCryptographicHash>
#include <QDebug>
#include <QSqlError>

namespace CustomDB {



DataBaseImpl::DataBaseImpl()
{

}

DataBaseImpl::~DataBaseImpl()
{

}

void DataBaseImpl::initTables()
{
    if(!m_db.isValid()){
        return;
    }


    // 创建书籍表
    QString createBooksTableQuery = "CREATE TABLE Books ("
                                    "book_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "title VARCHAR UNIQUE, "
                                    "author VARCHAR, "
                                    "publisher VARCHAR, "
                                    "isbn VARCHAR, "
                                    "publication_date DATE, "
                                    "edition VARCHAR, "
                                    "language VARCHAR, "
                                    "quantity INTEGER)";
    // 创建用户表
    QString createUsersTableQuery = "CREATE TABLE Users ("
                                    "user_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "username VARCHAR UNIQUE, "
                                    "password VARCHAR, "
                                    "full_name VARCHAR, "
                                    "email VARCHAR, "
                                    "phone VARCHAR, "
                                    "address VARCHAR, "
                                    "role VARCHAR)";

    // 创建借阅记录表
    QString createLoansTableQuery = "CREATE TABLE Loans ("
                                    "loan_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                    "user_id INTEGER, "
                                    "book_id INTEGER, "
                                    "borrow_date DATE, "
                                    "return_date DATE, "
                                    "status VARCHAR, "
                                    "FOREIGN KEY (user_id) REFERENCES Users(user_id), "
                                    "FOREIGN KEY (book_id) REFERENCES Books(book_id))";



    // 初始化表
    qDebug() << "initial tables";
    QStringList tableList = m_db.tables();

    createTables(tableList, m_query, "Books", createBooksTableQuery);
    createTables(tableList, m_query, "Users", createUsersTableQuery);
    createTables(tableList, m_query, "Loans", createLoansTableQuery);

    qDebug() << "initial tables end!";
}


QString hashPassword(const QString& password)
{
    // 将密码转换为UTF-8编码的字节数组
    QByteArray passwordBytes = password.toUtf8();

    // 使用SHA-256算法进行哈希散列
    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(passwordBytes);


    // 获取哈希结果，并以十六进制字符串形式返回
    QByteArray hashedPasswordBytes = hash.result();
    QString hashedPassword = QString(hashedPasswordBytes.toHex());

    return hashedPassword;
}

bool DataBaseImpl::registerUser(const QString &username, const QString &password, const QString &email, const QString &address)
{
    // 执行插入操作将新用户添加到数据库
    m_query.prepare("INSERT INTO Users (username, password, email, address ) "
                     "VALUES (:username, :password, :email, :address )");
    m_query.bindValue(":username", username);
    m_query.bindValue(":password", hashPassword(password));
    m_query.bindValue(":email", email);
    m_query.bindValue(":address", address);

    if (m_query.exec()) {
        qDebug() << "User registered successfully.";
        return true;
    } else {
        qDebug() << "Error registering user:" << m_query.lastError().text();
        return false;
    }
}


DataBaseImpl::LoginRet DataBaseImpl::login(const QString &username, const QString &password)
{
    LoginRet ret = LoginRet::NoUser;

    // 对密码进行加密
    QString hashPwsd = hashPassword(password);

    QString queryStr = QString("SELECT * FROM users WHERE username = '%1'").arg(username);
    QSqlQuery query(queryStr);

    if (query.exec()) {
        if (query.next()) {
            QString name = query.value("username").toString();
            QString pswd = query.value("password").toString();
            if(hashPwsd == pswd){
                ret = LoginRet::LoginSuccess;
            }
            else{
                ret = LoginRet::PasswordIncorrect;
            }
//            int age = query.value("age").toInt();
//            QString email = query.value("email").toString();
            // 处理查询结果
            // 可以使用name, age, email变量进行后续操作
        } else {
            // 未找到匹配的用户
            ret = LoginRet::NoUser;
        }
    } else {
        // 查询执行失败
        ret = SqlError;
    }

    return ret;
}


void DataBaseImpl::createTables(QStringList tableList, QSqlQuery &query, QString tabeName, QString sql)
{
    if(!tableList.contains(tabeName)){
        qDebug() << QString("%1表不存在，开始创建").arg(tabeName);
        bool ret = query.exec(sql);
        QString statusText = ret ? "成功" : "失败";
        qDebug() << QString("%1表创建%2").arg(tabeName).arg(statusText);
    }
}

}
