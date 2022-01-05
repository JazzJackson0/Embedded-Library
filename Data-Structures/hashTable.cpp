#include <iostream>
#include "hashTable.h"
using std::nullptr_t;


int HashTable::Get_HashCode(int key) {
    /*Honestly, this is just a compression function, 
    and should really be done after an actual hash code is obtained
    rather than in place of a hash code. But whatevs.*/
    return key % tableSize;
}

int HashTable::Hash(int key, int collision) {
    return Get_HashCode(key) + collision;
}

HashTable::HashTable(int size) {
    tableSize = size;
    table = (Element*) calloc(tableSize, sizeof(Element));
}

int HashTable::Insert_Element(int key, int value1, int value2) {
    Element elem;
    elem.key = key;
    elem.data_value1 = value1;
    elem.data_value2 = value2;

    int index = Hash(key, 0);

    //There's space to input element OR Overwriting element
    if (!(table[index]) || table[index].key == elem.key) {
        
        table[index] = elem;
        return 1;
    }
    int collision_count = 1;

    //Collision Occurred
    while(table[index].key != elem.key) {
        int index = Hash(key, collision_count);

        //There's space to input element OR Overwriting element
        if (!(table[index]) || table[index].key == elem.key) {
            
            table[index] = elem;
            return 1;
        }
        collision_count++;
    }
    return 0;
} 

Element HashTable::Find_Element(int key) {
    int index = Hash(key, 0);

    //Nothing there
    if (!(table[index])) { throw "No Data Matching this Key"; }

    //Match
    if (table[index].key == key) { return table[index]; }

    int collision_count = 1;

    //Collision Occurred
    while(table[index].key != key) {
        int index = Hash(key, collision_count);

        //Nothing there
        if (!(table[index])) { throw "No Data Matching this Key"; }

        //Match
        if (table[index].key == key) { return table[index]; }
        
        collision_count++;
    }
    return nullptr;


}  

int HashTable::Remove_Element(int key) {
    int index = Hash(key, 0);

    //Nothing there
    if (!(table[index])) { throw "No Data Matching this Key"; }

    //Match
    if (table[index].key == key) { 
        table[index] = 0; 
        return 1;
    }

    int collision_count = 1;

    //Collision Occurred
    while(table[index].key != key) {
        int index = Hash(key, collision_count);

        //Nothing there
        if (!(table[index])) { throw "No Data Matching this Key"; }

        //Match
        if (table[index].key == key) { 
            table[index] = 0;
            return 1;
        }
        
        collision_count++;
    }
    return 0;
}



/*
 * 			TO-DO
 * 			-----
 *  - Test Code
 *
 *  - Make the table a pointer to a pointer
 *  
 *  - 
 *  */