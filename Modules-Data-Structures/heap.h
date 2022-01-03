#pragma once

class Heap {
    protected:
        int heapSize;
        int currentSize;
        int *heap;

        int Get_ParentIndex(int index);

        int Get_LeftChildIndex(int index);

        int Get_RightChildIndex(int index);

        bool hasChild(int index);
    
    public:

        Heap();
        
        Heap(int aHeapSize);

        /**
         * @brief Adds an element to the heap without altering the current heap.
         * 
         * @param element 
         * @return ** void 
         */
        void HeapPush(int element);

        /**
         * @brief Returns the smallest data element from the heap.
         * 
         * @return ** int
         */
        int HeapPop();

        /**
         * @brief Replaces the root data element with 
         * a new value supplied in the function.
         * 
         * @param newValue 
         * @return ** void 
         */
        void HeapReplace(int newValue);

        void HeapifyUp(); //To be implemented in derrived classes

        void HeapifyDown(); //To be implemented in derrived classes


        
};
