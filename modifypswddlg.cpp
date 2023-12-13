#include "modifypswddlg.h"
#include "ui_modifypswddlg.h"

ModifyPswdDlg::ModifyPswdDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ModifyPswdDlg)
{
    ui->setupUi(this);

    setWindowTitle("修改密码");
}

ModifyPswdDlg::~ModifyPswdDlg()
{
    delete ui;
}

void ModifyPswdDlg::on_btnOk_clicked()
{
    accept();
}

void ModifyPswdDlg::on_btnCancel_clicked()
{
    reject();
}
