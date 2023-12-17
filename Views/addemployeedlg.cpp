#include "addemployeedlg.h"
#include "ui_addemployeedlg.h"

#include "DataBase/workermanagerdb.h"

#include "defs.h"

AddEmployeeDlg::AddEmployeeDlg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddEmployeeDlg)
{
    ui->setupUi(this);

    ui->labAvatar->init();
}

AddEmployeeDlg::~AddEmployeeDlg()
{
    delete ui;
}

void AddEmployeeDlg::on_btnOk_clicked()
{
    Employee employee;

    employee.avatarData = ui->labAvatar->getData();
    employee.name = ui->editName->text();
    employee.age = ui->spinBox->value();
    employee.number = ui->editPhone->text();
    employee.gender = Employee::Gender(ui->comboBox->currentIndex());

    CustomDB::WorkerManagerDB &db = Singleton<CustomDB::WorkerManagerDB>::getInstance();

}

void AddEmployeeDlg::on_btnCancel_clicked()
{
    reject();
}
