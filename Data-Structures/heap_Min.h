#pragma once
#include <iostream>
#include "heap.h"

class MinHeap : public Heap {
    private:
        int Get_SmallestChildIndex(int index);
    
    public:

        MinHeap();

        /**
         * @brief 
         * 
         */
        MinHeap(int aHeapSize);

        /**
         * @brief Ensures a newly added node is in MinHeap order.
         * 
         * @return ** void 
         */
        void HeapifyUp();

        /**
         * @brief Ensures root node moves to correct location to maintain MinHeap order.
         * 
         * @return ** void 
         */
        void HeapifyDown();
};



