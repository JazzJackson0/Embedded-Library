#pragma once
#include <iostream>
#include "heap.h"

class MaxHeap : public Heap {
    private:
        int Get_LargestChildIndex(int index);

    public:

        MaxHeap(int aHeapSize);

        /**
         * @brief Ensures a newly added node is in MaxHeap order.
         * 
         * @return ** void 
         */
        void HeapifyUp();

        /**
         * @brief Ensures root node moves to correct location to maintain MaxHeap order.
         * 
         * @return ** void 
         */
        void HeapifyDown();
};


