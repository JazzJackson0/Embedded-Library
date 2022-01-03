#include <iostream>
#include "queue_Circular.h"


CircularQueue::CircularQueue(int capacity) {
    Queue(capacity);
    queueFrontIndex = -1;
    queueRearIndex = -1;
}

void CircularQueue::Enqueue(int data) {
    if (currentSize == queueCapacity) { std::cout << "Circular Queue is Full." << std::endl; }

    if (currentSize == 0) { queueFrontIndex = 0; }

    // Circular algorithm
    if ((queueRearIndex + 1) == queueCapacity) {
        queueRearIndex = (queueRearIndex + 1) % queueCapacity;
    }
    
    else { queueRearIndex++; }

    queue[queueRearIndex] = data;
    currentSize++; 
}

int CircularQueue::Dequeue() {
    if (currentSize == 0) { std::cout << "Circular Queue is Empty." << std::endl; }
    int data = queue[queueFrontIndex];
    queue[queueFrontIndex] = 0;
    
    // Circular algorithm
    if ((queueFrontIndex + 1) == queueCapacity) {
        queueFrontIndex = (queueFrontIndex + 1) % queueCapacity;
    }
    
    else { queueFrontIndex++; }

    currentSize--;

    // If queue is now empty, reset index values..
    if (currentSize == 0) {
        queueFrontIndex = -1;
        queueRearIndex = -1;
        }

    return data;
}