#pragma once
#include "linkedList.h"

class DoublyLinkedList : public LinkedList {

    public:

        DoublyLinkedList();

        DoublyLinkedList(Node* node);

        int InsertNode(Node* node, int index);

        int RemoveNode(Node *node);

};

