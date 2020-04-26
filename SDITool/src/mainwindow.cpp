#include "headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "headers/linkedlist.h"
#include <iostream>

LinkedList List;
ClassFile newCFile;
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
    ui->ImgView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->ImgView->setScene(scene);

}


void MainWindow::on_SortAlpha_clicked()
{
    List.sortAlpha();
    ui->FileList->clear();
    ui->FileList->addItems(List.displayList());
}

void MainWindow::on_DrawBtn_clicked()
{
    ui->ClassList->clear();
    QString NewClass = ui->ClassName->text();
    newCFile.addTOFile(NewClass);
    ui->ClassList->addItems(newCFile.readFile());

}

void MainWindow::on_ClassBtn_clicked()
{
    ui->ClassList->clear();
    QFileInfo classFile = QFileDialog::getOpenFileName(
                this, tr("Choose a File"),
                "C://",
                "Class Files (*.names)");
    newCFile.addFile(classFile.absoluteFilePath());
    ui->ClassList->addItems(newCFile.readFile());
}

void MainWindow::on_ClassList_clicked(const QModelIndex &index)
{
    QString cName = ui->ClassList->currentItem()->text();
    rectangle = new Shapes;
    rectangle->setState(cName);
    scene->addItem(rectangle);
}


