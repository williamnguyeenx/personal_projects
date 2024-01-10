// ================================================
// element.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-10-2023
// Implementation file of class template Element
// ================================================

#include <optional>
#include "element.h"
using namespace std;

// ================================================
// Element
// Initialize an empty element
// Precondition: None
// Postcondition: None
// Parameter: None
// Return: None
// ================================================

template <class T>
Element<T>::Element(void) {
    empty = true;                                           //set element's state to empty
}

// ================================================
// Element
// Create an element and copy the data and
// key value from inputted element
// Precondition: Exists the element to be copied
// Postcondition: Return a new element with the same data
// and key value as the inputted element
// Parameter: copied_element - element to be copied
// Return: None
// ================================================


template <class T>
Element<T>::Element(const Element<T> &copied_element) {
    empty = copied_element.empty;                           //copy the state of the element - empty or not
    prev = copied_element.prev;                             //copy the pointer pointing to previous element/head/NIL
    next = copied_element.next;                             //copy the pointer pointing to next element/NIL
    key = copied_element.key;                               //copy key value of inputted element
    data = copied_element.data;                             //copy the data of inputted element
}

// ================================================
// Element
// Create an element containing the inputted data
// and key value
// Precondition: None
// Postcondition: A new element containing data 
// and have a key value
// Parameter: 
//      inputData - the template data that 
//      the new element will hold
//      inputKey - key value of element in int
// Return: None
// ================================================

template <class T>
Element<T>::Element(T inputData,int inputKey) { 
    empty = false;                                          //set element's state to not emppty
    prev = NULL;                                            //set previous-element pointer to NIL
    next = NULL;                                            //set next-element pointer to NIL
    key = inputKey;                                         //Set key value to the element
    data = inputData;                                       //Import data into the element
}

// ================================================
// ~Element
// Deallocate an element
// Precondition: Exists an element 
// Postcondition: The targeted element is deallocated
// Parameter: None
// Return: None
// ================================================

template <class T>
Element<T>::~Element(void) {
    prev = NULL;                                            //set previous-element pointer to NIL
    next = NULL;                                            //set next-element pointer to NIL
}

// ================================================
// get_data
// Retrieve the data stored in the element
// Precondition: Element is empty or Element 
// contains data and its key value
// Postcondition: Return the element's numeric key value
// Parameter: None
// Return: The data contain in the targeted element, 0 if element is empty
// ================================================

template <class T>
T Element<T>::get_data() const { 
    if (empty == true){                                    //check to see if element is empty or not
        return 0;                                          //return 0 if element is empty
    }
    return data;                                           //return targeted element's data
}

// ================================================
// get_key
// Retrieve the key value of the element
// Precondition: Element is empty or Element 
// contains data and its key value
// Post Condition: Return the numerical key value 
// of targeted element
// Parameter: None
// Return: The numerical key value of target element
// ================================================

template <class T>
int Element<T>::get_key() const { 
    if (empty == true){                                    //check to see if element is empty or not
        return -1;                                         //return -1 if element is empty
    }
    return key;                                            //return targeted element's key value
}