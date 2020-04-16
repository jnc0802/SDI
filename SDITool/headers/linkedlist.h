#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "mainwindow.h"
#include <QFileInfo>
#include "node.h"

class LinkedList {
private: // Should be private have a look at
    Node* head;
    Node* curr;
    Node* tail;
public:
    LinkedList(void) { head = NULL; tail = NULL; }
    Node* insertNode(QString, QString);
    Node* deleteNode(QFileInfo);
    QString fPath(QString);
};

#endif // LINKEDLIST_H
