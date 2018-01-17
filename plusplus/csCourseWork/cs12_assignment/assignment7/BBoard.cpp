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
#include "BBoard.h"
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Message.h"
#include <stdio.h>
#include <string.h>

void BBoard::display() const{
    if(message_list.size() == 0){
        cout << "Nothing to display" << endl << endl;
    }
    
    for(int q = 0; q < static_cast<int>( message_list.size() ); ++q){
        cout << "Message " << q << ": ";
        
    }
}

void BBoard::add_topic(){
    string subject, body;
    cin.ignore();
    
    cout << "Enter Subject: ";
    getline(cin, subject);
    
    cout << "Enter Body: ";
    getline(cin, body);
    
    Topic( current_user->get_username() , subject,body,message_list.size() - 1);
    
    cout << "Message Recorded!" << endl << endl;
}

BBoard::BBoard(){
    title = "Jack Link's Beef Jerky";
    current_user = NULL;
}

BBoard::BBoard(const string &ttl){
    title = ttl;
    current_user = NULL;
}

bool BBoard::load_users(const string &userfile){
    string name, pass;
    
    ifstream inU;
    inU.open( userfile.c_str() );
    
    if( !inU.is_open() ){
        cout << "ERROR: Load users file stream could not be opened" << endl;
        return 0;
    }
    else{
        while(inU >> name){
            inU >> pass;
            user_list.push_back( User( name, pass ) );
        }
    }
    inU.close();
    return 1;
}

bool BBoard::load_messages(const string &datafile){
    unsigned numMess, id;
    string garbage, author, subject, body, bodyTemp;
    vector<unsigned> ReplyIDs;
    bool isReply;
    
    ifstream inM;
    inM.open( datafile.c_str() );
    
    if( !inM.is_open() ){
        cout << "ERROR: load_messages datafile couldn't be opened" << endl;
        return 0;
    }
    else{
        inM >> numMess;
        
        for(int q = 0; q < 1/*static_cast<int>(numMess)*/; ++q){
            getline(inM, garbage);
            cout << "1 " << garbage << endl;
            getline(inM, garbage);
            cout << "2 " << garbage << endl;
            getline(inM, garbage);
            cout << "3 " << garbage << endl;
            getline(inM, garbage);
            cout << "4 " << garbage << endl;
            getline(inM, garbage);
            cout << "5 " << garbage << endl;
            getline(inM, garbage);
            cout << "1 " << garbage << endl;
            getline(inM, garbage);
            cout << "2 " << garbage << endl;
            getline(inM, garbage);
            cout << "3 " << garbage << endl;
            getline(inM, garbage);
            cout << "4 " << garbage << endl;
            getline(inM, garbage);
            cout << "5 " << garbage << endl;
            inM >> garbage;
            cout << "1 " << garbage << endl;
            

            while(inM >> id){
                ReplyIDs.push_back(id);
            }
            
            cout << "MY PROGRESS " << endl;
            inM >> garbage;
            cout << "5 " << garbage << endl;
            
            // while(garbage != "<end>"){
            //     getline(inM, garbage);
            //     cout << garbage << endl;
            // }
        }
        // Finds reply IDs
        
        inM.close();
        inM.open( datafile.c_str() );
        
        inM >> numMess;
        for(int q = 0; q < static_cast<int>(numMess); ++q){
            getline(inM, garbage);
            inM >> garbage;
            
            isReply = 0;
            inM >> id;
            for(int q = 0; q < static_cast<int>(ReplyIDs.size()); ++q){
                if(id == ReplyIDs.at(q) ){
                    isReply = 1;
                }
            }
            if(isReply == 1){
                inM >> garbage;
                getline(inM, subject);
                
                inM >> garbage;
                inM >> author;
                
                while(bodyTemp != "<end>"){
                    inM >> bodyTemp;
                    body = body + bodyTemp;
                }
                
                message_list.push_back( new Reply (Reply(author, subject, body, id) ));
                return 1;
            }
            else{
                inM >> garbage;
                getline(inM, subject);
                
                inM >> garbage;
                inM >> author;
                
                // while(bodyTemp != "<end>"){
                //     inM >> bodyTemp;
                //     body = body + "\n" + bodyTemp;
                // }
                
                
                message_list.push_back( new Topic (Topic(author, subject, body, id) ));
                return 1;
            }
        }
        
    }
    inM.close();
    return 1;
}

bool BBoard::save_messages( const string & datafile ){
    
    ofstream outM;
    outM.open( datafile.c_str() );
    
    if( !outM.is_open() ){
        return 0;
    }
    else{
        
    }
    outM.close();
    return 1;
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
        
        for(int q = 0; q < static_cast<int> ( user_list.size() ); ++q) {
            if(user_list.at(q).get_username() == enteredName){
                current_user = &user_list.at(q);
            }
        }
        
        if(current_user->check(enteredName, enteredPass) == 0){
            cout << "Invalid Username or Password!" << endl;
            current_user = 0;
        }
        else{
            cout << "Welcome back " << current_user->get_username() << "!" 
            << endl;
            cout << endl;
            userInfo = 1;
        }
    }
}

void BBoard::run(){
    string userInput = "z";
    if((current_user->get_username() != User().get_username())){
        while((userInput != "Q") || (userInput != "q")){
            cout << "Menu" << endl;
            cout << " \t - Display Messages ('D' or 'd')" << endl;
            cout << " \t - Add new Message ('N' or 'n')" << endl;
            cout << " \t - Quit ('Q' or 'q')" << endl;
            cout << "Choose an action: ";
            cin >> userInput;
            cout << endl;
            
            if((userInput == "D") || (userInput == "d")){
                this->display();
            }
            else if((userInput =="N") || (userInput == "n")){
                this->add_topic();
            }
            if((userInput == "Q") || (userInput == "q")){
                exit(0);
            }
        }
    }
}