//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 7 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date February 16th, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 023
/// @par
///     TA: Brian
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
//Create a class of vectors containing ints
//Call it IntVector
//Private Data
//-unsigned sz
//-unsigned cap
//-int *
//Public Data
//IntVector();
//IntVector(unsigned size);
//IntVector( unsigned size, int value)
//unsigned size()const
//unsigned capacity() const
//bool empty() const
//const int &at(unsigned index) const
#include <iostream>
#include <cstdlib>
#include "IntVector.h"

using namespace std;

IntVector::IntVector(){
    sz = 0;
    cap = 0;
    data = NULL;
}
IntVector::IntVector(unsigned size){
    sz = size;
    cap = size;
    data = new int[size]();
}
IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for(int q = 0; q < size; ++q){
        data[q] = value;
    }
}

unsigned IntVector::size() const{
    return sz;
}
unsigned IntVector::capacity() const{
    return cap;
}
bool IntVector::empty() const{
    if(sz > 0){
        return 0;
    }
    else{
        return 1;
    }
}
const int & IntVector::at(unsigned index) const{
    //returns value at parameter index
    if(index >= sz){
        exit(1);
    }
    //exit the program if the value is greater than sz
    else{
        return this->data[index];
    }
}