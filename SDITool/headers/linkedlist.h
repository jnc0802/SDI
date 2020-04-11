#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "mainwindow.h"
#include <QFileInfo>

class LinkedList
{

private:
    struct Node{
        QFileInfo Data;
        Node* Next;
    };
    Node* head;
    Node* curr;
public:
    LinkedList(){head=NULL;}
    void insertNode(QFileInfo file);
    void deleteNode(QFileInfo file);
    QString Name(QFileInfo x);
    QString fPath(QString x);
};

#endif // LINKEDLIST_H
