//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// element.h
// March 2024
// This file contains the Element class declaration.  
//========================================================


#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>
using namespace std;

template <class T>
class Element
{
private:
	int     key; // unique key for element
    T       data; // data stored in element

public:
                    Element* next;
                    Element* prev;
                    Element         ( void );
                    Element         ( T data_input, int key_input );
                    Element			( const Element<T> &e );
                    ~Element        ( void );
    // Element<T>		operator=		( const Element<T> &e );
    int             get_key         ( void ) const;
    T               get_data        ( void ) const;

// ==========================================================================================
// Overloads the << operator to provide a way to print the Set contents to an output stream.
// This function is declared as a friend within the Elemement class so it can access 
// private members of Element.
// Parameters:
// - os: A reference to the ostream object where the Element elements will be sent (e.g., std::cout)
// - e: A constant reference to the Element object to be printed
// Return Value: A reference to the ostream object to allow chaining of << operator calls
// ==========================================================================================
friend std::ostream& operator<<(std::ostream &os, const Element<T> &e) {
        os << "Key: " << e.key << ", Data: " << e.data;
        return os;
    }
};

#endif
