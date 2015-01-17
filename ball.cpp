#include "ball.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

#include <math.h>

Ball::Ball(qreal grams, qreal cm, QColor c, qreal pascals, qreal cof, bool mag)
    :mass(grams), radius(cm), color(c), elasticity(pascals), friction(cof),
     magnetic(mag)
{
    setFlag(ItemIsMovable);
    setCursor(Qt::OpenHandCursor);
}

QRectF Ball::boundingRect() const{
    return QRectF(radius +0.25 , radius + 0.25 ,
                  radius *2 +0.5, radius *2 +0.5);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

Ball::~Ball()
{

}

