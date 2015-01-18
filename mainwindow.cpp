#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "logic.h"

#include <QHash>
#include <QDebug>
#include <QtGUI>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sceneField = new QGraphicsScene(this);
    sceneField->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->field->setScene(sceneField);

    scenePreview = new QGraphicsScene(this);
    ui->preview->setScene(scenePreview);

    //Category List (Main Parent)
    categoryModel = new QStringListModel(this);
    //
    QStringList categoryList;
    categoryList << "Plastic" << "Rubber" << "Ice";
    categoryModel->setStringList(categoryList);
    //
    ui->categoryList->setModel(categoryModel);
    ui->categoryList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->categoryList->setSelectionMode((QAbstractItemView::SingleSelection));
    //
    connect(ui->categoryList, SIGNAL(clicked(QModelIndex)), this, SLOT(categoryListHandler(QModelIndex)));
    //
    currentCat = plastic;
    currentMap = &objectPlasticMap;

    //Object List (category child)
    plasticObjectModel = new QStringListModel(this);
    rubberObjectModel = new QStringListModel(this);
    iceObjectModel = new QStringListModel(this);
    //
    QStringList plasticList, rubberList, iceList;
    plasticList << "Plastic Ball" << "Plastic Box" << "Plastic Triangle";
    rubberList << "Rubber Ball" << "Rubber Box" << "Rubber Triangle";
    iceList << "Ice Ball" << "Ice Box" << "Ice Triangle";
    //
    plasticObjectModel->setStringList(plasticList);
    rubberObjectModel->setStringList(rubberList);
    iceObjectModel->setStringList(iceList);
    //
    categoryMap.insert(plastic,plasticObjectModel);
    categoryMap.insert(rubber,rubberObjectModel);
    categoryMap.insert(ice,iceObjectModel);
    //
    ui->objectList->setModel(categoryMap.value(currentCat));
    ui->objectList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->objectList->setSelectionMode(QAbstractItemView::SingleSelection);
    //
    connect(ui->objectList, SIGNAL(clicked(QModelIndex)), this, SLOT(objectListHandler(QModelIndex)));


    Ball* h;
    objectPlasticMap.insert(plastic, h);
    objectRubberMap.insert(rubber, h);
    objectIceMap.insert(ice, h);


    /**
      *Ignore
      */
    //Ball *ball = new Ball(30,30,Qt::red,20,0,false);
    //scene->addItem(ball);



    //ui->field->setCacheMode(QGraphicsView::CacheBackground);
    //ui->field->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //ui->field->setDragMode(QGraphicsView::ScrollHandDrag);


}

void MainWindow::objectListHandler(const QModelIndex &index){
//    QListView* view = qobject_cast<QListView* >(sender());
    int item = index.row();
    qDebug() <<  "category " << item;

/*
    switch(item){
    case b: addItem(ballObj);
                break;
    }
*/

}

void MainWindow::categoryListHandler(const QModelIndex &index){
    int item = index.row();
    qDebug() <<  "category " << item;

    switch(item){
    case plastic: currentCat = plastic;
        currentMap = &objectPlasticMap;
        break;
    case rubber: currentCat = rubber;
        currentMap = &objectRubberMap;
        break;
    case ice: currentCat = ice;
        currentMap = &objectIceMap;
        break;
    }

    ui->objectList->setModel(categoryMap.value(currentCat));
}
MainWindow::~MainWindow()
{
    delete ui;
}
