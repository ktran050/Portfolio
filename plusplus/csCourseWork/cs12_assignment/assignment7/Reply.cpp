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
#include <iostream>
#include "Reply.h"
#include <string>
#include <sstream>

using namespace std;

Reply::Reply(){
    author = "blank";
    subject = "blank";
    body = "blank";
    id = 0;
}

Reply::Reply(const string &athr,
const string &sbjct,
const string &body,
unsigned id){
    author = athr;
    subject = sbjct;
    this->body = body;
    this->id = id;
}

bool Reply::is_reply(){
    return 1;
}

// string Reply::to_formatted_string() const{
//     string bloop = "<begin_topic>\n";
//     string stringID;
//     stringstream convert;
//     convert << id;
//     stringID = convert.str();
    
//     string formatted = bloop + stringID + "\n:subject: "
//     + subject + "\n:from: " + author + "\n:body: " + body + "\n";
//     return formatted;
//     // cout << endl;
//     // cout << "Message #" << id << ": " << subject << endl;
//     // cout << "from " << author << ": " << body << endl;
//     // cout << endl;
    // return "woop";
// }
