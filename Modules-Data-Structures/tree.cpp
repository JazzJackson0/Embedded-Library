#include <iostream>
#include "tree.h"

TreeNode::TreeNode(int aData) {
    currentNumOfChildren = 0;
    data = aData;
}

int TreeNode::Get_Data() {
    return data;
}

void TreeNode::AddChild(int newElement) {
    children[currentNumOfChildren] = TreeNode(newElement);
    currentNumOfChildren++;
}

int TreeNode::FindChild(int element) {

    for (int i = 0; i < currentNumOfChildren; i++) {
        
        if (element == children[i].Get_Data()) { return i; }
    }
}

void TreeNode::RemoveChild(int elementToRemove) {

    int index = FindChild(elementToRemove);
    children[index] = 0;

    for (int i = index; i < currentNumOfChildren; i++) {
        
        if ((i + 1) < currentNumOfChildren) {
            children[i] = children[i + 1];
        }
    }
    currentNumOfChildren--;   
}

void TreeNode::InOrderTraversal() {
    
}

void TreeNode::PreOrderTraversal() {


}

void TreeNode::PostOrderTraversal() {

}

void TreeNode::PrintTree() {

}



/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */