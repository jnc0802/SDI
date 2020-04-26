#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "mainwindow.h"
#include <QFileInfo>
#include <QDebug>
#include "node.h"

class LinkedList {
private: // Should be private have a look at
    Node* head;
    Node* curr;
    Node* tail;
    int nodeNum=0;

public:
    LinkedList(void) { head = NULL; tail = NULL; }
    Node* insertNode(QString, QString);
    QString fPath(QString);
    void sortAlpha();
    QStringList displayList();
};

#endif // LINKEDLIST_H
