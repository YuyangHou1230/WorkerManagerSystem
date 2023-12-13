#include "loginform.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginForm  form;
    MainWindow w;
    form.show();

    QObject::connect(&form, &LoginForm::loginSuccess, &w, &MainWindow::showMaximized);
    QObject::connect(&form, &LoginForm::loginSuccess, &form, &LoginForm::hide);
    QObject::connect(&w, &MainWindow::loginOut, &form, &LoginForm::show);
    QObject::connect(&w, &MainWindow::loginOut, &w, &MainWindow::hide);

    return a.exec();
}
