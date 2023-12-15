#include "addemployeedlg.h"
#include "ui_addemployeedlg.h"

AddEmployeeDlg::AddEmployeeDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEmployeeDlg)
{
    ui->setupUi(this);
}

AddEmployeeDlg::~AddEmployeeDlg()
{
    delete ui;
}
