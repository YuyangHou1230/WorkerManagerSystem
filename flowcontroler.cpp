#include "flowcontroler.h"

#include "loginform.h"
#include "mainwindow.h"
#include "Utility/singleton.h"
#include "DataBase/mysql.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>

FlowControler::FlowControler()
{
}

int FlowControler::run(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool         logout = true;
    int          ret    = 0;

    // 数据库连接
    // 连接数据库
    CustomDB::Mysql &mysql = Singleton<CustomDB::Mysql>::getInstance();
    mysql.setDBParams("10.1.1.72", 3306, "WorkerManager", "root", "123456");
    if(!mysql.connect())
    {
        qCritical() << "数据库连接失败！";
        // 添加用户确定选项
        QMessageBox::StandardButton btn = QMessageBox::question( nullptr, "提示", "数据库连接失败，是否继续使用软件？");
        if ( btn != QMessageBox::Yes )
        {
            return 0;
        }
    }
    else{
        qInfo() << "数据库连接成功！";
    }

    // 使用循环完成注销功能,这样的好处是所有的对象都是重新创建，不需要自己去手动恢复主界面到初始状态
    while ( logout )
    {
        logout = false;

        LoginForm  form;
        MainWindow w;
        form.show();

        QObject::connect(&form, &LoginForm::loginSuccess, &w, &MainWindow::showMaximized);
        QObject::connect(&form, &LoginForm::loginSuccess, &form, &LoginForm::close);
        QObject::connect(&w, &MainWindow::loginOut, [&logout]() { logout = true; });
        QObject::connect(&w, &MainWindow::loginOut, &w, &MainWindow::close);

        ret = a.exec();

        if ( logout )
        {
            qDebug() << "用户注销";
        }
    }

    qDebug() << "程序退出";

    return ret;
}
