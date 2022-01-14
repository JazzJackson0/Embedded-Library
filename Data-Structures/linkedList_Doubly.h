#pragma once
#include "linkedList.h"

class DoublyLinkedList : public LinkedList {

    public:

        DoublyLinkedList();

        /**
         * @brief 
         * 
         */
        DoublyLinkedList(Node* node);

        /**
         * @brief 
         * 
         * @param node 
         * @param index 
         * @return ** int 
         */
        int InsertNode(Node* node, int index);

        /**
         * @brief 
         * 
         * @param node 
         * @return ** int 
         */
        int RemoveNode(Node *node);

};

