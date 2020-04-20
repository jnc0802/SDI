#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QGraphicsView>
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QGraphicsRectItem>
#include "headers/shapes.h"


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
    void on_FileBtn_clicked();


    void on_FileList_clicked(const QModelIndex &index);

    void on_SortAlpha_clicked();

    void on_DrawBtn_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *file;
    QGraphicsScene *scene;
    Shapes *rectangle;
};

#endif // MAINWINDOW_H
