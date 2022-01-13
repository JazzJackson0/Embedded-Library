#pragma once
#include "linkedList.h"
#include "linkedList_Doubly.h"

class CircularLinkedList : public LinkedList {

    public:

        CircularLinkedList(Node* node);

        int InsertNode(Node* node, int index);

};


class CircularDoublyLinkedList : public DoublyLinkedList {

    public:

        CircularDoublyLinkedList(Node* node);

        int InsertNode(Node* node, int index);

};

