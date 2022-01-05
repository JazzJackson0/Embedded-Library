#pragma once
#include "queue.h"

class CircularQueue : public Queue {

    private:
        int queueFrontIndex;
        int queueRearIndex;

    public:

        CircularQueue(int capacity);
        
        void Enqueue(int data);

        int Dequeue();

        
};
