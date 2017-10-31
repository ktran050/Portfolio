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
// Implement functions given in Prompt.txt
/// Create necessary files
/// Copy class and class member declarations
/// Write Tune class
/// Write Constructors/Deconstructor for MuCol
/// Write the other functions
/// Brainstorm edge cases
/// Test for edge cases
/// Fix cases

#include <iostream>
#include "Music_collection.h"

using namespace std;

void somefunction(Music_collection p){
    Tune aa("wowee");
    p.add_tune(aa);
}

int main(){
    
    Tune qq;
    Tune aa("wowee");
    Tune bb("Test");
    
    Music_collection cc;
    cc.add_tune(aa);
    cout << cc;
    cout << "-------------------------" << endl;
    
    Music_collection dd(4);
    dd.add_tune(bb);
    dd.add_tune(bb);
    dd.add_tune(bb);
    dd.add_tune(bb);
    cout << dd;
    cout << "-------------------------" << endl;
    
    cc.set_tune(0, bb);
    cout << cc;
    cout << "-------------------------" << endl;
    
    return 0;
}