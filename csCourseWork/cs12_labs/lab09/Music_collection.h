//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 9 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date March 2nd, 2015
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
#ifndef __MuCol__
#define __MuCol__

#include <iostream>
#include <string>

using namespace std;

class Tune{
    private:
        string title;
    
    public:
        Tune();
        Tune(const string& n);
        const string & get_title() const;
    
};

class Music_collection{
    private:
        int number; // Number of songs in the collection
        int max; // Max the collection can hold
        Tune *collection; // Dynamically allocated array of Tunes
    
    public:
        Music_collection();
            // Default value of max is 100
        Music_collection(int n);
            // Sets max to n
        Music_collection(const Music_collection &m);
            // Overloaded copy constructor
        bool add_tune(const Tune &t);
            // Returns True if add was successful
            // Retirms False if unsuccessful
        bool set_tune(int index, const Tune &t);
            // Sets the Tune at position index in position collection to t
            // Returns True if index < number
        ~Music_collection();
            // Destructor
        Music_collection& operator=(const Music_collection &m);
            
        friend ostream & operator<<(ostream & out, const Music_collection &m);
            // Overloaded stream insert operator
            // Outputs each tile on a seperate line
};

#endif