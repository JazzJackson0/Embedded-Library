#include <iostream>
#include "linkedList_Circular.h"


CircularLinkedList::CircularLinkedList(Node* node): LinkedList(node) {
}

int CircularLinkedList::InsertNode(Node* node, int index) {
    
    if (index > currentSize || index < 0) { throw "Index Out of Range"; }

    else if (index == 0) { 
        Set_Head(node);
        return 1; 
    }

    //Add a Circular Link to nodes put at the end.
    else if (index == currentSize) {

        Node *currentNode = Get_Head();
        for (int i = 0; i < currentSize; i++) { // Should index start at 0 or 1?
            currentNode = currentNode->nextNode;
        }

        currentNode->nextNode = node;
        node->nextNode = Get_Head();
    }

    else {
        Node *currentNode = Get_Head();

        for (int i = 1; i <= currentSize; i++) {

            if (i == index) {

                Node *tempNode = currentNode->nextNode;
                currentNode->nextNode = node;
                node->nextNode = tempNode;
                currentSize++;
                return 1;
            }
            currentNode = currentNode->nextNode;
        }
    }

    return 0;
}





//---------------------------------------------------------------------------------------

CircularDoublyLinkedList::CircularDoublyLinkedList(Node* node): DoublyLinkedList(node) {
}

int CircularDoublyLinkedList::InsertNode(Node* node, int index) {
    
    if (index > currentSize || index < 0) { throw "Index Out of Range"; }

    else if (index == 0) { 
        Set_Head(node);
        node->previousNode = node; //Needed for the sake of the circular link
        return 1; 
    }

    //Add a Circular Link to nodes put at the end.
    else if (index == currentSize) {

        Get_Head()->previousNode->nextNode = node;
        node->previousNode = Get_Head()->previousNode;

        node->nextNode = Get_Head();
        Get_Head()->previousNode = node;
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