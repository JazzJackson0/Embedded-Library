#pragma once
#include "heap_Min.h"

class PriorityQueue : public MinHeap {

    public:
        
        /**
         * @brief 
         * 
         */
        PriorityQueue(int size);

        /**
         * @brief 
         * 
         * @param data 
         * @return ** void 
         */
        void Enqueue(int data);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Dequeue();

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_Size();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool isFull();

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Peek();

};
