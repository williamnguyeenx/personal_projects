//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// hash_table.cpp
// March 2024
// This file contains the class methods for the
// HashTable class.
//========================================================

#include "hash_table.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std; 

//========================================================
// define HashTable class
//========================================================

//========================================================
// HashTable 
// default constructor
// Create an empty HashTable
// Parameter: None
// Return value: None
// Pre-condition: None
// Post-condition: HashTable object created
//========================================================
template <class T>
HashTable<T>::HashTable(int tableSize) 
{
    size = tableSize;
    table = new Element<T>*[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = nullptr;
    }
}
//========================================================
// ~HashTable
// Destructor
// This destructor iterates through the hash table, 
// deallocating any dynamically allocated memory for each Element object stored within. 
// Parameters: None
// Return Value: None
// Pre-condition: A HashTable object exists.
// Post-condition: The HashTable object and all its contained 
// Element objects are properly cleaned up, with their associated resources deallocated.
//========================================================

template <class T>
HashTable<T>::~HashTable() 
{
    for (int i = 0; i < size; i++) 
    {
        Element<T>* entry = table[i];
        while (entry != nullptr) 
        {
            Element<T>* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete[] table;
}

//========================================================
// insert
// Inserts a new element with the specified data and key into the hash table.
// Parameter: data (T) and key (int)
// Return Value: None
// Pre-condition: The hash table is initialized and capable of storing elements.
// Post-condition: The new element is added to the hash table. 
// If an element with the same key already exists, its data is updated to the new data.
//========================================================

template <class T>
void HashTable<T>::insert(T data, int key) 
{
    int index = hash(key); // compute hash value to determine index
    Element<T>* newEle = new Element<T>(data, key); // pointer to new Element with data and key
    Element<T>* current = table[index]; // pointer to DLL used for chaining
    
    while (current != nullptr) 
    {
        if (current->get_key() == key) // duplicate key found -> not insert
        {
            delete newEle; // delete element having duplicated key
            return;
        }
        current = current->next; // move to next element in DLL to keep checking
    }

    newEle->next = table[index]; // connect newEle with head of DLL
    newEle->prev = NULL; // previous node is NULL
    if (table[index] != nullptr) // if bucket isn't empty
    {
        table[index]->prev = newEle; // set prev of bucket to newEle to place newEle at the start
    }

    table[index] = newEle; // update the head of DLL to be newEle
}

//========================================================
// remove
// Removes an element with the specified key from the hash table.
// Parameters: key (int)
// Return Value: None
// Pre-condition: The hash table is initialized and may contain elements.
// Post-condition: If an element with the specified key existed, it is removed from the hash table, and any dynamically allocated memory is deallocated.
//========================================================

template <class T>
void HashTable<T>::remove(int key)
{
    int index = hash(key); // compute hash value to determine index
    Element<T>* current = table[index]; // pointer to DLL used for chaining

    while (current != nullptr) // iterate through non-null nodes
    {
        if (current->get_key() == key) // element with specified key is found
        {
            if (current->prev != nullptr) 
                current->prev->next = current->next; // connect the previous node with next node
            else
                table[index] = current->next; // if element is the head of DLL, update new head 

            if (current->next != nullptr)
                current->next->prev = current->prev; // connect next node with previous one

            delete current; // delete element with specified key
            return; // exit loop
        }

        current = current->next; // switch to next node to keep searching for element with key 
    }
}

//========================================================
// member
// Checks if an element with the specified data and key is a member of the hash table.
// Parameters: d (T) and k (int)
// Return Value: None
// Pre-condition: The hash table is initialized and may contain zero or more elements.
// Post-condition: A boolean value indicating whether element is member
//========================================================

template <class T>
bool HashTable<T>::member(T d, int k) 
{
    int index = hash(k); //compute hash value to determine index
    Element<T>* current = table[index]; // pointer to DLL used for chaining
    
    while (current != nullptr) 
    {
       if (current->get_key() == k && current->get_data() == d) // element with d and k is found
        return true; // indicate that it's a member

        current = current->next;
    }
    
   return false; // finish looping through list, element not found
}

//========================================================
// to_string
// returns a string with the elements in each doubly linked list
// separated by a single space and displayed as (data,key). 
// Each slot in the hash table should be separated by a new line
// Parameter: none
// Return value: string result of the specified format
// Pre-condition: Exists a Hash Table object
// Post-condition: A string representing data of Hash Table
//========================================================

template <class T>
string HashTable<T>::to_string () const
{
    if (size == 0)
        return "";

    stringstream result;

    for (int i = 0; i < size; i++)  // Iterate through each slot in the hash table
    {
        result << i << ": "; // Slot index followed by a colon

        Element<T>* current = table[i]; // Start of the linked list in the current slot

        while (current != nullptr) { // Traverse the doubly linked list
            // Append element representation in the format (data,key)
            result << "(" << current->get_data() << "," << current->get_key() << ") ";
            current = current->next; // Move to the next element in the list
        }

        result << "\n"; // End each slot's listing with a newline
    }

    return result.str(); // return string
}

//====================================================
// get_slot_count
// Returns the number of items in a particular slot (int)
// Parameter: int slot - number of slots in the table
// Return value: number of items in that slot
// Pre-condition: Exists a slot in the table
// Post-condition: The table with number of items in that slot returned
//====================================================
template <class T>
int HashTable<T>::get_slot_count(int slot)
{
    if (slot < 0 || slot >= size) // check if slot is invalid
        return 0;

    int count = 0; // initialize count

    if (size == 0) // number of items is 0 if table's size is 0
        return 0;

    Element<T>* current = table[slot]; // make a pointer to point to the slot

    while (current != nullptr) // iterate while current does point to NULL
    {
        count++; // increment count
        current = current->next; // move to next node to keep counting
    }

    return count;
}