#include <iostream>
#include "linkedList_Doubly.h"


int DoublyLinkedList::InsertNode(Node* node, int index) {
    
    if (index > currentSize || index < 0) { throw "Index Out of Range"; }

    else if (index == 0) { 
        Set_Head(node);
        return 1; 
    }

    else {
        Node *currentNode = Get_Head();

        for (int i = 1; i <= currentSize; i++) {

            if (i == index) {

                //Set Next Node Links
                Node *tempNode = currentNode->nextNode;
                currentNode->nextNode = node;
                node->nextNode = tempNode;

                //Set Previous Node Links
                tempNode->previousNode = node;
                node->previousNode = currentNode;
                
                currentSize++;
                return 1;
            }
            currentNode = currentNode->nextNode;
        }
    }

    return 0;
}

int DoublyLinkedList::RemoveNode(Node *node) {

    Node *currentNode = Get_Head();
    for (int i = 0; i < currentSize; i++) {

        if (node->data == currentNode->data) {

            if (i == 0) {
                Set_Head(currentNode->nextNode);
                currentNode = 0;
            }

            else {
                currentNode->previousNode->nextNode = currentNode->nextNode;
                currentNode->nextNode->previousNode = currentNode->previousNode;
                currentNode = 0;
            }

            currentSize--;
            return 1;
        }
        currentNode = currentNode->nextNode;
    }

    return 0;
}