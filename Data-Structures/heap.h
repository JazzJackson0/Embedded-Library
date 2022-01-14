#pragma once

class Heap {
    protected:
        int heapSize;
        int currentSize;
        int *heap;

        /**
         * @brief 
         * 
         * @param index 
         * @return ** int 
         */
        int Get_ParentIndex(int index);

        /**
         * @brief 
         * 
         * @param index 
         * @return ** int 
         */
        int Get_LeftChildIndex(int index);

        /**
         * @brief 
         * 
         * @param index 
         * @return ** int 
         */
        int Get_RightChildIndex(int index);

        /**
         * @brief 
         * 
         * @param index 
         * @return true 
         * @return false 
         */
        bool hasChild(int index);
    
    public:

        Heap();
        
        /**
         * @brief 
         * 
         */
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

        /**
         * @brief 
         * 
         * @return ** void 
         */
        void HeapifyUp(); //To be implemented in derrived classes

        /**
         * @brief 
         * 
         * @return ** void 
         */
        void HeapifyDown(); //To be implemented in derrived classes


        
};
