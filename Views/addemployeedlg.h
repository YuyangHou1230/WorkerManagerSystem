#ifndef ADDEMPLOYEEDLG_H
#define ADDEMPLOYEEDLG_H

#include <QDialog>

namespace Ui {
    class AddEmployeeDlg;
}

class AddEmployeeDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmployeeDlg(QWidget *parent = nullptr);
    ~AddEmployeeDlg();

private:
    Ui::AddEmployeeDlg *ui;
};

#endif // ADDEMPLOYEEDLG_H
