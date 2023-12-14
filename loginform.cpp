#include "loginform.h"
#include "ui_loginform.h"

#include "DataBase/workermanagerdb.h"
#include "Utility/singleton.h"

#include <QMessageBox>

LoginForm::LoginForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginForm)
{
    ui->setupUi(this);
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

    //数据库账号匹配
    CustomDB::WorkerManagerDB &db = Singleton<CustomDB::WorkerManagerDB>::getInstance();
    if(db.validateLogin(user, pswd)){
        emit loginSuccess(0);
    }

    // 匹配失败进行临时账号匹配
    else if(user == "admin" && pswd == "admin")
    {
        emit loginSuccess(0);
    }
    else{
        // 登录失败提示
        QMessageBox::information( nullptr, "提示", "登录失败，请检查用户名和密码是否正确！");
    }

}

void LoginForm::on_btnCancel_clicked()
{
    close();
}
