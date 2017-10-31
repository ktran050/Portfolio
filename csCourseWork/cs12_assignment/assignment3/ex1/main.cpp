//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Assignment 3 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 27th, 2015
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
#include <string>
#include "Date.h"

using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    Date q(1,1,2000);
    q.addDays(1).printNumeric();
    cout << endl;
    return 0;
}

void test1(){
    cout << "1. Default" << endl;
    Date x = Date();
    cout << "numeric:\t";
    x.printNumeric(); cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------------------" << endl;
}

void test2(){
    cout << "2. Numeric Date: 7.3.1991" << endl;
    Date x = Date(7,3,1991);
    cout << "numeric:\t";
    x.printNumeric(); cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------------------" << endl;
}

void test3(){
    cout << "3. Alpha Date: July 3, 1991" << endl;
    Date x = Date("July", 3, 1991);
    cout << "numeric:\t";
    x.printNumeric(); cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------------------" << endl;
}

void test4(){
    cout << "4. Invalid Numeric Date: 0.3.1991 => 1.3.1991" << endl;
    Date x = Date(0,3,1991);
    cout << "numeric:\t";
    x.printNumeric(); cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------------------" << endl;
    
}

void test5(){
    cout << "5. Alpha Date: 1.adf.1991 => 1.1.2000" << endl;
    Date x= Date();
    cout << "numeric:\t";
    x.printNumeric(); cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------------------" << endl;
}

void test6(){
    cout << "6. Invalid Numeric Date: 2.29.1500" << endl;
    Date x = Date(2,29,1500);
    cout << "numeric:\t";
    x.printNumeric(); cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "---------------------------------------" << endl;
}