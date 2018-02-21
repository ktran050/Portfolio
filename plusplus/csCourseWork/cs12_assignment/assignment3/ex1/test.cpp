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
//Build a date class and a test harness in main to test it
//magic numbers not allowed ( 1-12, 28-32 are ok)
//"January" - "December" are not "magic"

//Private fields:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//day- unsigned~~~~~~~~~~~~~~~`
//month- unsigned~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//month name -string~~~~~~~~~~~~~~~~~~~~~~~~~~~
//year -unsigned (not designed to work with BC)


//Public functions:
//date() -default January 1st, 2000 ~~~~~~~~~~~~~~~~~~~~~~~~
//date(unsigned mn, unsigned d, unsigned y)
//if the constructor finds an invalid month name cout
//"Invalid month name: the date was set to 1/1/2000" newline
//if the month is right but the day isnt, cout that as well
//constructor can recognize december and December

//date(unsignmed m, unsigned d, unsigned y)
//same but without month name

//void printNumeric() const ~~~~~~~~~~~~~~~~~~
//outputs a date in m/d/year with no endline

//void printAlpha const~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//prints Monthname day, year with no endline CAPITAL FIRST LETTER MONTH


//private functions:

//bool isLeap() const~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//tests fo leap year
//rules year % 4 == 0 is leap year
//except year % 100 == 0
//but year % 400 == 0 is ok

//unsigned daysPerMonth(unsigned m, unsigned y) const~~~~~~~~~~
// ~~~~~~~~possible upgrade later?~~~~~~~~~~~~~~~~
//returns the number of days in a month
//return an error for incorrect month #

//unsigned number(const string &mn) const ~~~~~~~~~~~~~~~~~~~~~~~~
//returns the number of a given month

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
    Date q(12,31,2000);
    q.addDays(-1).printNumeric();
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