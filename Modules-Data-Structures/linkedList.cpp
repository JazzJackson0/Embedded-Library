#include <iostream>
#include <cstdlib>
#include "linkedList.h"
using std::string;

LinkedList::LinkedList(Node *aHead) {
    head = aHead;
    currentSize = 0;
}

int LinkedList::Get_Size() {
    return currentSize;
}

Node* LinkedList::Get_Head() {
    return head;
}

void LinkedList::Set_Head(Node *aHead) {
    
    if (currentSize == 0) { 
        head = aHead;
        currentSize++;
    }
    
    else { 
        aHead->nextNode = head;
        currentSize++;
    }
}

int LinkedList::InsertNode(Node* node, int index) {
    
    if (index > currentSize || index < 0) { throw "Index Out of Range"; }

    else if (index == 0) { 
        Set_Head(node);
        return 1; 
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

int LinkedList::RemoveNode(Node *node) {

    Node *currentNode = Get_Head();
    Node *previousNode = NULL;
    for (int i = 0; i < currentSize; i++) {

        if (node->data == currentNode->data) {

            if (i == 0) {
                Set_Head(currentNode->nextNode);
                currentNode = 0;
            }

            else {
                previousNode->nextNode = currentNode->nextNode;
                currentNode = 0;
            }

            currentSize--;
            return 1;
        }
        previousNode = currentNode;
        currentNode = currentNode->nextNode;
    }

    return 0;
}

int LinkedList::FindNode(Node *node) {
    
    Node *currentNode = Get_Head();
    for (int i = 0; i < currentSize; i++) {

        if (node->data == currentNode->data) {

            return i;
        }
        currentNode = currentNode->nextNode;
    }
}

Node* LinkedList::Get_NodeAtIndex(int index) {
    
    if (index > currentSize || index < 0) { throw "Index Out of Range"; }

    Node *currentNode = Get_Head();
    for (int i = 0; i < currentSize; i++) {

        if (i == index) {

            return currentNode;
        }
        currentNode = currentNode->nextNode;

    }
}

int LinkedList::Get_LastIndexOf(Node *node) {

    Node *currentNode = Get_Head();
    int mostRecentIndex;
    for (int i = 0; i < currentSize; i++) {

        if (node->data == currentNode->data) {

            mostRecentIndex = i;
        }
        currentNode = currentNode->nextNode;
    }
    return mostRecentIndex;
}

int LinkedList::HasNext() {


}

string LinkedList::ToString() {


}



/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */