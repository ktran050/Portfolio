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

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    return 0;
}

void test1(){
    IntVector qq;
    cout << "Test 1: default constructor" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "------------------------" << endl;
}
void test2(){
    IntVector qq(5);
    cout << "Test 2: construc with size" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
        
    qq.at(3);
    cout << "------------------------" << endl;
}
void test3(){
    IntVector qq(100);
    cout << "Test 3: construc with size" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << qq.at(3) << endl;    
    cout << "------------------------" << endl;
}
void test4(){
    IntVector qq(5,100);
    cout << "Test 4: construc with size and val" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << "------------------------" << endl;
}
void test5(){
    IntVector qq(10,10);
    cout << "Test 4: construc with size and val" << endl;
    cout << "sz: " << qq.size() << endl << "cap: " <<
        qq.capacity() << endl;
    cout << qq.at(3) << endl;
}
void test6(){
}
void test7(){
    
}
void test8(){
    
}
void test9(){
    
}
void test10(){
    
}