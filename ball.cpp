#include "ball.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

#include <math.h>

Ball::Ball()
    :mass(0), radius(0), color(Qt::black), elasticity(0), friction(0),
     magnetic(0)
{
    setFlag(ItemIsMovable);
    setCursor(Qt::OpenHandCursor);
}

QRectF Ball::boundingRect() const{
    return QRectF(radius +0.25 , radius + 0.25 ,
                  radius *2 +0.5, radius *2 +0.5);
}

void Ball::setProperties(int type){

}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

Ball::~Ball()
{

}

