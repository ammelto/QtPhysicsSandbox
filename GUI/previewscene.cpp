#include "previewscene.h"

previewScene::previewScene(QObject *parent)
{
    Q_UNUSED(parent);
    this->setItemIndexMethod(QGraphicsScene::NoIndex);
}

previewScene::~previewScene()
{

}

