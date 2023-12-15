#include "addemployeedlg.h"
#include "ui_addemployeedlg.h"

#include "defs.h"

AddEmployeeDlg::AddEmployeeDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEmployeeDlg)
{
    ui->setupUi(this);
}

AddEmployeeDlg::~AddEmployeeDlg()
{
    delete ui;
}

void AddEmployeeDlg::on_btnOk_clicked()
{
    Employee employee;
}

void AddEmployeeDlg::on_btnCancel_clicked()
{
}
