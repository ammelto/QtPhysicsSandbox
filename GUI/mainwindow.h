#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGUI>
#include <QtCore>
#include <QHash>
#include "..\Items\ball.h"
#include "..\GUI\fieldScene.h"
#include "..\GUI\previewscene.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:

private slots:
        void objectListHandler(const QModelIndex &index);
        void categoryListHandler(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    fieldScene *sceneField;
    previewScene *scenePreview;
    QStringListModel *categoryModel;
    QStringListModel *iceObjectModel;
    QStringListModel *rubberObjectModel;
    QStringListModel *plasticObjectModel;
    int currentCat;
    enum plastics{pBall, pBox, pTriangle};
    enum rubber{rBall, rBox, rTriangle};
    enum ice{iBall, iBox, iTriangle};
    QHash<int, QStringListModel*>categoryMap;

    void MainWindow::addPlasticItem(int item);
    void MainWindow::addRubberItem(int item);
    void MainWindow::addIceItem(int item);
};

#endif // MAINWINDOW_H
