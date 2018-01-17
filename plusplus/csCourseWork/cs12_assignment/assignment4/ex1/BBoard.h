#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Message.h"

using namespace std;

#ifndef __BBoard__
#define __BBoard__

class BBoard{
  private:
  
    string title;
    //Title of the board
    //Initiallized via constructor
    
    vector<User> user_list;
    //List of members
    //Initiallized empty
    //Populated via setup()
    
    User current_user;
    //User currently logged in
    //Initiallized to default(User)
    //Set via login()
    
    vector<Message> message_list;
    //List of messages
    //Initially empty
    
    void displayAll() const;
    void addMessage() const;
    
  public:
    BBoard();
    //Creates board with default title
    //Empty message and user lists
    //default user logged in
    
    BBoard(const string &ttl);
    //Sets title of a board
    
    void setup(const string &input_file);
    //Imports users from user list
    //Stores them as user object in vector user_list
    
    void login();
    //Asks for name and password
    //Abort if username is 'Q' or 'q'
    //Else always check for password
    //Checks if thats right
    //If wrong cout Invalid Username or Password!
    //If login successful set user to username
    //When the user puts in 'q' or 'Q' say Bye! and exit(0)
    
    
    void run();
    //if username is not a valid current user don't show a menu
    //Show the following menu items
    //\t - "Display Messages ('D' or 'd')"
    //\t - "Add New Message ('N' or 'n')"
    //\t - "Quit ('Q' or 'q')"
    
};

#endif