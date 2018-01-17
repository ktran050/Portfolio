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
#ifndef __TOPIC__
#define __TOPIC__
#include <iostream>
#include "Message.h"
#include <string>


using namespace std;

class Topic : public Message{
    public:
        Topic();
        // constructor
        
        Topic(const string &athr,
        const string &sbjct,
        const string &body,
        unsigned id);
        // constructor with parameters
        
        virtual bool is_reply() const;
        //returns false
        
        virtual string to_formatted_string() const;
        //writes everything out in this format
        //endl;
        //id:
        //subject:
        //from: author
        //children: (don't write this line if there are no children)
        //body: line 1
        //line 2
        //line 3
        //endl;
        
        //this function should add a newline at the end of the body string
        //on top of that the last character of the string should be a newline
        
    private:
    
};

#endif