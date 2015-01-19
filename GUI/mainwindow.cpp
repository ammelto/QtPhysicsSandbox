#include "..\GUI\mainwindow.h"
#include "ui_mainwindow.h"
#include "..\Items\ball.h"
#include "..\logic.h"
#include "..\GUI\fieldscene.h"
#include "..\GUI\previewscene.h"

#include <QHash>
#include <QDebug>
#include <QtGUI>
#include <QtWidgets>

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); 

    sceneField = new fieldScene;
    ui->field->setScene(sceneField);
    ui->field->setAcceptDrops(true);
    ui->field->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->field->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scenePreview = new previewScene(this);
    ui->preview->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->preview->setScene(scenePreview);
    ui->preview->fitInView(scenePreview->sceneRect(), Qt::KeepAspectRatio);
    ui->preview->setTransform(QTransform());

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
    connect(ui->categoryList, SIGNAL(clicked(QModelIndex)),
            this, SLOT(categoryListHandler(QModelIndex)));
    //
    currentCat = logic::plasticCat;

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
    categoryMap.insert(logic::plasticCat,plasticObjectModel);
    categoryMap.insert(logic::rubberCat,rubberObjectModel);
    categoryMap.insert(logic::iceCat,iceObjectModel);
    //
    ui->objectList->setModel(categoryMap.value(currentCat));
    ui->objectList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->objectList->setSelectionMode(QAbstractItemView::SingleSelection);
    //
    connect(ui->objectList, SIGNAL(clicked(QModelIndex)),
            this, SLOT(objectListHandler(QModelIndex)));

}

void MainWindow::objectListHandler(const QModelIndex &index){
//    QListView* view = qobject_cast<QListView* >(sender());
    int item = index.row();
    qDebug() <<  "category " << item;
    qDeleteAll(scenePreview->items());
    scenePreview->clear();
    scenePreview->setSceneRect(0,0,0,0);

    switch(currentCat){
    case logic::plasticCat: addPlasticItem(item);
                break;
    case logic::rubberCat: addRubberItem(item);
        break;
    case logic::iceCat: addIceItem(item);
        break;
    }

}

void MainWindow::categoryListHandler(const QModelIndex &index){
    int item = index.row();
    qDebug() <<  "category " << item;

    switch(item){
    case logic::plasticCat: currentCat = item;
        break;
    case logic::rubberCat: currentCat = item;
        break;
    case logic::iceCat: currentCat = item;
        break;
    }

    ui->objectList->setModel(categoryMap.value(currentCat));
}

void MainWindow::addPlasticItem(int item){

    switch(item){
    case pBall:{
        Ball *b = new Ball(logic::plasticCat);
        scenePreview->addItem(b);
        break;
    }
    case pBox:
        break;
    case pTriangle:
        break;
    }
}

void MainWindow::addRubberItem(int item){
    switch(item){
    case rBall:{
        Ball *b = new Ball(logic::rubberCat);
        scenePreview->addItem(b);
        break;
    }
    case rBox:
        break;
    case rTriangle:
        break;
    }
}

void MainWindow::addIceItem(int item){
    switch(item){
    case iBall:{
        Ball *b = new Ball(logic::iceCat);
        scenePreview->addItem(b);
        break;
    }
    case iBox:
        break;
    case iTriangle:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
