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
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Message.h"
#include "Topic.h"
#include "Reply.h"

using namespace std;

#ifndef __BBoard__
#define __BBoard__

class BBoard{
  private:
  
    string title;
    // Title of the board
    // Initiallized via constructor
    
    vector<User> user_list;
    // List of members
    // Initiallized empty
    // Populated via setup()
    
    const User* current_user;
    // Points to user currently logged in
    // Initiallized to Null
    // Set via login()
    
    vector<Message *> message_list;
    // List of message pointers
    // Initially empty
    
    void display() const;
    // 
    
    void add_topic();
    // 
    
    void add_reply();
    // 
    
    
  public:
    BBoard();
    // Creates board with default title
    // Empty message and user lists
    // NULL current user
    
    BBoard(const string &ttl);
    // Sets title of a board
    // Null current user
    
    bool load_users(const string &userfile);
    // Takes user info from the given file
    // Opens and reads all usernames and their passwords
    // Populates userlist with this info
    // If an error occurs return fales, return true if otherwise
    
    bool load_messages(const string &datafile);
    // Takes message info from given file
    // Creates Topic and Reply objects
    // Fills message list with pointers to these objects
    // If an error occurs return false4
    
    bool save_messages(const string &datafile);
    // Gets the file name to save these messages
    // Opens the file and writes everything in the same format
    // If an error occurs return false
    // file not found is NOT an error
    
    void login();
    // Asks for the username and password
    // Checks list if data matches
    // IF correct sets current_user to that user
    // If incorrect keep looking until end or the user types 'Q' or 'q'
    // When the user quits 
    
    
    void run();
    //if username is not a valid current user don't show a menu
    //Show the following menu items
    //\t - "Display Messages ('D' or 'd')"
    //\t - "Add New Message ('N' or 'n')"
    //\t - "Quit ('Q' or 'q')"
    
};

#endif