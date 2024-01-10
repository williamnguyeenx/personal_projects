// ================================================
// test_hashtable_example.cpp
// Author: Niranjan Reji, Khoa Nguyen, Phuc Nguyen
// Date: 10-02-2023
// Last Update: 10-09-2023
// Test file for correctness of 
// class template Element, HashTable, and usecase.cpp
// ================================================

#include "element.cpp"
#include "hash_table.cpp"
#include "usecase.cpp"
#include <string>
#include <iostream>

using namespace std;

//this is for floating point test cases, to account for their lack of precision when making direct comparisons.
float tolerance = 1e-6;

void test_get_key() {
    try {
        //empty element
        Element<int> e;
        if(e.get_key()!=-1){cout << "Incorrect result from get key. Expected -1 but got : " << e.get_key() << endl;}

        //int element
        Element<int> e_int(10, 6);
        if(e_int.get_key()!=6){cout << "Incorrect result from get key. Expected 6 but got : " << e_int.get_key() << endl;}
        Element<int> e_int2(10, 8);
        if(e_int2.get_key()!=8){cout << "Incorrect result from get key. Expected 8 but got : " << e_int2.get_key() << endl;} 
        Element<int> e_int3(10, 0);
        if(e_int3.get_key()!=0){cout << "Incorrect result from get key. Expected 0 but got : " << e_int3.get_key() << endl;}

        //string element
        Element<string> e_string("hi", 6);
        if(e_string.get_key()!=6){cout << "Incorrect result from get key. Expected 6 but got : " << e_string.get_key() << endl;}
        Element<string> e_string2("hi", 0);
        if(e_string2.get_key()!=0){cout << "Incorrect result from get key. Expected 0 but got : " << e_string2.get_key() << endl;}
        Element<string> e_string3("hi", 1);
        if(e_string3.get_key()!=1){cout << "Incorrect result from get key. Expected 1 but got : " << e_string3.get_key() << endl;}
       
        //bool element
        Element<bool> e_bool1(false, 2);
        if(e_bool1.get_key()!=2){cout << "Incorrect result from get key. Expected 2 but got : " << e_bool1.get_key() << endl;}
        Element<bool> e_bool2(true, 0);
        if(e_bool2.get_key()!=0){cout << "Incorrect result from get key. Expected 0 but got : " << e_bool2.get_key() << endl;}
        Element<bool> e_bool3(false, 14);
        if(e_bool3.get_key()!=14){cout << "Incorrect result from get key. Expected 1 but got : " << e_bool3.get_key() << endl;}
        
        //char element
        Element<char> e_char('a', 1);
        if(e_char.get_key()!=1){cout << "Incorrect result from get key. Expected 1 but got : " << e_char.get_key() << endl;}
        Element<char> e_char1('a', 0);
        if(e_char1.get_key()!=0){cout << "Incorrect result from get key. Expected 0 but got : " << e_char1.get_key() << endl;}
        Element<char> e_char2('a', 34);
        if(e_char2.get_key()!=34){cout << "Incorrect result from get key. Expected 34 but got : " << e_char2.get_key() << endl;}

        //float element
        Element<float> e_float(4.2, 7);
        if(e_float.get_key()!=7){cout << "Incorrect result from get key. Expected 7 but got : " << e_float.get_key() << endl;}
        Element<float> e_float2(4.2, 0);
        if(e_float2.get_key()!=0){cout << "Incorrect result from get key. Expected 0 but got : " << e_float2.get_key() << endl;}
        Element<float> e_float3(4.2, 13);
        if(e_float3.get_key()!=13){cout << "Incorrect result from get key. Expected 13 but got : " << e_float3.get_key() << endl;}
    
    } catch(exception& e) {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
       
}

void test_get_data() {
    try {
         //empty elements for all types
        Element<int> e;
        if(e.get_data()!=0){cout << "Incorrect result from get data. Expected 0 but got : " << e.get_data() << endl;}
        Element<bool> g;
        if(g.get_data()!=false){cout << "Incorrect result from get data. Expected false but got : " << g.get_data() << endl;}
        Element<float> h;
        if(h.get_data()!=0.0){cout << "Incorrect result from get data. Expected 0.0 but got : " << h.get_data() << endl;}
        
        //int element
        Element<int> e_int(10, 6);
        if(e_int.get_data()!=10){cout << "Incorrect result from get data. Expected 10 but got : " << e_int.get_data() << endl;}
        Element<int> e_int1(25, 6);
        if(e_int1.get_data()!=25){cout << "Incorrect result from get data. Expected 25 but got : " << e_int1.get_data() << endl;}
        Element<int> e_int2(13, 6);
        if(e_int2.get_data()!=13){cout << "Incorrect result from get data. Expected 13 but got : " << e_int2.get_data() << endl;}

        //string element
        Element<string> e_string("hi", 6);
        if(e_string.get_data()!="hi"){cout << "Incorrect result from get data. Expected 'hi' but got : " << e_string.get_data() << endl;}
        Element<string> e_string1("haaaaaa", 6);
        if(e_string1.get_data()!="haaaaaa"){cout << "Incorrect result from get data. Expected 'haaaaaa' but got : " << e_string1.get_data() << endl;}
        Element<string> e_string2("hhhha", 6);
        if(e_string2.get_data()!="hhhha"){cout << "Incorrect result from get data. Expected 'hhhha' but got : " << e_string1.get_data() << endl;}
        Element<string> e_string3("hhhhaaaa", 6);
        if(e_string3.get_data()!="hhhhaaaa"){cout << "Incorrect result from get data. Expected 'hhhhaaaa' but got : " << e_string1.get_data() << endl;}
    
        //bool element
        Element<bool> e_bool(false, 2);
        if(e_bool.get_data()!=false){cout << "Incorrect result from get data. Expected false but got : " << e_bool.get_data() << endl;}
        Element<bool> e_bool2(true, 2);
        if(e_bool2.get_data()!=true){cout << "Incorrect result from get data. Expected true but got : " << e_bool2.get_data() << endl;}

        //char element
        Element<char> e_char('a', 1);
        if(e_char.get_data()!='a'){cout << "Incorrect result from get data. Expected 'a' but got : " << e_char.get_data() << endl;}
        Element<char> e_char2('b', 1);
        if(e_char2.get_data()!='b'){cout << "Incorrect result from get data. Expected 'b' but got : " << e_char2.get_data() << endl;}
        Element<char> e_char3('2', 1);
        if(e_char3.get_data()!='2'){cout << "Incorrect result from get data. Expected '2' but got : " << e_char3.get_data() << endl;}
        Element<char> e_char4('5', 1);
        if(e_char4.get_data()!='5'){cout << "Incorrect result from get data. Expected '5' but got : " << e_char4.get_data() << endl;}

        //float element
        //floating points are imprecise! when we simply insert float data into an element and compare it with the float value we inserted when we return,
        //because of very small differences between both values, we get a false positive error. because of that, we add in a tolerance value
        //that we picked arbitrarily, and simply check if the float value returned is within the value we inserted +- the tolerance value.
        //the tolerance value is defined at the top of our program. We chose it arbitrarily.
        Element<float> e_float(6.6, 7);
        if(e_float.get_data() > (6.6 + tolerance) || e_float.get_data() < (6.6 - tolerance)){cout << "Incorrect result from get data. Expected 6.6 but got : " << e_float.get_data() << endl;}
        Element<float> e_float2(0.0, 7);
        if(e_float2.get_data() > (0.0 + tolerance) || e_float2.get_data() < (0.0 - tolerance)){cout << "Incorrect result from get data. Expected 6.6 but got : " << e_float2.get_data() << endl;}
        Element<float> e_float3(3.4, 7);
        if(e_float3.get_data() > (3.4 + tolerance) || e_float3.get_data() < (3.4 - tolerance)){cout << "Incorrect result from get data. Expected 6.6 but got : " << e_float3.get_data() << endl;}

    
    } catch(exception& e) {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert() {
    try {
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if(empty_ht.to_string()!="") {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }
    } catch(exception& e) {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if(ht.to_string()!="0: \n1: (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.insert(1, 21);
        if(ht.to_string()!="0: \n1: (1,21) (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht.insert(0, 0);
        if(ht.to_string()!="0: (0,0) \n1: (1,21) (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht.insert(12, 12);
        if(ht.to_string()!="0: (0,0) \n1: (1,21) (10,6) \n2: (12,12) \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht.insert(7, 13);
        if(ht.to_string()!="0: (0,0) \n1: (1,21) (10,6) \n2: (12,12) \n3: (7,13) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht.insert(15, 14);
        if(ht.to_string()!="0: (0,0) \n1: (1,21) (10,6) \n2: (12,12) \n3: (7,13) \n4: (15,14) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht.insert(27, 14);
        if(ht.to_string()!="0: (0,0) \n1: (1,21) (10,6) \n2: (12,12) \n3: (7,13) \n4: (27,14) (15,14) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }

    try {
        HashTable<string> ht2(5);
        ht2.insert("hi", 6);
        if(ht2.to_string()!="0: \n1: (hi,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (hi,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht2.to_string() << endl;
        }
        ht2.insert("hhii", 1);
        if(ht2.to_string()!="0: \n1: (hhii,1) (hi,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht2.insert("hhhii", 0);
        if(ht2.to_string()!="0: (hhhii,0) \n1: (hhii,1) (hi,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht2.insert("hihih", 12);
        if(ht2.to_string()!="0: (hhhii,0) \n1: (hhii,1) (hi,6) \n2: (hihih,12) \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht2.insert("hiiii", 13);
        if(ht2.to_string()!="0: (hhhii,0) \n1: (hhii,1) (hi,6) \n2: (hihih,12) \n3: (hiiii,13) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht2.insert("hhhhi", 14);
        if(ht2.to_string()!="0: (hhhii,0) \n1: (hhii,1) (hi,6) \n2: (hihih,12) \n3: (hiiii,13) \n4: (hhhhi,14) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht2.insert("h", 24);
        if(ht2.to_string()!="0: (hhhii,0) \n1: (hhii,1) (hi,6) \n2: (hihih,12) \n3: (hiiii,13) \n4: (h,24) (hhhhi,14) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        } 

    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }

    try {
        HashTable<char> ht3(5);
        ht3.insert('a', 0);
        if(ht3.to_string()!="0: (a,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (a,0) \n2: \n3: \n4: \n\nBut got\n\n" << ht3.to_string() << endl;
        }
        ht3.insert('a', 10);
        if(ht3.to_string()!="0: (a,10) (a,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        ht3.insert('b', 3);
        if(ht3.to_string()!="0: (a,10) (a,0) \n1: \n2: \n3: (b,3) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        ht3.insert('c', 13);
        if(ht3.to_string()!="0: (a,10) (a,0) \n1: \n2: \n3: (c,13) (b,3) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        ht3.insert('d', 4);
        if(ht3.to_string()!="0: (a,10) (a,0) \n1: \n2: \n3: (c,13) (b,3) \n4: (d,4) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        ht3.insert('3', 2);
        if(ht3.to_string()!="0: (a,10) (a,0) \n1: \n2: (3,2) \n3: (c,13) (b,3) \n4: (d,4) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        // ht3.insert('0', 1);
        // if(ht3.to_string()!="0: (a,10) (a,0) \n1: (0,1) \n2: (3,2) \n3: (c,13) (b,3) \n4: (d,4) \n") {
        //     cout << "Incorrect result of inserting into table" << endl;
        // }

    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
    
    try {
        HashTable<bool> ht4(5);
        ht4.insert(true, 0);
        if(ht4.to_string()!="0: (1,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: (1,0) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht4.to_string() << endl;
        }
        ht4.insert(true, 10);
        if(ht4.to_string()!="0: (1,10) (1,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        ht4.insert(false, 3);
        if(ht4.to_string()!="0: (1,10) (1,0) \n1: \n2: \n3: (0,3) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht4.insert(false, 13);
        if(ht4.to_string()!="0: (1,10) (1,0) \n1: \n2: \n3: (0,13) (0,3) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht4.insert(true, 4);
        if(ht4.to_string()!="0: (1,10) (1,0) \n1: \n2: \n3: (0,13) (0,3) \n4: (1,4) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht4.insert(true, 2);
        if(ht4.to_string()!="0: (1,10) (1,0) \n1: \n2: (1,2) \n3: (0,13) (0,3) \n4: (1,4) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht4.insert(false, 1);
        if(ht4.to_string()!="0: (1,10) (1,0) \n1: (0,1) \n2: (1,2) \n3: (0,13) (0,3) \n4: (1,4) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }

    try {
        HashTable<float> ht5(5);
        ht5.insert(1.25, 21);
        if(ht5.to_string()!="0: \n1: (1.25,21) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: (1.25,21) \n2: \n3: \n4: \n\nBut got\n\n" << ht5.to_string() << endl;
        }
        ht5.insert(1.5, 6);
        if(ht5.to_string()!="0: \n1: (1.5,6) (1.25,21) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht5.insert(0.5, 10);
        if(ht5.to_string()!="0: (0.5,10) \n1: (1.5,6) (1.25,21) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht5.insert(0.0, 0);
        if(ht5.to_string()!="0: (0,0) (0.5,10) \n1: (1.5,6) (1.25,21) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht5.insert(19.25, 13);
        if(ht5.to_string()!="0: (0,0) (0.5,10) \n1: (1.5,6) (1.25,21) \n2: \n3: (19.25,13) \n4: \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }
        ht5.insert(2.75, 14);
        if(ht5.to_string()!="0: (0,0) (0.5,10) \n1: (1.5,6) (1.25,21) \n2: \n3: (19.25,13) \n4: (2.75,14) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

        ht5.insert(3.75, 24);
        if(ht5.to_string()!="0: (0,0) (0.5,10) \n1: (1.5,6) (1.25,21) \n2: \n3: (19.25,13) \n4: (3.75,24) (2.75,14) \n") {
            cout << "Incorrect result of inserting into table" << endl;
        }

    } catch(exception& e) {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if(empty_ht.to_string()!="") {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n" << empty_ht.to_string() << endl;
        }
    } catch(exception& e) {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        ht.remove(5);
        if(ht.to_string()!="0: \n1: (10,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.remove(6);
        if(ht.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.remove(6); //removing twice
        if(ht.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.insert(10, 0);
        ht.remove(0); //removing at head
        if(ht.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.insert(10, 0);
        ht.insert(10, 4);
        ht.remove(4); //removing at tail and removing if there is a duplicate value
        if(ht.to_string()!="0: (10,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: (10,4) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }
        ht.remove(-1); //removing negative
        if(ht.to_string()!="0: (10,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: (10,4) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht.to_string() << endl;
        }

        HashTable<string> ht_str(5);
        ht_str.insert("hi", 6);
        ht_str.remove(5);
        if(ht_str.to_string()!="0: \n1: (hi,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_str.to_string() << endl;
        }
        ht_str.remove(6);
        if(ht_str.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_str.to_string() << endl;
        }
        ht_str.remove(6); //removing twice
        if(ht_str.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_str.to_string() << endl;
        }
        ht_str.insert("cs 1111", 0);
        ht_str.remove(0); //removing at head
        if(ht_str.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_str.to_string() << endl;
        }
        ht_str.insert("cs 1111", 0);
        ht_str.insert("cs 1111", 4);
        ht_str.remove(4); //removing at tail and removing if there is a duplicate value
        if(ht_str.to_string()!="0: (cs 1111,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: (10,4) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_str.to_string() << endl;
        }

        HashTable<bool> ht_bool(5);
        ht_bool.insert(true, 6);
        ht_bool.remove(5);
        if(ht_bool.to_string()!="0: \n1: (1,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (1,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_bool.to_string() << endl;
        }
        ht_bool.remove(6);
        if(ht_bool.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_bool.to_string() << endl;
        }
        ht_bool.remove(6); //removing twice
        if(ht_bool.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_bool.to_string() << endl;
        }
        ht_bool.insert(false, 0);
        ht_bool.remove(0); //removing at head
        if(ht_bool.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_bool.to_string() << endl;
        }
        ht_bool.insert(false, 0);
        ht_bool.insert(false, 4);
        ht_bool.remove(4); //removing at tail and removing if there is a duplicate value
        if(ht_bool.to_string()!="0: (0,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: (10,4) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_bool.to_string() << endl;
        }

        HashTable<char> ht_char(5);
        ht_char.insert('h', 6);
        ht_char.remove(5);
        if(ht_char.to_string() != "0: \n1: (h,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_char.to_string() << endl;
        }
        ht_char.remove(6);
        if(ht_char.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_char.to_string() << endl;
        }
        ht_char.remove(6); //removing twice
        if(ht_char.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_char.to_string() << endl;
        }
        ht_char.insert('c', 0);
        ht_char.remove(0); //removing at head
        if(ht_char.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_char.to_string() << endl;
        }
        ht_char.insert('c', 0);
        ht_char.insert('c', 4);
        ht_char.remove(4); //removing at tail and removing if there is a duplicate value
        if(ht_char.to_string()!="0: (c,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: (10,4) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_char.to_string() << endl;
        }

        HashTable<float> ht_float(5);
        ht_float.insert(4.2, 6);
        ht_float.remove(5);
        if(ht_float.to_string() != "0: \n1: (4.2,6) \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_float.to_string() << endl;
        }
        ht_float.remove(6);
        if(ht_float.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_float.to_string() << endl;
        }
        ht_float.remove(6); //removing twice
        if(ht_float.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n" << ht_float.to_string() << endl;
        }
        ht_float.insert(6.1, 0);
        ht_float.remove(0); //removing at head
        if(ht_float.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_float.to_string() << endl;
        }
        ht_float.insert(6.44, 0);
        ht_float.insert(6.44, 4);
        ht_float.remove(4); //removing at tail and removing if there is a duplicate value
        if(ht_float.to_string()!="0: (6.44,0) \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: (10,4) \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht_float.to_string() << endl;
        }




    } catch(exception& e) {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht2(5);
        ht2.insert(10, 6);
        ht2.remove(6);
        if(ht2.to_string()!="0: \n1: \n2: \n3: \n4: \n") {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n" << ht2.to_string() << endl;
        }
    } catch(exception& e) {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

void test_member() {
    try {
        HashTable<int> empty_ht(0);
        if(empty_ht.member(10, 6)) {cout << "Incorrect membership in empty table" << endl;}
    } catch(exception& e) {
        cout << "Error caused by trying to determine membership in empty table : " << e.what() << endl;
    }
    try {
        HashTable<int> ht(5);
        ht.insert(10, 6);
        if(ht.member(11, 6)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht.member(10, 6)){cout << "Element in table, but function returned false" << endl;}
        ht.insert(12, 0);
        if(ht.member(12, 1)){cout << "Element not in table, but function returned true" << endl;}
        if(ht.member(12, 2)){cout << "Element not in table, but function returned true" << endl;}
        if(ht.member(12, 3)){cout << "Element not in table, but function returned true" << endl;}
        if(ht.member(12, 4)){cout << "Element not in table, but function returned true" << endl;}
        if(ht.member(12, 5)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht.member(12, 0)){cout << "Element in table, but function returned false" << endl;}
        ht.insert(12, 1);
        if(ht.member(12, 2)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht.member(12, 0)){cout << "Element in table, but function returned false" << endl;}
        if(!ht.member(12, 1)){cout << "Element in table, but function returned false" << endl;}
        ht.insert(13, 1);
        ht.insert(17,1);
        if(ht.member(14, 1)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht.member(13, 1)){cout << "Element in table, but function returned false" << endl;}
        if(!ht.member(12, 1)){cout << "Element in table, but function returned false" << endl;}
        if(!ht.member(17, 1)){cout << "Element in table, but function returned false" << endl;}
        if(ht.member(14, -1)){cout << "Element not in table, but function returned true" << endl;}
        if(ht.member(13, -2)){cout << "Element not in table, but function returned true" << endl;}
        if(ht.member(12, -2)){cout << "Element not in table, but function returned true" << endl;}

        HashTable<float> ht2(5);
        ht2.insert(10.2, 6);
        if(ht2.member(11.2, 6)){cout << "Element not in table, but function returned true" << endl;}
        if(ht2.member(10.2, 1)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht2.member(10.2, 6)){cout << "Element in table, but function returned false" << endl;}
        ht2.insert(12.1, 0);
        if(ht2.member(12.66, 1)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht2.member(12.1, 0)){cout << "Element in table, but function returned false" << endl;}
        ht2.insert(12.1, 1);
        if(ht2.member(12.2, 2)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht2.member(12.1, 0)){cout << "Element in table, but function returned false" << endl;}
        if(!ht2.member(12.1, 1)){cout << "Element in table, but function returned false" << endl;}
        ht2.insert(13.4, 1);
        if(ht2.member(14.22, 1)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht2.member(13.4, 1)){cout << "Element in table, but function returned false" << endl;}
        if(!ht2.member(12.1, 1)){cout << "Element in table, but function returned false" << endl;}

        HashTable<char> ht_char(5);
        ht_char.insert('a', 6);
        if(ht_char.member('b', 6)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht_char.member('a', 6)){cout << "Element in table, but function returned false" << endl;}
        
        ht_char.insert('b', 99);
        if(ht_char.member('b', 1)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht_char.member('b', 99)){cout << "Element in table, but function returned false" << endl;}

        ht_char.insert('b', 1);
        if(!ht_char.member('b', 99)){cout << "Element in table, but function returned false" << endl;}
        if(!ht_char.member('b', 1)){cout << "Element in table, but function returned false" << endl;}

        ht_char.insert('c', 0);
        ht_char.insert('c', 6);
        ht_char.insert('c', 7);
        ht_char.insert('c', 8);
        ht_char.insert('c', 9);
        ht_char.insert('c', 10);
        if(ht_char.member('c', 1)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_char.member('c', 2)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_char.member('c', 3)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_char.member('c', 4)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_char.member('c', 5)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht_char.member('c', 0)){cout << "Element in table, but function returned false" << endl;}
        if(!ht_char.member('c', 6)){cout << "Element in table, but function returned false" << endl;}
        if(!ht_char.member('c', 7)){cout << "Element in table, but function returned false" << endl;}
        if(!ht_char.member('c', 8)){cout << "Element in table, but function returned false" << endl;}
        if(!ht_char.member('c', 9)){cout << "Element in table, but function returned false" << endl;}
        if(!ht_char.member('c', 10)){cout << "Element in table, but function returned false" << endl;}
        if(ht_char.member('c', -1)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_char.member('c', 9999)){cout << "Element not in table, but function returned true" << endl;}

        HashTable<bool> ht_bool(5);
        ht_bool.insert(true, 6);
        if(ht_bool.member(false, 6)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht_bool.member(true, 6)){cout << "Element in table, but function returned false" << endl;}
        if(ht_bool.member(false, 0)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_bool.member(false, 1)){cout << "Element not in table, but function returned true" << endl;}

         HashTable<string> ht_str(5);
        ht_str.insert("cs is cool", 6);
        if(ht_str.member("cs is not cool", 6)){cout << "Element not in table, but function returned true" << endl;}
        if(!ht_str.member("cs is cool", 6)){cout << "Element in table, but function returned false" << endl;}
        if(ht_str.member("cs is not cool", 0)){cout << "Element not in table, but function returned true" << endl;}
        if(ht_str.member("cs is not cool", 1)){cout << "Element not in table, but function returned true" << endl;}
        


    } catch(exception& e) {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
}

void test_login() {
    try {
        HashTable<string>* ht = create_table<string>("logins.csv", 10);
        string username = "IEv";
        string password = "7170790290";
        if(!login(ht, username, password)){cout << "Incorrect result validating accurate login information" << endl;}
        username = "bad-user";
        password = "98213873";
        if(login(ht, username, password)){cout << "Incorrect result validating inaccurate login information" << endl;}
        username = "";
        password = "";
        if(login(ht, username, password)){cout << "Incorrect result validating blank login information" << endl;}
        username = "";
        password = "ee";
        if(login(ht , username, password)){cout << "Incorrect result validating blank username information" << endl;}
        username = "ee";
        password = "";
        if(login(ht, username, password)){cout << "Incorrect result validating blank password information" << endl;}
    } catch(exception& e) {
        cerr << "Error in accomplishing login validation : " << e.what() << endl;
    }
}

int main() {
    test_get_key();
    cout << "test_get_key complete" << endl;
    test_get_data();
    cout << "test_get_data complete" << endl;
    test_insert();
    cout << "test_insert complete" << endl;
    test_remove();
    cout << "test_remove complete" << endl;
    test_member();
    cout << "test_member complete" << endl;
    test_login();
    cout << "Testing completed" << endl;
    
    return 0;
}