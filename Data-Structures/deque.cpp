#include <iostream>
#include "deque.h"


Deque::Deque(int capacity): Queue(capacity) {

}

void Deque::EnqueueFront(int data) {
    if (currentSize == queueCapacity) { 

        queue = (int*) realloc(queue, (queueCapacity * 2));
        queueCapacity = queueCapacity * 2;
    }

    // Shift data to the right.
    int pos = 0;
    int i = currentSize;
    /* Can't guarantee that spaces up to index 0 are not non-useable empty space
    So a while loop is used instead of for loop.*/
    while (pos < currentSize) { 

        queue[currentSize] = queue[currentSize - 1];
        pos++;
        i--;
    }
    
    queue[0] = data;
    currentSize++;  
}

void Deque::EnqueueBack(int data) {
    Enqueue(data);
}

int Deque::DequeueFront() {
    return Dequeue();
}

int Deque::DequeueBack() {
    if (currentSize == 0) { throw "Deque is Empty"; }

    int data = queue[currentSize - 1];
    queue[currentSize - 1] = 0;
    currentSize--;  
    return data;
}

int Deque::PeekFront() {
    return Peek();
}

int Deque::PeekBack() {
    return queue[currentSize - 1];
}