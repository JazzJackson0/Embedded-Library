#pragma once
#include "heap_Min.h"

class PriorityQueue : public MinHeap {

    public:
        
        PriorityQueue(int size);

        void Enqueue(int data);

        int Dequeue();

        int Get_Size();

        bool isEmpty();

        bool isFull();

        int Peek();

};
