//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// hash_table.h
// March 2024
// This file contains the Hash Table class declaration.  
//========================================================

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <string>
#include "element.h"
using namespace std;

template <class T>
class HashTable
{
    private:
        int size;
        Element<T>** table;

        int get_size()
        { 
            return size; 
        }
        int hash (int k)
        {
            return k % size; 
        }

    public:
                    HashTable(int tableSize = 100);
                    ~HashTable();

        void        insert (T data, int key);
        void        remove (int k);
        bool        member (T d, int k);
        string      to_string (void) const; 
        int         get_slot_count (int slot);
};

#endif