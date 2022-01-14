#pragma once

class Queue {
    protected:
        int currentSize;
        int queueCapacity;
        int* queue;
    
    public:

        Queue();
        
        /**
         * @brief 
         * 
         */
        Queue(int capacity);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_Size();
        
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
         * @return true 
         * @return false 
         */
        bool IsEmpty();

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



