#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ball.h"
#include "logic.h"
#include <QtGUI>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->field->setScene(scene);
    //scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    Ball *ball = new Ball();
    scene->addItem(ball);



    //ui->field->setCacheMode(QGraphicsView::CacheBackground);
    //ui->field->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //ui->field->setDragMode(QGraphicsView::ScrollHandDrag);


}

MainWindow::~MainWindow()
{
    delete ui;
}
