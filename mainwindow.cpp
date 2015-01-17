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
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->field->setScene(scene);
    Ball *ball = new Ball(30,30,Qt::red,20,0,false);
    scene->addItem(ball);



    //ui->field->setCacheMode(QGraphicsView::CacheBackground);
    //ui->field->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //ui->field->setDragMode(QGraphicsView::ScrollHandDrag);


}

MainWindow::~MainWindow()
{
    delete ui;
}
