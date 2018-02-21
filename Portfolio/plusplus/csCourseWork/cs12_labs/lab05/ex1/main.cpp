//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 5 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date February 4th, 2015
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
#include "Distance.h"

using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();

int main(){
    // test1();
    // test2();
    // test3();
    test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    return 0;
}

void test1(){
    cout << "Test 1: Default Constructor" << endl;
    Distance q;
    q.DistObjDisp();
    cout << "====================" << endl;
}
void test2(){
    cout << "Test 2: constructor(unsigned 0, double 0)"
    << endl;
    Distance q(0, 0.0);
    q.DistObjDisp();
    cout << "====================" << endl;
}
void test3(){
    cout << "Test 3: constructor(unassigned 1000, double 1200" << endl;
    Distance q(1000, 1200);
    q.DistObjDisp();
    cout << "====================" << endl;
}
void test4(){
    cout << "Test 4: additon test" << endl;
    Distance a(1000);
    Distance b(2000);
    (a+b).DistObjDisp();
    cout << "====================" << endl;
}
void test5(){
    cout << "Test 5: constructor(1200)" << endl;
    Distance q(1200);
    q.DistObjDisp();
    cout << "====================" << endl;
}
void test6(){
    cout << "Test 6: " << endl;
    cout << "====================" << endl;
}
void test7(){
    cout << "Test 7: " << endl;
    cout << "====================" << endl;
}
void test8(){
    cout << "Test 8: " << endl;
    cout << "====================" << endl;
}
void test9(){
    cout << "Test 9: " << endl;
    cout << "====================" << endl;
}