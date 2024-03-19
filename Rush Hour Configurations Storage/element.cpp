//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// Element.cpp
// March 2024
// This file contains the class methods for the
// Element class.
//========================================================

#include "element.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

//========================================================
// define Element class
//========================================================

//========================================================
// Element
// default constructor
// Create an empty Element
// Parameter: None
// Return value: None
// Pre-condition: None
// Post-condition: Element object created
//========================================================
template    <class T>
Element<T>::Element( void ) 
{
    key = -1;
    data = T();
    next = nullptr;
    prev = nullptr;
}

//========================================================
// Element
// default constructor
// Create an empty Element
// Parameter: None
// Return value: None
// Pre-condition: None
// Post-condition: Element object created
//========================================================
template    <class T>
Element<T>::Element( T data_input, int key_input ) 
{
    key = key_input;
    data = data_input;
    next = nullptr;
    prev = nullptr;
}

//========================================================
// Element
// copy constructor
// Create a Element and copy elements from an existing Element
// Parameter: const Element<T> &e - Object's elements to be copied
//            int k - key of element
// Return value: None
// Pre-condition: Exists an Element object
// Post-condition: Created a copy of the existing Element object
//========================================================
template    <class T>
Element<T>::Element( const Element<T> &e ) 
{
    key = e.key;
    // data = new T(*(e.data)); //Use deep copy to copy key and data
    data = e.data;
    next = e.next;
    prev = e.prev;
}

//========================================================
// ~Element
// Destructor
// Parameter: None
// Return value: None
// Pre-condition: Exist a Element object
// Post-condition: Element object deallocated
//========================================================
template <class T>
Element<T>::~Element( void )
{
}

// //========================================================
// // assignment operator
// // Create a new Element from the current Element by copying current
// // values and deleting the current Element
// // Parameter: reference call to Element e - object to be copied
// // Return value: a Element object
// // Pre-condition: Exist a Element object
// // Post-condition: Created a copy of the existing Element object
// //========================================================
// template <class T>
// Element<T> Element<T>::operator= ( const Element<T> &e )
// {
//     if (this != &e)
//     {
//         if(data != nullptr) //prevents deleting nullptr
//             delete data;
//     }
//     key = e.key;
//     data = new T(*(e.data)); // Use deep copy here

//     return *this;
// }

//========================================================
// get_key
// Parameter: None
// Return value: Element's key
// Pre-condition: Exist a Element object
// Post-condition: Return key of an Element
//========================================================
template <class T>
int     Element<T>::get_key( void ) const
{
    return key;
}

//========================================================
// get_data
// Parameter: None
// Return value: Element's data
// Pre-condition: Exist a Element object
// Post-condition: Return data of an Element
//========================================================
template <class T>
T     Element<T>::get_data( void ) const
{
    return data;
}