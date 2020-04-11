#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/linkedlist.h"
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
    List.insertNode(newFile);
    ui->FileList->addItem(List.Name(newFile));


}

void MainWindow::on_FileList_itemClicked(QListWidgetItem *item)
{

}