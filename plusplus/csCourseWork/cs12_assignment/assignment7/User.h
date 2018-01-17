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
#ifndef __User__
#define __User__

#include <string>

using namespace std;

class User{
    private:
        string username;
        string password;
    public:
        User();
        //creates a default user with empty name and password
        
        User(const string& uname, const string& pass);
        //creates a user with given username and password
        
        string get_username() const;
        //returns the current username
        
        bool check(const string& uname, const string& pass) const;
        //returns true if user info is correct
        //has to return false for empty unames and default user
        
        void set_password(const string &newpass);
        //sets a new password not used yet
};

#endif