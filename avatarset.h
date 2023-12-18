#ifndef AVATARSET_H
#define AVATARSET_H

#include <QLabel>

class AvatarSet : public QLabel
{
public:
    AvatarSet(QWidget *parent = nullptr);

    void init();

    QByteArray getData();





private:
    QByteArray pixmapToBinaryData(QPixmap pix);
protected:



    // QWidget interface
protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    void resizeEvent(QResizeEvent *e) override;




private:
    QLabel *tipLabel;

    QPixmap m_pixmap;

};

#endif // AVATARSET_H
