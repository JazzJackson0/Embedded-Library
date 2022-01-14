#pragma once


typedef struct element {
    int data_value1;
    int data_value2;
    int key;
    bool empty = true;
}Element;

class HashTable {
    private:
        int tableSize;
        Element* table;

        /**
         * @brief 
         * 
         * @param key 
         * @return ** int 
         */
        int Get_HashCode(int key);

        /**
         * @brief 
         * 
         * @param key 
         * @param collision 
         * @return ** int 
         */
        int Hash(int key, int collision);

    public:

        /**
         * @brief 
         * 
         */
        HashTable(int size); 

        /**
         * @brief 
         * 
         * @param key 
         * @param value1 
         * @param value2 
         * @return ** int 
         */
        int Insert_Element(int key, int value1, int value2);

        /**
         * @brief 
         * 
         */
        Element Find_Element(int key);

        /**
         * @brief 
         * 
         * @param key 
         * @return ** int 
         */
        int Remove_Element(int key);

};

