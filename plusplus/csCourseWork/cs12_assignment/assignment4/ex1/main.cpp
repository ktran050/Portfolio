//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Assignment 4 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date February 9th, 2015
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
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Message.h"
#include "User.h"
#include "BBoard.h"

using namespace std;

int main(int argc, char* argv[]){
    const string filename = argv[1];
    BBoard qq;
    
    qq.setup(filename);
    qq.login();
    qq.run();
    return 0;
}