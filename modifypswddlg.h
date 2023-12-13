#ifndef MODIFYPSWDDLG_H
#define MODIFYPSWDDLG_H

#include <QDialog>

namespace Ui
{
class ModifyPswdDlg;
}

class ModifyPswdDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyPswdDlg(QWidget *parent = nullptr);
    ~ModifyPswdDlg();

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ModifyPswdDlg *ui;
};

#endif   // MODIFYPSWDDLG_H
