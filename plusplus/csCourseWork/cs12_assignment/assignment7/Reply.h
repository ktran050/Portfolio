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
#ifndef __REPLY__
#define __REPLY__
#include <iostream>
#include <string>
#include "Message.h"

using namespace std;

class Reply : public Message{
    public:
        Reply();
        //defualt constructor
        
        Reply(const string &athr,
        const string &sbjct,
        const string &body,
        unsigned id);
        
        virtual bool is_reply();
        //returns true
    
        virtual string to_formatted_string() const;
        //outputs same format
        //nests it with n number indentation
        
    private:
    
};

#endif