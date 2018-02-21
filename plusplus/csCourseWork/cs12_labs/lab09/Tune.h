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
#include <string>
#include "Music_collection.h"

Tune::Tune(){
    
}

Tune::Tune(const string& n){
    title = n;
}

const string & Tune::get_title() const{
    return title;
}



Music_collection::Music_collection(){
    max = 100;
    number = 0;
    collection = new Tune[100];
}

Music_collection::Music_collection(int n){
    max = n;
    number = 0;
    collection = new Tune[n];
}

Music_collection::Music_collection(const Music_collection &m){
    
}

bool Music_collection::add_tune(const Tune &t){
    if(number + 1 > max){
        return 0;
    }
    else{
        collection[number] = t;
        ++number;
        return 1;
    }
}


bool Music_collection::add_tune(const Tune &t){
    if(number + 1 > max){
        return 0;
    }
    else{
        collection[number + 1] = t;
        ++number;
        return 1;
    }
}

bool Music_collection::set_tune(int index, const Tune &t){
    
    //FIXME: Write this function
    cout << "FIXME: Write this function" << endl;
    return 0;
}

Music_collection::~Music_collection(){
    delete [] collection;
}

// friend ostream & Music_collection::operator<<(ostream &out, 
// const Music_collection() &m){
    
// }