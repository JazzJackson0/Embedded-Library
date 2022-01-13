#include <iostream>
#include "queue_Priority.h"

PriorityQueue::PriorityQueue(int size): MinHeap(size) {

}

void PriorityQueue::Enqueue(int data) {
    HeapPush(data);
}

int PriorityQueue::Dequeue() {
    return HeapPop();
}

int PriorityQueue::Get_Size() {

    return currentSize;
}

bool PriorityQueue::isEmpty() {
    return currentSize == 0;
}

bool PriorityQueue::isFull() {
    return currentSize == heapSize;
}

int PriorityQueue::Peek() {
    return heap[0];
}