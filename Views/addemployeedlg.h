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

private slots:

    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::AddEmployeeDlg *ui;
};

#endif // ADDEMPLOYEEDLG_H
