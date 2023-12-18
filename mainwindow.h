#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

    void addWidget(QString name, QWidget *widget);

signals:
    // 注销
    void loginOut();

private slots:
    void slotActionUserModifyPswd();
    void slotActionUserLoginOut();

private:
    Ui::MainWindow *ui;
};
#endif   // MAINWINDOW_H
