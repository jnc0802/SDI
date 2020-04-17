#include "headers/linkedlist.h"
#include <cstdlib>
#include <iostream>


Node* LinkedList::insertNode(QString name, QString path)
{
    int nodeNum=0;
    Node* temp = new Node;
        temp->Name = name;
        temp->fPath = path;
        temp->Next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
            nodeNum++;
        }
        else
        {
            tail->Next = temp;
            tail = temp;
            nodeNum++;
        }
        return 0;

}


QString LinkedList::fPath(QString x)
{
    curr=head;
    while(curr->Name!=x){
        curr=curr->Next;
    }
    return curr->fPath;
}

QString LinkedList::sortAlpha()
{
    curr=head;
    if(curr->Name>curr->Next->Name){

    }
}
