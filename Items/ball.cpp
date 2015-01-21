#include "ball.h"
#include "..\logic.h"
#include "..\GUI\mainwindow.h"

#include <QtWidgets>
#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>
#include <QDebug>
#include <math.h>

/**
 * @brief Ball::Ball Clone of ball real without physics, saves memory
 * @param type
 */
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

/**
 * @brief Ball::mouseMoveEvent This overrides the mouseMoveEvent in order to start a dragging action
 * @details This is the main difference between the preview and real class
 * @param event
 */
void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    //This compares the drag distance to the location where the button
    //was first pressed down. This causes some delay before the object starts
    //moving. As a result, it eliminates the jittery effect from the mouse's initial grasp
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }
    //Creates a new drag event
    QDrag * drag = new QDrag(event->widget());

    //Mime data is the data that is dropped off at the drag location
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);

    //Stores the current item as an array of bytes and
    //just plops it into the location of the drag release
    //!!!THIS IS REALLY UNSAFE. DO NOT IMPLEMENT THIS IN THE FIRST RELEASE!!!
    Ball *item = this;
    QByteArray byteArray(reinterpret_cast<char*>(&item),sizeof(Ball*));
    mime->setData("Ball", byteArray);

    //Creates a blank slate for the ghost image
    QPixmap pixmap(radius * 2.5, radius * 2.5);
    pixmap.fill(Qt::white);

    //Adjusts the ghost so that the image appears in the center of the canvas
    QPainter painter(&pixmap);
    painter.translate(-(radius * 0.75), -(radius * 0.75));
    //Removes jaggies
    painter.setRenderHint(QPainter::Antialiasing);
    paint(&painter, 0, 0);
    painter.end();

    //Sets the Qt::white to be transparent
    pixmap.setMask(pixmap.createHeuristicMask());

    //Sets this as the ghost image
    drag->setPixmap(pixmap);
    drag->setHotSpot(QPoint(radius, radius));

    //This executes the drag event.
    //Basically, the drag will continue to loop until the drag is dropped
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

