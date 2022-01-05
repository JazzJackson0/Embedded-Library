#pragma once

class TreeNode {
    private:
        int data;
        int currentNumOfChildren;
        TreeNode *children;

    public:

        TreeNode(int aData);

        int Get_Data();

        void AddChild(int newElement);

        int FindChild(int element);

        void RemoveChild(int elementToRemove);

        void InOrderTraversal(TreeNode *tNode);

        void PreOrderTraversal(TreeNode *tNode);

        void PostOrderTraversal(TreeNode *tNode);

};



