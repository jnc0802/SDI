#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/linkedlist.h"
#include <iostream>

LinkedList List;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_FileBtn_clicked()
{

    QFileInfo newFile = QFileDialog::getOpenFileName(
                this, tr("Choose a File"),
                "C://",
                "Img Files (*.jpg *.jpeg *.png *.gif)");
    List.insertNode(newFile.fileName(),newFile.absoluteFilePath());
    ui->FileList->addItem(newFile.fileName());
}



void MainWindow::on_FileList_clicked(const QModelIndex &index)
{
    QString fName = ui->FileList->currentItem()->text();
    QString path= List.fPath(fName);
    QImage img= QImage(path);
    scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(img));
    ui->ImgView->setScene(scene);
}

