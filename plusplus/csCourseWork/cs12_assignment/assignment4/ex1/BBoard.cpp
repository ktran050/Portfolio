#include <iostream>
#include "BBoard.h"
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Message.h"

void BBoard::displayAll() const{
    if(message_list.size() == 0){
        cout << "Nothing to display" << endl << endl;
    }
    
    for(int q = 0; q < message_list.size(); ++q){
        cout << "Message " << q << ": ";
        message_list.at(q).display();
    }
}

void BBoard::addMessage() const{
    string subject, body;
    cin.ignore();
    
    cout << "Enter Subject: ";
    getline(cin, subject);
    
    cout << "Enter Body: ";
    getline(cin, body);
    
    Message(current_user.get_username(), subject, body);
    
    cout << "Message Recorded!" << endl << endl;
}

BBoard::BBoard(){
    title = "Jack Link's Beef Jerky";
    current_user = User();
}

BBoard::BBoard(const string &ttl){
    title = ttl;
    current_user = User();
}

void BBoard::setup(const string &input_file){
    string readInName, readInPass;
    
     //open file stream
    ifstream inFS;
    inFS.open(input_file.c_str());
    if(!inFS.is_open()){
        cout << "Error: shit's on fire yo" << endl;
    }
    
    while(inFS >> readInName){
        inFS >> readInPass;
        user_list.push_back(User(readInName, readInPass));
    }
    
    //close file stream
    inFS.close();
}

void BBoard::login(){
    string enteredName, enteredPass;
    bool userInfo = 0;
    
    while(userInfo == 0){
        cout << "Welcome to Jack's Amazing Bulletin Board" << endl;
        cout << "Enter your username ('Q' or 'q' to quit): ";
        cin >> enteredName;
        
        cout << "Enter your password: ";
        cin >> enteredPass;
        
        if((enteredName == "Q") || (enteredName == "q")){
            cout << "Bye!" << endl;
            exit(0);
        }
        
        for(int q = 0; q < user_list.size(); ++q){
            if(user_list.at(q).get_username() == enteredName){
                current_user = user_list.at(q);
            }
        }
        
        if(current_user.check(enteredName, enteredPass) == 0){
            cout << "Invalid Username or Password!" << endl;
            current_user = User();
        }
        else{
            userInfo = 1;
        }
    }
    if(userInfo == 1){
        cout << "Welcome back " << current_user.get_username() << "!" << endl;
        cout << endl;
    }
}

void BBoard::run(){
    string userInput = "z";
    if((current_user.get_username() != User().get_username())){
        while((userInput != "Q") || (userInput != "q")){
            cout << "Menu" << endl;
            cout << " \t - Display Messages ('D' or 'd')" << endl;
            cout << " \t - Add new Message ('N' or 'n')" << endl;
            cout << " \t - Quit ('Q' or 'q')" << endl;
            cout << "Choose an action: ";
            cin >> userInput;
            cout << endl;
            
            if((userInput == "D") || (userInput == "d")){
                this->displayAll();
            }
            else if((userInput =="N") || (userInput == "n")){
                this->addMessage();
            }
            if((userInput == "Q") || (userInput == "q")){
                exit(0);
            }
        }
    }
}