#include "ballreal.h"
#include "..\logic.h"
#include "..\GUI\mainwindow.h"

#include <QtWidgets>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <math.h>

/**
 * @brief BallReal::BallReal Real ball with rendered physics
 * @param type remove this when preview/real model is implemented.
 */
BallReal::BallReal(int type)
    :mass(10), radius(10), color(Qt::red), elasticity(10), friction(10),
     magnetic(10)
{
    setProperties(type);
    setToolTip(QString("Drag this item to insert it."));
    setCursor(Qt::OpenHandCursor);
    this->setPos(50,50);
}

/**
 * @brief BallReal::boundingRect Bounding rectangle based on the radius
 * @return
 */
QRectF BallReal::boundingRect() const{
    return QRectF(radius + 0.25 , radius +0.25 ,
                  radius *2 +0.5, radius *2 +0.5);
}

/**
 * @brief BallReal::setProperties Sets the physical properties of the ball based on the type
 * @param type Determines the category of the generic object
 */
void BallReal::setProperties(int type){
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

/**
 * @brief BallReal::paint Draws the ball within the bounds of the bounding rect
 * @param painter
 */
void BallReal::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

BallReal::~BallReal()
{

}
