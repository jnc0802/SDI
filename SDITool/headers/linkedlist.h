#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "mainwindow.h"
#include <QFileInfo>

class LinkedList
{
public:
    struct Node{
        QFileInfo Data;
        Node* next;
    };

    Node* head;
    LinkedList(void){head=NULL;}
    ~LinkedList(void);

    bool IsEmpty();
    Node* InsertNode(int index, QFileInfo x);
    int FindNode(QFileInfo x);
    int DeleteNode(QFileInfo x);
    void DisplayList(void);
};

#endif // LINKEDLIST_H
