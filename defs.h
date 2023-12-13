#ifndef DEFS_H
#define DEFS_H

#include <QString>
#include <QWidget>


enum class SubWidgetType
{
    TypeWorkerManage,
};

struct WidgetData
{
    QString name;
    SubWidgetType type;
    QWidget *widget;

    WidgetData(QString _name, SubWidgetType _type, QWidget *_widget)
    {
        name = _name;
        type = _type;
        widget = _widget;
    }
};

namespace System {





}

#endif // DEFS_H
