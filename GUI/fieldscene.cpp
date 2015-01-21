#include "fieldscene.h"
#include <QtDebug>
#include <QDrag>
#include <QMimeData>
#include "..\Items\ball.h"

/**
 * @brief fieldScene::fieldScene Custom scene to override drag and drop
 */
fieldScene::fieldScene()
{
    this->setItemIndexMethod(QGraphicsScene::NoIndex);
    this->setSceneRect(0,0,600,540);
}

/**
 * @brief fieldScene::dropEvent Gets the drop event and adds the item as a byte array
 * !!!THIS IS VERY UNSAFE AND MUST NOT BE IMPLEMENTED IN THE FIRST RELEASE!!!!
 * @param event
 */
void fieldScene::dropEvent(QGraphicsSceneDragDropEvent *event){
    QByteArray byteArray = event->mimeData()->data("Ball");
    Ball *item = *reinterpret_cast<Ball**>(byteArray.data());
    addItem(item);

    qDebug() << "Drag Drop";
}

/**
 * @brief fieldScene::dragEnterEvent All drag and drop events must be overridden to accept drop events
 * @param event
 */
void fieldScene::dragEnterEvent ( QGraphicsSceneDragDropEvent *event )
{
    event->setAccepted(true);
    update();
    qDebug() << "drag enter";
}

/**
 * @brief fieldScene::dragLeaveEvent
 * @param event
 */
void fieldScene::dragLeaveEvent ( QGraphicsSceneDragDropEvent *event )
{
    event->setAccepted(false);
    Q_UNUSED(event);
    update();
    qDebug() << "drag leave";
}

/**
 * @brief fieldScene::dragMoveEvent All drag and drop events must be overridden to accept drop events
 * @param event
 */
void fieldScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    event->setAccepted(true);
}

fieldScene::~fieldScene()
{

}

