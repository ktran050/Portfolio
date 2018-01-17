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
/// is ENTIRELY my own original work
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include "Topic.h"
#include <string>
#include <sstream>

using namespace std;

Topic::Topic(){
    author = "blank";
    subject = "blank";
    this->body = "blank";
    this->id = 0;
}

Topic::Topic(const string &athr,
const string &sbjct,
const string &body,
unsigned id){
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}
// constructor with parameters

bool Topic::is_reply() const{
    return 0;
}
//returns false

string Topic::to_formatted_string() const{
    string bloop = "<begin_topic>\n";
    string stringID;
    stringstream convert;
    convert << id;
    stringID = convert.str();
    
    string formatted = bloop + ":id: " + stringID + "\n:subject: "
    + subject + "\n:from: " + author + "\n:body: " + body + "\n";
    return formatted;
    // cout << endl;
    // cout << "Message #" << id << ": " << subject << endl;
    // cout << "from " << author << ":" << body << endl;
    // cout << endl;
    // return "woop";
}
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