#include "avatarset.h"

#include <QFileDialog>
#include <QApplication>
#include <QResizeEvent>
#include <QBuffer>

AvatarSet::AvatarSet(QWidget *parent) : QLabel(parent)
{
    tipLabel = new QLabel(this);
    tipLabel->setFixedHeight(30);
    tipLabel->setAlignment(Qt::AlignCenter);
    tipLabel->setText("点击上传");

    tipLabel->hide();

    setContentsMargins(0, 0, 0, 30);
}

void AvatarSet::init()
{
    QPixmap pixmap("F:\\Qt\\WorkerManagerSystem\\Icon\\avatar.png");
    m_pixmap = pixmap;
    setPixmap(pixmap);
}

QByteArray AvatarSet::getData()
{
    return pixmapToBinaryData(m_pixmap);
}

QByteArray AvatarSet::pixmapToBinaryData(QPixmap pix)
{
    QImage img = pix.toImage();

    QByteArray imageData;
    QBuffer buffer(&imageData);

    buffer.open(QIODevice::WriteOnly);
    img.save(&buffer, "png"); // 这里一定要指定格式， 否则会失败

    buffer.close();
    return imageData;
}

void AvatarSet::enterEvent(QEvent *event)
{
    tipLabel->show();
}

void AvatarSet::leaveEvent(QEvent *event)
{
    tipLabel->hide();
}

void AvatarSet::mousePressEvent(QMouseEvent *e)
{

}

void AvatarSet::mouseReleaseEvent(QMouseEvent *e)
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "选择头像", "F:\\Qt\\WorkerManagerSystem\\Icon", tr(""));
    if(fileName.isEmpty())
    {
        return;
    }

    m_pixmap = QPixmap(fileName);
    setPixmap(m_pixmap);
}

void AvatarSet::resizeEvent(QResizeEvent *e)
{
    tipLabel->setFixedWidth(e->size().width());
    tipLabel->move(0, e->size().height() - 30);

}
