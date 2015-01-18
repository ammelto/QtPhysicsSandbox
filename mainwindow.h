#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGUI>
#include <QtCore>
#include <QHash>
#include "ball.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
        void objectListHandler(const QModelIndex &index);
        void categoryListHandler(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *sceneField;
    QGraphicsScene *scenePreview;
    QStringListModel *categoryModel;
    QStringListModel *iceObjectModel;
    QStringListModel *rubberObjectModel;
    QStringListModel *plasticObjectModel;

    int currentCat;
    QHash<int, QGraphicsItem*> *currentMap;
    enum categories{plastic,rubber,ice};
    QHash<int, QStringListModel*>categoryMap;

    QHash<int, QGraphicsItem*> objectPlasticMap;
    QHash<int, QGraphicsItem*> objectRubberMap;
    QHash<int, QGraphicsItem*> objectIceMap;
};

#endif // MAINWINDOW_H
