#pragma once
#include "linkedList.h"
#include "linkedList_Doubly.h"

class CircularLinkedList : public LinkedList {

    public:

        /**
         * @brief 
         * 
         */
        CircularLinkedList(Node* node);

        /**
         * @brief 
         * 
         * @param node 
         * @param index 
         * @return ** int 
         */
        int InsertNode(Node* node, int index);

};


class CircularDoublyLinkedList : public DoublyLinkedList {

    public:

        /**
         * @brief 
         * 
         */
        CircularDoublyLinkedList(Node* node);

        /**
         * @brief 
         * 
         * @param node 
         * @param index 
         * @return ** int 
         */
        int InsertNode(Node* node, int index);

};

