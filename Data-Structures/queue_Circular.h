#pragma once
#include "queue.h"

class CircularQueue : public Queue {

    private:
        int queueFrontIndex;
        int queueRearIndex;

    public:

        /**
         * @brief 
         * 
         */
        CircularQueue(int capacity);
        
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

};
