#ifndef FIELDSCENE_H
#define FIELDSCENE_H
#include <QtGUI>
#include <QtWidgets>


class fieldScene : public QGraphicsScene
{
public:
    fieldScene();
    ~fieldScene();
protected:
    virtual void fieldScene::dropEvent(QGraphicsSceneDragDropEvent * event);
    virtual void fieldScene::dragEnterEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void fieldScene::dragLeaveEvent ( QGraphicsSceneDragDropEvent * event );
    virtual void fieldScene::dragMoveEvent(QGraphicsSceneDragDropEvent *event);
};

#endif // FIELDSCENE_H
