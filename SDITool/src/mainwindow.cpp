#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linkedlist.h"
#include <iostream>

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
    LinkedList List;
    QFileInfo newFile = QFileDialog::getOpenFileName(
                this, tr("Choose a File"),
                "C://",
                "Img Files (*.jpg *.jpeg *.png *.gif)");
    List.InsertNode(0,newFile);
    ui->FileList->addItem(newFile.fileName());


}


void MainWindow::on_FileList_clicked(const QModelIndex &index)
{
    QString imageName = file->fileInfo(index).absoluteFilePath();
    //if imageName is not equal to 0 and valid is True, display on label
    if (QString::compare(imageName, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(imageName);
    try{
        if(valid)
        {
            ui->Image->setPixmap(QPixmap::fromImage(image));
        }
        }catch(DockOption e){
            std::cout<<"image crashes!"<<std::endl;
        }
    }
}
