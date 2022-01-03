#include <iostream>
#include "queue.h"

Queue::Queue() {

}

Queue::Queue(int capacity) {

    queueCapacity = capacity;
    queue = (int*) calloc(capacity, sizeof(int));
    currentSize = 0;
}

int Queue::Get_Size() {

    return currentSize;
}

void Queue::Enqueue(int data) {
    if (currentSize == queueCapacity) { 

        queue = (int*) realloc(queue, (queueCapacity * 2));
        queueCapacity = queueCapacity * 2;
        }
    queue[currentSize - 1] = data;
    currentSize++;         
}

int Queue::Dequeue() {
    if (currentSize == 0) { std::cout << "Queue is Empty" << std::endl; }
    int data = queue[0];

    for (int i = 1; i < currentSize; i++) {
        queue[i - 1] = queue[i];
    }

    currentSize--;
    return data;
}

bool Queue::IsEmpty() {
    return currentSize == 0;
}

bool Queue::isFull() {
    return currentSize == queueCapacity;
}

int Queue::Peek() {
    
    return queue[0];
}



/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - 
 *  
 *  - 
 *  */