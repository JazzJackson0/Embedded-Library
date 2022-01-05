#pragma once
#include "linkedList.h"

class DoublyLinkedList : public LinkedList {

    public:

        int InsertNode(Node* node, int index);

        int RemoveNode(Node *node);

};

