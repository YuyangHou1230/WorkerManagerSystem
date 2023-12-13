#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "modifypswddlg.h"

#include <QDateTime>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        ui->labDate->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    });
    timer->setInterval(1000);
    timer->start();

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    QMenu *menu = new QMenu("");

    QAction *actionUserModifyPswd = new QAction("修改密码");
    connect(actionUserModifyPswd, &QAction::triggered, this, &MainWindow::slotActionUserModifyPswd);
    QAction *actionUserLoginOut = new QAction("注销");
    connect(actionUserLoginOut, &QAction::triggered, this, &MainWindow::slotActionUserLoginOut);

    menu->addAction(actionUserModifyPswd);
    menu->addAction(actionUserLoginOut);
    ui->btnUser->setMenu(menu);
}

void MainWindow::slotActionUserModifyPswd()
{
    ModifyPswdDlg dlg(this);
    dlg.exec();
}

void MainWindow::slotActionUserLoginOut()
{
    // 添加用户确定选项
    QMessageBox::StandardButton btn = QMessageBox::question(this, "提示", "确定要注销吗？");
    if ( btn != QMessageBox::Yes )
    {
        return;
    }

    emit loginOut();
}
