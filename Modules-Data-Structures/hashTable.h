#pragma once


typedef struct element {
    int data_value1;
    int data_value2;
    int key;
}Element;

class HashTable {
    private:
        int tableSize;
        Element* table;

        int Get_HashCode(int key);

        int Hash(int key, int collision);

    public:

        HashTable(int size); 

        int Insert_Element(int key, int value1, int value2);

        Element Find_Element(int key);

        int Remove_Element(int key);

};

