#include <iostream>
#include "heap_Min.h"

int MinHeap::Get_SmallestChildIndex(int index) {
    
    //If there is only a left child.
    if (Get_RightChildIndex(index) > currentSize) { 
        std::cout << "There is only a left child.";
        return Get_LeftChildIndex(index);
    }

    else {

        int left_child = heap[Get_LeftChildIndex(index)];
        int right_child = heap[Get_RightChildIndex(index)];

        if (left_child < right_child) {
            std::cout << "Left Child is smaller";
            return Get_LeftChildIndex(index);
        }

        if (right_child < left_child) {
            std::cout << "Right Child is smaller.";
            return Get_RightChildIndex(index);
        }
    }

    return;
}

MinHeap::MinHeap() {

}

MinHeap::MinHeap(int aHeapSize) {

    Heap(aHeapSize);
}


void MinHeap::HeapifyUp() {
    int index = currentSize - 1;

    while (Get_ParentIndex(index) > 0) {

        int parent = heap[Get_ParentIndex(index)];
        int child = heap[index];

        if (child < parent) {
            heap[index] = parent;
            heap[Get_ParentIndex(index)] = child;
            std::cout << "Swapping " << child << " with " << parent << ".";
        }

        index = Get_ParentIndex(index);
    }
    
    return;
}


void MinHeap::HeapifyDown() {

    int index = 0;

    while (hasChild(index)) {

        int data_going_down = heap[index];
        int child = heap[Get_SmallestChildIndex(index)];

        if (data_going_down > child) {
            heap[index] = child;
            heap[Get_SmallestChildIndex(index)] = data_going_down;
        }

        index = Get_SmallestChildIndex(index);
    }

    return;
}