#include <iostream>
#include "heap.h"
/*A Heap is a Complete Binary Tree that satisfies one of the two Heap Properties.

Complete Binary Tree: 
A binary tree in which ALL the levels are completely 
filled except possibly the lowest one, which is filled from the left.

    1. All the leaf elements must lean towards the left. 
    2. The last leaf element might not have a right sibling.

Heap Properties:
    
    + Max Heap Property: Any given node is always greater than its child node/s.
    + Min Heap Property: Any given node is always smaller than its child node/s.

*/

int Heap::Get_ParentIndex(int index) {
    if (index % 2 == 0) { // Right Children are even indexed
        return (index / 2) - 1;
    }

    else { // Left Children are odd indexed
        return index / 2;
    }
}

int Heap::Get_LeftChildIndex(int index) {
    return (index * 2) + 1;
}

int Heap::Get_RightChildIndex(int index) {
    return (index * 2) + 2;
}

bool Heap::hasChild(int index) {
    return Get_LeftChildIndex(index) <= currentSize;
}


Heap::Heap() {
    
}

Heap::Heap(int aHeapSize) {

    heapSize = aHeapSize;
    heap = (int*) calloc(heapSize, sizeof(int));
    currentSize = 0;
}

/**
 * @brief Adds an element to the heap without altering the current heap.
 * 
 * @param element 
 * @return ** void 
 */
void Heap::HeapPush(int element) {
    heap[currentSize] = element;
    currentSize++;
    HeapifyUp();
}


int Heap::HeapPop() {
    if (currentSize == 0) {
        std::cout << "There is nothing in this heap.";
    }

    else {

        int min_value = heap[0];
        heap[0] = heap[currentSize - 1];
        heap[currentSize - 1] == 0;
        currentSize--;
        HeapifyDown();
        return min_value;
    }

    return NULL;
}

void Heap::HeapReplace(int newValue) {
    heap[0] = newValue;
    HeapifyDown();
}

void Heap::HeapifyUp() {
    //To be implemented in derrived classes
}

void Heap::HeapifyDown() {
    //To be implemented in derrived classes
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