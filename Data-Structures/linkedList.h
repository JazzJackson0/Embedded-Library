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
        
        LinkedList(Node *aHead);

        int Get_Size();

        Node* Get_Head();

        void Set_Head(Node *aHead);

        int InsertNode(Node* node, int index);

        int RemoveNode(Node *node);

        int FindNode(Node *node);

        Node* Get_NodeAtIndex(int index);

        int Get_LastIndexOf(Node *node);

        int HasNext();

        string ToString();


};

struct node {
    int data;
    Node *nextNode = NULL;
    Node *previousNode = NULL;
};