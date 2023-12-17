#include "employeemanagewidget.h"
#include "ui_employeemanagewidget.h"

#include "addemployeedlg.h"

EmployeeManageWidget::EmployeeManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeManageWidget)
{
    ui->setupUi(this);
}

EmployeeManageWidget::~EmployeeManageWidget()
{
    delete ui;
}

void EmployeeManageWidget::on_btnAddEmployee_clicked()
{
    AddEmployeeDlg dlg;
    dlg.exec();
}
