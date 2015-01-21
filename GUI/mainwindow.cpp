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
 * @brief MainWindow::MainWindow Instantiates UI elements
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Initializaes the UI
    ui->setupUi(this); 

    //Creates a new QGraphicsScene from the custom field scene
    sceneField = new fieldScene;
    ui->field->setScene(sceneField);
    ui->field->setAcceptDrops(true);
    //Disables the scrolling effect caused by expanding a scene larger than the view
    ui->field->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->field->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //Creates a preview scene from the custom overrid class
    scenePreview = new previewScene(this);
    //This changes how the view is updated. This allows for better handling of multiple moving items
    ui->preview->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->preview->setScene(scenePreview);
    ui->preview->fitInView(scenePreview->sceneRect(), Qt::KeepAspectRatio);
    ui->preview->setTransform(QTransform());

    //Category List (Main Parent)
    categoryModel = new QStringListModel(this);
    //Creates the category list and sets it as the model
    QStringList categoryList;
    categoryList << "Plastic" << "Rubber" << "Ice";
    categoryModel->setStringList(categoryList);
    //Implements the model on to the UI. disables edit, and allows only one selection
    ui->categoryList->setModel(categoryModel);
    ui->categoryList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->categoryList->setSelectionMode((QAbstractItemView::SingleSelection));
    //Action listener for the category list
    connect(ui->categoryList, SIGNAL(clicked(QModelIndex)),
            this, SLOT(categoryListHandler(QModelIndex)));
    //Temp value to allow global access to the current selected category
    currentCat = logic::plasticCat;

    //Object List (category child)
    plasticObjectModel = new QStringListModel(this);
    rubberObjectModel = new QStringListModel(this);
    iceObjectModel = new QStringListModel(this);
    //Mutiple lists for each category
    QStringList plasticList, rubberList, iceList;
    plasticList << "Plastic Ball" << "Plastic Box" << "Plastic Triangle";
    rubberList << "Rubber Ball" << "Rubber Box" << "Rubber Triangle";
    iceList << "Ice Ball" << "Ice Box" << "Ice Triangle";
    //Sets each model
    plasticObjectModel->setStringList(plasticList);
    rubberObjectModel->setStringList(rubberList);
    iceObjectModel->setStringList(iceList);
    //Inserts the models into a hash
    categoryMap.insert(logic::plasticCat,plasticObjectModel);
    categoryMap.insert(logic::rubberCat,rubberObjectModel);
    categoryMap.insert(logic::iceCat,iceObjectModel);
    //Sets the model from the hash based on the current category
    ui->objectList->setModel(categoryMap.value(currentCat));
    ui->objectList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->objectList->setSelectionMode(QAbstractItemView::SingleSelection);
    //Action listener for the items selection
    connect(ui->objectList, SIGNAL(clicked(QModelIndex)),
            this, SLOT(objectListHandler(QModelIndex)));

}

/**
 * @brief MainWindow::objectListHandler Handles events from the item list
 * @param index
 */
void MainWindow::objectListHandler(const QModelIndex &index){
    //Gets the row selected from the list
    int item = index.row();

    //Removes all current items from the preview scene
    qDeleteAll(scenePreview->items());
    scenePreview->clear();
    scenePreview->setSceneRect(0,0,0,0);

    //Adds the correct item depending on the category.
    switch(currentCat){
    case logic::plasticCat: addPlasticItem(item);
                break;
    case logic::rubberCat: addRubberItem(item);
        break;
    case logic::iceCat: addIceItem(item);
        break;
    }

}

/**
 * @brief MainWindow::categoryListHandler Handles the event from the category list
 * @param index
 */
void MainWindow::categoryListHandler(const QModelIndex &index){
    int item = index.row();

    //Sets the category based on the selection
    switch(item){
    case logic::plasticCat: currentCat = item;
        break;
    case logic::rubberCat: currentCat = item;
        break;
    case logic::iceCat: currentCat = item;
        break;
    }

    //Sets the model to the current selected category
    ui->objectList->setModel(categoryMap.value(currentCat));
}

/**
 * @brief MainWindow::addPlasticItem Adds item from  the Plastic list
 * @details The only function implemented right now is the ball item for
 * debugging purposes
 * @param item
 */
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

/**
 * @brief MainWindow::addRubberItem Similar to the plastic list
 * @param item
 */
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

/**
 * @brief MainWindow::addIceItem Similar to the rubber list
 * @param item
 */
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
