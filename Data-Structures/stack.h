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

        /**
         * @brief 
         * 
         */
        Stack(int aStackCapacity);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_StackSize();
        
        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Get_StackCapacity();

        /**
         * @brief 
         * 
         * @param data 
         * @return ** void 
         */
        void Push(int data);

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Pop();

        /**
         * @brief 
         * 
         * @return ** int 
         */
        int Peek();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool isFull();

        /**
         * @brief 
         * 
         * @return ** void 
         */
        void SearchStack();

        /**
         * @brief 
         * 
         * @return ** string 
         */
        string ToString();

};


