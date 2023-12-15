#include "loginform.h"
#include "ui_loginform.h"

#include "DataBase/workermanagerdb.h"
#include "Utility/singleton.h"

#include <QDebug>
#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);

    setWindowTitle("登录");

    // 禁用上下文帮助按钮
    Qt::WindowFlags flags = windowFlags();
    flags                 = flags & (~Qt::WindowContextHelpButtonHint);   // 移除上下文帮助按钮标志
    setWindowFlags(flags);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_btnLogin_clicked()
{
    // 有临时密码
    QString user = ui->editUser->text();
    QString pswd = ui->editPswd->text();

    // 基本的输入规则判断
    if ( user.isEmpty() )
    {
        // 登录失败提示
        QMessageBox::information(nullptr, "提示", "请输入用户名！");
        return;
    }
    if ( pswd.isEmpty() )
    {
        // 登录失败提示
        QMessageBox::information(nullptr, "提示", "请输入密码！");
        return;
    }

    // 先进行临时账号匹配
    if ( user == "admin" )
    {
        qDebug() << "user super account";
        if ( pswd == "admin" )
        {
            emit loginSuccess(0);
        }
        else
        {
            // 登录失败提示
            QMessageBox::information(nullptr, "提示", "登录失败，密码错误！");
        }
        return;
    }

    //数据库账号匹配
    CustomDB::WorkerManagerDB &db = Singleton<CustomDB::WorkerManagerDB>::getInstance();

    CustomDB::WorkerManagerDB::LoginRet ret = db.validateLogin(user, pswd);
    switch ( ret )
    {
    case CustomDB::WorkerManagerImpl::LoginSuccess:
        emit loginSuccess(0);
        break;
    case CustomDB::WorkerManagerImpl::LoginErrorUser:
        // 登录失败提示
        QMessageBox::information(nullptr, "提示", "用户名不存在");

        break;
    case CustomDB::WorkerManagerImpl::LoginErrorPswd:
        // 登录失败提示
        QMessageBox::information(nullptr, "提示", "密码错误！");
        break;
    case CustomDB::WorkerManagerImpl::LoginQueryFailed:
        // 登录失败提示
        QMessageBox::information(nullptr, "提示", "数据库查询失败！");
        break;
    }
}

void LoginForm::on_btnCancel_clicked()
{
    close();
}
