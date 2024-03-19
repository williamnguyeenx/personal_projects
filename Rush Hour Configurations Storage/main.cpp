//========================================================
// William Nguyen, Cheryl Nguyen, Phan Anh Le
// main.cpp
// March 2024
// This file contains the test for Board.cpp 
//========================================================
#include "Board.h"
#include "hash_table.cpp" 
#include "element.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <vector> 
#include <numeric>
#include <algorithm>
#include <cmath> 
using namespace std;

int main(int argc, char* argv[]) {
    if ( argc != 2 ) {
        printf("Error: you must include the hash table size as a");
        printf(" command-line parameter.\n");
        exit(0);
    }
    int size = atoi(argv[1]);

    HashTable<Board> table(size);

    Board b; // used to store the boards being read
    cin >> b;
    
    int hash = 0;
    int number = 0; 

    while (!cin.eof()) {
        hash = b.getHashValue(size);
        if (table.member(b, hash) == false) {
            number++; // Increment for each unique board inserted
            table.insert(b, hash);
            
        }
        cout << "Read in board: \n";     // comment this out later
        cout << b;
        cin >> b;
    };

    int min = table.get_slot_count(0); 
    int max = min;
    int counts;

    for (int i = 1; i < size; i++) { // Start from 1 since min and max are already initialized to the count of slot 0
        int counts = table.get_slot_count(i);
        cout << counts << endl;
        counts += number;
        if(counts < min)
            min = counts; 
        if (counts > max)
            max = counts; 
    }
    double average = float((number)/ size);
    double loadFactor = average; // Load factor is equivalent to average in this context
    double standard_deviation; 

    for (int i = 0; i < size; i++)
    { 
        int counts = table.get_slot_count(i); 
        standard_deviation += (counts-average)*(counts-average); 
    }

    double stdev = sqrt(standard_deviation/size);

    cout << number << endl;
    cout << "The total number of unique items stored in the table is " << number << endl;
    cout << "The average number of items in each slot in the table is " << average << endl;
    cout << "The slot count for the minimum number of items in a slot is " << min << endl;
    cout << "The slot count for the maximum number of items in a slot is " << max << endl;   
    cout << "The standard deviation of the number of items in each slot is " << stdev << endl; 
    cout << "The load factor is " << loadFactor << endl; 
    return 0;
}
