#include "ball.h"

#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

#include <math.h>

Ball::Ball()
{
    setFlag(ItemIsMovable);
}

QRectF Ball::boundingRect() const{
    return QRectF(0, 0,
                  100, 100);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(0,0,10,10);
}

QPainterPath Ball::shape() const {
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}


Ball::~Ball()
{

}
