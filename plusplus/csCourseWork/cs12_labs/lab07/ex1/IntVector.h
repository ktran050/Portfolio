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
#ifndef __IntVector__
#define __IntVector__

#include <iostream>
#include <cstdlib>

using namespace std;

class IntVector{
    private:
    unsigned sz;
    unsigned cap;
    int *data;
    
    public:
    IntVector();
    IntVector(unsigned size);
    IntVector(unsigned size, int value);
    unsigned size() const;
    unsigned capacity() const;
    bool empty() const;
    const int & at(unsigned index) const;
    
};

#endif