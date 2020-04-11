#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFileSystemModel>

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

    void on_FileList_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *file;
};

#endif // MAINWINDOW_H
