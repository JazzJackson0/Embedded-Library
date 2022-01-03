#include <iostream>
#include <cstdlib>
#include "stack.h"
using std::string;

Stack::Stack(int aStackCapacity) {

    stackCapacity = aStackCapacity;
    stackItems = (int*) malloc(stackCapacity * sizeof(int));
    currentSize = 0;

}

int Stack::Get_StackSize() {
    return currentSize;
}

int Stack::Get_StackCapacity() {
    return stackCapacity;
}

void Stack::Push(int data) {
    if (currentSize == stackCapacity) { 

        stackItems = (int*) realloc(stackItems, (stackCapacity * 2));
        stackCapacity = stackCapacity * 2;
        }

        stackItems[currentSize] = data;
        currentSize++;
}

int Stack::Pop() {
    if (currentSize == 0) { 

        throw "The Stack is Empty";
        }

        int data = stackItems[currentSize - 1];
        stackItems[currentSize - 1] = 0;
        currentSize--;

        return data;
}

int Stack::Peek() {

    if (currentSize == 0) { 

        throw "The Stack is Empty";
        }

        return stackItems[currentSize - 1];

}

bool Stack::isEmpty() {
    return currentSize == 0;
}

bool Stack::isFull() {
    return currentSize == stackCapacity;
}

void Stack::SearchStack() {

}

string Stack::ToString() {


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