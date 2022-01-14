#pragma once

class TreeNode {
    private:
        int data;
        int currentNumOfChildren;
        TreeNode *children;

    public:

        /**
         * @brief 
         * 
         */
        TreeNode(int aData);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_Data();

        /**
         * @brief 
         * 
         * @param newElement 
         * @return ** void 
         */
        void AddChild(int newElement);

        /**
         * @brief 
         * 
         * @param element 
         * @return ** int 
         */
        int FindChild(int element);

        /**
         * @brief 
         * 
         * @param elementToRemove 
         * @return ** void 
         */
        void RemoveChild(int elementToRemove);

        /**
         * @brief 
         * 
         * @param tNode 
         * @return ** void 
         */
        void InOrderTraversal(TreeNode *tNode);

        /**
         * @brief 
         * 
         * @param tNode 
         * @return ** void 
         */
        void PreOrderTraversal(TreeNode *tNode);

        /**
         * @brief 
         * 
         * @param tNode 
         * @return ** void 
         */
        void PostOrderTraversal(TreeNode *tNode);

};



