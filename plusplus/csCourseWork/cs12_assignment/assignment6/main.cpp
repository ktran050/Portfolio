//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 8 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date February 25th, 2015
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
#include <iostream>
#include "IntList.h"

using namespace std;

int main(){
    IntList op;
    op.push_front(817);
    op.push_front(573);
    op.push_front(556);
    op.push_front(467);
    op.push_front(352);
    op.push_front(25);
    op.push_back(25);
    op.push_back(26);
    cout << endl;
    
    op.display();
    cout << endl;
    
    // op.select_sort();
    op.display();
    cout << endl;
    
    return 0;
}