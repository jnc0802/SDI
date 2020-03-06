#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Sets root path for the directory tree to display
    QString sPath= "C:/";
    directory = new QFileSystemModel(this);
    //Display only directories not files
    directory->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    directory->setRootPath(sPath);
    ui->directoryTree->setModel(directory);

    file = new QFileSystemModel(this);
    //Display files only
    file->setFilter(QDir::NoDotAndDotDot | QDir::Files);


    ui->fileList->setModel(file);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Clicking a directory sets the path for the file pane to that directory's root path
void MainWindow::on_directoryTree_clicked(const QModelIndex &index)
{
   QString dirPath = directory->fileInfo(index).absoluteFilePath();
   ui->fileList->setRootIndex(file->setRootPath(dirPath));
}
//Clicking over the list view loads images to the label
void MainWindow::on_fileList_clicked(const QModelIndex &index)
{
    QString imageName = QFileDialog::getOpenFileName(this, tr("Pick an image"),"",tr("Images(*.jpg *.jpeg *.gif *.png"));
    //if imageName is not equal to 0 and valid is True, display on label
    if (QString::compare(imageName, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(imageName);

        if(valid)
        {
            ui->imageLabel->setPixmap(QPixmap::fromImage(image));
        }

    }
}
