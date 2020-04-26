#include "headers/linkedlist.h"
#include <cstdlib>
#include <iostream>
namespace Ui {

}


Node* LinkedList::insertNode(QString name, QString path)
{
    Node* temp = new Node;
        temp->Name = name;
        temp->fPath = path;
        temp->Next = NULL;
        //Sets the node as head
        if (head == NULL) {
            head = temp;
            tail = temp;
            temp = NULL;
            nodeNum++;
        }
        //Sets the node as tail
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
    //finds the node with the same filepath as the list
    curr=head;
    while(curr->Name!=x){
        curr=curr->Next;
    }
    return curr->fPath;
}

void LinkedList::sortAlpha()
{
    Node* tempNode;
    QString tempString1;
    QString tempString2;
    for(int stop = nodeNum ;stop>0 ; stop--){

        curr = head;

        for(int check = 0; check<stop-1;check ++){
                tempString1 = curr->Name;
                tempString2 = curr->Next->Name;
                //Swap current and current next by storing curr in a temp node
                if( tempString1.at(0) > tempString2.at(0) ){
                    tempNode = curr;
                    curr = curr->Next;
                    //if tempnode is the same as head curr becomes head
                    if(tempNode == head){
                        head = curr;
                    }
                    tempNode->Next = curr->Next;
                    curr->Next = tempNode;
                    //if tempnode next is null then temp node is tail
                    if(tempNode->Next == NULL){
                        tail = tempNode;
                    }




            }
            curr=curr->Next;

    }

}
}




QStringList LinkedList::displayList()
{
    QStringList names;
    curr=head;
    //inserts the names of all files into a list until it reaches the end of the list
    for(int i = 0 ; i < nodeNum; i++){
        names << curr->Name;
        curr = curr->Next;
        qDebug() << "insert";
    }
    return names;

}

