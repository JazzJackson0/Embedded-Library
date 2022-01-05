#pragma once
#include <iostream>
#include <cstdlib>
using std::string;

class Stack {
    private:
        int currentSize;
        int stackCapacity;
        int *stackItems;
    public:

        Stack(int aStackCapacity);

        int Get_StackSize();
        
        int Get_StackCapacity();

        void Push(int data);

        int Pop();

        int Peek();

        bool isEmpty();

        bool isFull();

        void SearchStack();

        string ToString();

};


