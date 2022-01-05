#pragma once
#include "linkedList.h"
#include "linkedList_Doubly.h"

class CircularLinkedList : public LinkedList {

    public:

        int InsertNode(Node* node, int index);

};


class CircularDoublyLinkedList : public DoublyLinkedList {

    public:
        int InsertNode(Node* node, int index);

};

