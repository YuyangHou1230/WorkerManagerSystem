#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui
{
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

signals:
    void loginSuccess(int role);

private slots:
    void on_btnLogin_clicked();

    void on_btnCancel_clicked();

private:
    Ui::LoginForm *ui;
};

#endif   // LOGINFORM_H
