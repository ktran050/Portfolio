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
#ifndef __Message__
#define __Message__
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Message{
    protected:
        string author;
        string subject;
        string body;
        unsigned id;
        vector<Message *> child_list;
        
    public:
        Message();
        //default constructor
        
        Message(const string& athr,
        const string& sbjct,
        const string& body
        ,unsigned id);
        //Message object with parameters
        
        virtual ~Message();
        //some messages might have 2 pointers to it
        
        virtual bool is_reply() const = 0;
        
        
        
        // void print(unsigned indentation) const;
        //prints the message
        //recursively calls itself and indents child replies
        //each indentation is two spaces
        
        const string & get_subject() const{
            return subject;
        }
        
        unsigned get_id() const{
            return id;
        }
        
        void add_child(Message *child){
            child_list.push_back(child);
        }
        //add a pointer to the child to the parents child list
        
};
#endif