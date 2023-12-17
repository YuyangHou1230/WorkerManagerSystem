#ifndef EMPLOYEEMANAGEWIDGET_H
#define EMPLOYEEMANAGEWIDGET_H

#include <QWidget>

namespace Ui {
class EmployeeManageWidget;
}

class EmployeeManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeeManageWidget(QWidget *parent = nullptr);
    ~EmployeeManageWidget();

private slots:
    void on_btnAddEmployee_clicked();

private:
    Ui::EmployeeManageWidget *ui;
};

#endif // EMPLOYEEMANAGEWIDGET_H
