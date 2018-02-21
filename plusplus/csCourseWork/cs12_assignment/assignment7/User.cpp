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
#include "User.h"
#include <string>

using namespace std;

User::User(){
    
}

User::User(const string& uname, const string& pass){
    username = uname;
    password = pass;
}

string User::get_username() const{
    return username;
}

bool User::check(const string &uname, const string &pass) const{
    bool userInfo = 0;
    
    if((uname.empty())||(pass.empty())){
        userInfo = 0;
    }
    
    if((username == uname) && (password == pass)){
        userInfo = 1;
    }
    
    return userInfo;
}

void User::set_password(const string &newpass){
    password = newpass;
}