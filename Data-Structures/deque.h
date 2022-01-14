#pragma once
#include "queue.h"

class Deque : public Queue {

    public:

        Deque();
        
        /**
         * @brief 
         * 
         */
        Deque(int capacity);

        /**
         * @brief 
         * 
         * @param data 
         * @return ** void 
         */
        void EnqueueFront(int data);

        /**
         * @brief 
         * 
         * @param data 
         * @return ** void 
         */
        void EnqueueBack(int data);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int DequeueFront();
        
        /**
         * @brief 
         * 
         * @return ** int 
         */
        int DequeueBack();

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int PeekFront();

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int PeekBack();

};