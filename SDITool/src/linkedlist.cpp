#include "headers/linkedlist.h"

void LinkedList::insertNode(QFileInfo file)
{
    Node* newNode = new Node;
    newNode->Next=NULL;
    newNode->Data=file;
    if(head==NULL){
        head = newNode;

    }
    else
    {
        curr = head;
        while(curr->Next != NULL)
        {
            curr = curr->Next;
        }
        curr->Next=newNode;
    }
}

QString LinkedList::Name(QFileInfo x)
{
    curr = head;
    while(curr->Data != x)
    {
        curr = curr->Next;
    }
    return curr->Data.fileName();
}

QString LinkedList::fPath(QString x)
{
    curr = head;
    while(curr->Data.fileName() != x)
    {
        curr = curr->Next;
    }
    return curr->Data.absoluteFilePath();
}
