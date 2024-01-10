// ================================================
// element.h
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-10-2023
// Header file for class template Element
// ================================================

#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
template <class T> 
class Element
{
    public:
        bool empty;
        T data;                                             //class T data
        Element* prev;                                      //pointer to point to previous element/head/NIL
        Element* next;                                      //pointer to point to next element/NIL
        int key;                                            //element's key value
        Element(void);                                      //constructor
        ~Element(void);                                     //destructor
        Element(const Element<T> &copied_element);          //copy constructor from another element
        Element(T inputData, int inputKey);                 //constructor with data and a key value
        int get_key() const;                                //get numeric value stored inside element
        T get_data() const;                                 //get data stored inside element
};  