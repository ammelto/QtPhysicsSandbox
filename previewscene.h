#ifndef PREVIEWSCENE_H
#define PREVIEWSCENE_H
#include <QtGUI>
#include <QtWidgets>

class previewScene : public QGraphicsScene
{
public:
    previewScene(QObject *parent);
    ~previewScene();
};

#endif // PREVIEWSCENE_H
