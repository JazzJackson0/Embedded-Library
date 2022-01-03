#pragma once

class Queue {
    protected:
        int currentSize;
        int queueCapacity;
        int* queue;
    
    public:

        Queue();
        
        Queue(int capacity);

        int Get_Size();
        
        void Enqueue(int data);

        int Dequeue();

        bool IsEmpty();

        bool isFull();

        int Peek();

};



