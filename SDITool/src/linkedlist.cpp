#include "linkedlist.h"
#include "ui_mainwindow.h"


LinkedList::Node* LinkedList::InsertNode(int index, QFileInfo x){
    if(index<0)
    {
        return NULL;
    }

    int currIndex = 1;
    Node* currNode = head;
    while(currNode&&index>currIndex)
    {
        currNode=currNode->next;
        currIndex++;
    }

    if(index>0&&currNode==NULL)
    {
        return NULL;
    }

    Node* newNode = new Node;
    newNode->Data=x;
    if(index==0)
    {
        newNode->next=head;
        head = new Node;
    }
    else
    {
        newNode->next=currNode;
        currNode->next=newNode;
    }

    return newNode;

}

LinkedList::~LinkedList(void){

}

