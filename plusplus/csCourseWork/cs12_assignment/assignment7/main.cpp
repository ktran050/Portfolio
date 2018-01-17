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
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Message.h"
#include "User.h"
#include "BBoard.h"

using namespace std;

int main(int argc, char **argv){
    if(argc != 3){
        cout << "ERROR: Invalid program call." << endl
        << "Usage: <program_name> userfile datafile" << endl;
        return 1;
    }
    
    string userfile(argv[1]);
    string datafile(argv[2]);
    BBoard bb("CS12 Bullein Board");
    
    if(!bb.load_users(userfile)){
        cout << "ERROR: Cannot load users from " << userfile << endl;
        return 1;
    }
    // Loads users
    
    if(!bb.load_messages(datafile)){
        cout << "ERROR: Cannot load messages from " << datafile << endl;
    }
    // Loads messages
    
    // bb.login();
    // bb.run();
    
    // if(!bb.save_messages(datafile)){
    //     cout << "ERROR: Cannot save messages to " << datafile << endl;
    //     return 1;
    // }
    // // Saves messages
    
    return 0;
}
