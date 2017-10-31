//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 2 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 13th, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 023
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;

void mystrcat(char destination[],char const source[]){
    int sourceSize = 0;
    int destSize = 0;
    for(int i = 0; source[i] != '\0'; ++i){
        if( (source[i] >= 'a') && (source[i] <= 'z') ){
            ++sourceSize;
            cout << "Source size: " << sourceSize << endl;
        }
    }
    for(int i = 0; destination[i] != '\0'; ++i){
        if( (destination[i] >= 'a') && (destination[i] <= 'z') ){
            ++destSize;
            cout << "Dest Size: " << destSize << endl;
        }
    }
    for(int i = 0; i < sourceSize; ++i){
        destination[destSize + i] = source[i];
        cout << destination[i] << endl;
    }
    destination[destSize + sourceSize] = '\0';

}