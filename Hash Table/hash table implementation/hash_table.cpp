// ================================================
// hash_table.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-10-2023
// Implementation file of class template Hashtable
// ================================================

#include <iostream>
#include <typeinfo>
#include <sstream>
#include "hash_table.h"
#include "element.h"
#include <string>
#include <math.h>
using namespace std;

// ================================================
// HashTable
// Create an instance of class HashTable
// Pre-condition: None
// Post-condition: A new hash table
// Parameter: None
// Return: None
// ================================================

template <class T>
HashTable<T>::HashTable() {
    hashTable = new Element<T>*[10];                   //initialize an array of pointers of class template Element
    size = 10;                                         //set the size of the array
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();           //initialize an element of class template Element
        hashTable[i] = item;                           //pointer at index i points to the newly initilized element
    }
}

// ================================================
// HashTable
// Create an instance of class HashTable with 'len' slots
// Pre-condition: Called with a positive integer len passed in as an argument
// Post-condition: A new hash table with 'len' slots is created
// Parameter: len - number of slots that the hash table will have
// Return: None
// ================================================

template <class T>
HashTable<T>::HashTable(int len) {
    if (len < 0) {                                                              //check if len is valid
        throw std::runtime_error("Negative size for hash table not allowed.");  //if len is not valid then throw error
    }
    hashTable = new Element<T>*[len];                                           //initialize an array of pointers
    size = len;                                                                 //set the hash table's number of slots
    for (int i = 0; i < size; i++) {
        Element<T>* item = new Element<T>();                                    //initialize an element of class template Element
        hashTable[i] = item;                                                    //pointer at index i points to newly initilized element
    }
}

// ================================================
// insert
// Insert an element into the Hash Table
// Pre-condition: Exists a HashTable; 
//                element must have key that is in range 
//                of the Hash Table
// Post-condition: HashTable contains the new element
// Parameter: T data - the data of element to be inserted
//            int key - the key value of element to be inserted
// Return: None
// ================================================

template <class T>
void HashTable<T>::insert(T data, int key) {
    int hashVal = h(key);                               //get hash value of key 'key'   
    if (validIndex(hashVal)) {                          //check if the key is valid or not, if not then do nothing, else proceed
        Element<T>* node = new Element<T>(data, key);   //pointer points to a new element containing inputted data and key value
        node->next = hashTable[hashVal];                //add the new element to the start of the linked list, connect with the previous first element
        node->prev = nullptr;                           //set new element's previous pointer to nil
        hashTable[hashVal]->prev = node;                //previous first element's prev pointer points to newly inserted element
        hashTable[hashVal] = node;                      //set the hash table's index at hashVal to point to the new element
    }
}

// ================================================
// remove
// Remove an element from HashTable
// Pre-condition: Exists a HashTable;
//                Exists the element at inputted key value
// Post-condiiton: HashTable no longer has the element
//                 at the inputted key value
// Parameter: int key - key value of the element
//                      to be removed
// Return: None
// ================================================

template <class T>
void HashTable<T>::remove(int key) {
    if (size == 0){
        return;
    }
    int hashVal = h(key);
    if (validIndex(hashVal) && hashTable[hashVal]->empty != true) {
        Element<T>* tempNode = hashTable[hashVal];
        while (tempNode->key != key){
            if (tempNode->next == nullptr){
                return;
            }
            tempNode = tempNode->next;
        }
        if (hashTable[hashVal] == tempNode){                            //remove at the start of linked list
            Element<T>* nextNode = tempNode->next;
            hashTable[hashVal] = nextNode;
            nextNode->prev = NULL;
        }else if (tempNode->next == nullptr){                           //remove at the end of linked list
            Element<T>* prevNode = tempNode->prev;
            prevNode->next = NULL;
        }
        else if (tempNode->next != NULL && tempNode->prev != NULL) {    //remove at the middle of linked list
            Element<T>* prevNode = tempNode->prev;
            Element<T>* nextNode = tempNode->next;
            prevNode->next = tempNode->next;
            nextNode->prev = tempNode->prev;
        } 
        delete tempNode;
        }
    return;
}

// ================================================
// validIndex
// Check if a hash table contains the inputted index value
// Pre-condition: Exists a hash table
// Post-condition: Return the index
// Parameter: int i - the index to be check if 
//                    it is in the hash table
// Return: the index if it is in the hash table
// ================================================

template <class T>
bool HashTable<T>::validIndex(int i) {
    return (i >= 0 && i < size);                    //if i is larger than 0 and smaller than array's size, then return i
}

// ================================================
// member
// Check if an element is in the hash table
// Pre-condition: Exists a hash table
// Post-condition: Return true if element to be
//                 check is in the hash table
//                 Else return false
// Parameter: T data - targeted element's data
//            int key - targeted element's key value
// Return: true if targeted element is in
//         the hash table, false otherwise
// ================================================

template <class T>
bool HashTable<T>::member(T data, int key) {
    int hashVal = h(key);
    bool ret = false;
    if (validIndex(hashVal)) {
        Element<T>* curr = hashTable[hashVal];
        while (!curr->empty) {
            if (curr->data == data && curr->key == key) {
                ret = true;
                break;
            }
            curr = curr->next;
        }
    }
    return ret;
}

// ================================================
// h
// Set hash value of key k
// Pre-condition: Exist a hash table with key at index k
// Post-condition: Return the hash value of key k
// Parameter: int k - a key value
// Return: Return the hash value of key k
// ================================================

template <class T>
int HashTable<T>::h(int k) {
    if (size == 0) {                                //check if hash table is empty
        return -1;                                  //if empty then return -1
    }
    else {
        return k%size;                             //return hash value of key k
    }
}

// ================================================
// to_string
// Convert data and key value of elements in the
// hash table into string
// Pre-condition: Exists the hash table;
// Post-condition: a string containing data and
//                 key value of all elements in 
//                 the hash table
// Parameter: None
// Return: the string a string containing data and
//         key value of all elements in the hash table
// ================================================

template <class T>
string HashTable<T>::to_string() {
    if (size == 0) return "";                                                   //check if hash table if empty, if empty then return an empty string
    stringstream out;                                                           //a stringstream object to temporarily hold element's data and key value
    for (int i = 0; i < size; i++) {                                            //for loop to go through elements in the hash table
        Element<T>* curr = hashTable[i];                                        //pointer points to element at key i
        out << i << ": ";                                                       //assign the pointer the stringstream object
        while (!curr->empty) {                                                  //while loop to traverse through the linked list at current key
            out << "(" << curr->get_data() << "," << curr->get_key() << ") ";   //retrieve the elements' data and key value
            curr = curr->next;                                                  //go to next element
        }
        out << endl;
    }
    return out.str();                                                           //convert the stringstream into string
}

// ================================================
// h_most_significant
// Set hash value of key k
// Pre-condition: Exist a hash table with key at index k
// Post-condition: Return the hash value of key k
// Parameter: int k - a key value
// Return: Return most significant k
// ================================================
template <class T>
int HashTable<T>::h_most_significant(int k) {
        int no_bits = floor(log2(k)) +1;
        int space = size;
        while (log2(space) != floor(log2(space))) {
            space--;
        }
        int shifts = log2(space);
        
        while (floor(log2(k)) + 1 >= shifts) {
            k = k >> shifts;
        }
        cout << k << " ";
        return k;
}

// ================================================
// insert_most_significant
// Insert an element into the Hash Table
// Pre-condition: Exists a HashTable; 
//                element must have key that is in range 
//                of the Hash Table
// Post-condition: HashTable contains the new element
// Parameter: T data - the data of element to be inserted
//            int key - the key value of element to be inserted
// Return: None
// ================================================

template <class T>
void HashTable<T>::insert_most_significant(T data, int key) {
    int hashVal = h_most_significant(key);              //get hash value of key 'key'   
    if (validIndex(hashVal)) {                          //check if the key is valid or not, if not then do nothing, else proceed
        Element<T>* node = new Element<T>(data, key);   //pointer points to a new element containing inputted data and key value
        node->next = hashTable[hashVal];                //add the new element to the start of the linked list, connect with the previous first element
        node->prev = nullptr;                           //set new element's previous pointer to nil
        hashTable[hashVal]->prev = node;                //previous first element's prev pointer points to newly inserted element
        hashTable[hashVal] = node;                      //set the hash table's index at hashVal to point to the new element
    }
}

// ================================================
// member_most_significant
// Check if an element is in the hash table
// Pre-condition: Exists a hash table
// Post-condition: Return true if element to be
//                 check is in the hash table
//                 Else return false
// Parameter: T data - targeted element's data
//            int key - targeted element's key value
// Return: true if targeted element is in
//         the hash table, false otherwise
// ================================================

template <class T>
bool HashTable<T>::member_most_significant(T data, int key) {
    int hashVal = h_most_significant(key);
    bool ret = false;
    if (validIndex(hashVal)) {
        Element<T>* curr = hashTable[hashVal];
        while (!curr->empty) {
            if (curr->data == data && curr->key == key) {
                ret = true;
                break;
            }
            curr = curr->next;
        }
    }
    return ret;
}

// ================================================
// h_most_significant
// Set hash value of key k
// Pre-condition: Exist a hash table with key at index k
// Post-condition: Return the hash value of key k
// Parameter: int k - a key value
// Return: Return most significant k
// ================================================

template <class T>
int HashTable<T>::h_cormen_multiplication(int k) {
    const float A = (sqrt(5)-1)/2;
    int m = pow(2,3);
    float temp = k*A;
    int result = floor(fmod(temp,1) * m);                                 //(k*A)%1 fractional part of k*A, m is a power of 2
    return result;
}

// ================================================
// insert_cormen_multiplication
// Insert an element into the Hash Table
// Pre-condition: Exists a HashTable; 
//                element must have key that is in range 
//                of the Hash Table
// Post-condition: HashTable contains the new element
// Parameter: T data - the data of element to be inserted
//            int key - the key value of element to be inserted
// Return: None
// ================================================

template <class T>
void HashTable<T>::insert_cormen_multiplication(T data, int key) {
    int hashVal = h_cormen_multiplication(key);                    //get hash value of key 'key'   
    if (validIndex(hashVal)) {                                     //check if the key is valid or not, if not then do nothing, else proceed
        Element<T>* node = new Element<T>(data, key);              //pointer points to a new element containing inputted data and key value
        node->next = hashTable[hashVal];                           //add the new element to the start of the linked list, connect with the previous first element
        node->prev = nullptr;                                      //set new element's previous pointer to nil
        hashTable[hashVal]->prev = node;                           //previous first element's prev pointer points to newly inserted element
        hashTable[hashVal] = node;                                 //set the hash table's index at hashVal to point to the new element
    }
}

// ================================================
// loadFactor
// Retrieve load factor of the hash table
// Pre-conditions: called on valid Hash Table object with non zero size
// Post-conditions: returns average load factor for hash table object
// Parameter: None
// Return: load factor of the hash table method is called on
// ================================================

template <class T>
float HashTable<T>::loadFactor() {
    float ret = 0.0;
    if (size == 0) return 0;                        //if hash table empty then return 0
    for (int i = 0; i < size; i++) {                //traverse through elements in the hash table
        Element<T>* curr = hashTable[i];
        while (!curr->empty) {                      //go through linked list of the current key
            ret = ret + 1;
            curr = curr->next;
        }
    }
    ret = ret/size;                                 //get the load factor
    return ret;
}
