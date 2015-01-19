#include "ball.h"
#include "..\logic.h"
#include "..\GUI\mainwindow.h"

#include <QtWidgets>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <math.h>

Ball::Ball(int type)
    :mass(10), radius(10), color(Qt::red), elasticity(10), friction(10),
     magnetic(10)
{
    setProperties(type);
    setToolTip(QString("Drag this item to insert it."));
    setCursor(Qt::OpenHandCursor);
    this->setPos(50,50);
}

QRectF Ball::boundingRect() const{
    return QRectF(radius + 0.25 , radius +0.25 ,
                  radius *2 +0.5, radius *2 +0.5);
}

void Ball::setProperties(int type){
    switch(type){
    case logic::plasticCat:{
        mass = 10;
        radius = 50;
        color.operator =(Qt::gray);
        elasticity = 5;
        friction = 40;
        magnetic = 0;
        break;
    }
    case logic::rubberCat:{
        mass = 30;
        radius = 20;
        color.operator =(Qt::black);
        elasticity = 100;
        friction = 30;
        magnetic = 0;
        break;
    }
    case logic::iceCat:{
        mass = 40;
        radius = 40;
        color.operator =(Qt::white);
        elasticity = 0;
        friction = 0;
        magnetic = 0;
        break;
    }
    }
}

void Ball::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ClosedHandCursor);
}

void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }
    QDrag * drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);

    Ball *item = this;
    QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Ball*));
    mime->setData("Ball", byteArray);

    QPixmap pixmap(radius * 2.5, radius * 2.5);
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.translate(-(radius * 0.75), -(radius * 0.75));
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, 0, 0);
    painter.end();

    pixmap.setMask(pixmap.createHeuristicMask());

    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(radius, radius));

    drag->exec();
    setCursor(Qt::OpenHandCursor);
}

void Ball::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::OpenHandCursor);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

Ball::~Ball()
{

}

