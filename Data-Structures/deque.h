#pragma once
#include "queue.h"

class Deque : public Queue {

    public:

        Deque(int capacity);

        void EnqueueFront(int data);

        void EnqueueBack(int data);

        int DequeueFront();

        int DequeueBack();

        int PeekFront();

        int PeekBack();

};