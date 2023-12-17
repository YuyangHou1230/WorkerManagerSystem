#ifndef DEFS_H
#define DEFS_H

#include <QDateTime>
#include <QString>
#include <QWidget>

enum class SubWidgetType
{
    TypeWorkerManage,
};

struct WidgetData
{
    QString       name;
    SubWidgetType type;
    QWidget *     widget;

    WidgetData(QString _name, SubWidgetType _type, QWidget *_widget)
    {
        name   = _name;
        type   = _type;
        widget = _widget;
    }
};

// 职工
struct Employee
{
    enum Gender
    {
        Mail,
        Femail
    };
    enum Position
    {
        CEO,
        Manager,
        HR,
        Normal
    };

    int        id;
    QString    name;
    int        age;
    QString    number;
    Gender     gender;
    QDate      birthDay;
    int        DepartMent;
    Position   position;
    int        Salary;
    QDate      hireDate;
    QByteArray avatarData;
};

namespace System
{

}

#endif   // DEFS_H
