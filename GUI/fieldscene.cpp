#include "fieldscene.h"
#include <QtDebug>
#include <QDrag>
#include <QMimeData>
#include "..\Items\ball.h"

fieldScene::fieldScene()
{
    this->setItemIndexMethod(QGraphicsScene::NoIndex);
    this->setSceneRect(0,0,600,540);
}

void fieldScene::dropEvent(QGraphicsSceneDragDropEvent *event){
    QByteArray byteArray = event->mimeData()->data("Ball");
    Ball *item = *reinterpret_cast<Ball**>(byteArray.data());
    addItem(item);

    qDebug() << "Drag Drop";
}

void fieldScene::dragEnterEvent ( QGraphicsSceneDragDropEvent *event )
{
    event->setAccepted(true);
    update();
    qDebug() << "drag enter";
}

void fieldScene::dragLeaveEvent ( QGraphicsSceneDragDropEvent *event )
{
    event->setAccepted(false);
    Q_UNUSED(event);
    update();
    qDebug() << "drag leave";
}

void fieldScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    event->setAccepted(true);
}

fieldScene::~fieldScene()
{

}

