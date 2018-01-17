//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 10 for CS 12 Winter 2015
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
// algorith and notes
/// do not iterate
/// no loops
/// write a function witha  string parameter
/// void reverse(string &s)
/// no global variables

#include <iostream>
#include <string>

using namespace std;

void test_PLZ_IGNORE(string &s){
    if(s.size() != 0){
        cout << "ELLO ELLO ELLO" << endl;
    }
}

void reverse(string &s){
    if( (s.size() > 1) && (s.at(0) != ' ') ){
        if(s.size() == 0){
            return;
        }
        else{
            char temp = s.at(0);
            s.erase( s.begin() );
            reverse(s);
            s.push_back(temp);
        }
    }
}

int main(){
    string s = "hello";
    string q = " ";
    
    cout << q;
    
    // test_PLZ_IGNORE(q);
    reverse(q);
    
    cout << q << endl;
    
    reverse(s);
    cout << s << endl;
    
    
    
    return 0;
}