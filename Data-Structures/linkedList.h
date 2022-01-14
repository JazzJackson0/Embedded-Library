#pragma once
#include <iostream>
#include <cstdlib>
using std::string;

typedef struct node Node;

class LinkedList {
    protected:
        Node *head;
        int currentSize;

    public:

        LinkedList();
        
        /**
         * @brief 
         * 
         */
        LinkedList(Node *aHead);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_Size();

        /**
         * @brief 
         * 
         * @return ** Node* 
         */
        Node* Get_Head();

        /**
         * @brief 
         * 
         * @param aHead 
         * @return ** void 
         */
        void Set_Head(Node *aHead);

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

        /**
         * @brief 
         * 
         * @param node 
         * @return ** int 
         */
        int FindNode(Node *node);

        /**
         * @brief 
         * 
         * @param index 
         * @return ** Node* 
         */
        Node* Get_NodeAtIndex(int index);

        /**
         * @brief 
         * 
         * @param node 
         * @return ** int 
         */
        int Get_LastIndexOf(Node *node);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int HasNext();

        /**
         * @brief 
         * 
         * @return ** string 
         */
        string ToString();


};

struct node {
    int data;
    Node *nextNode = NULL;
    Node *previousNode = NULL;
};