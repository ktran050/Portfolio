//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Assignment 7 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date March 10th, 2015
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
#include "Message.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Message::Message(){
    author = "blank";
    subject = "blank";
    body = "blank";
    id = 0;
}

Message::Message(const string &athr,
const string &sbjct,
const string &body,
unsigned id){
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}

Message::~Message(){
    
}
