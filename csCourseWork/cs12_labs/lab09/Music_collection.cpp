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
    collection = new Tune[max];
}

Music_collection::Music_collection(int n){
    max = n;
    number = 0;
    collection = new Tune[max];
}

Music_collection::Music_collection(const Music_collection &m){
    max = m.max;
    number = m.number;
    collection = new Tune[number];
    for(int q = 0; q < number; ++q){
        collection[q] = m.collection[q];
    }
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

bool Music_collection::set_tune(int index, const Tune &t){
    if(index > number){
        return 0;
    }
    else{
        collection[index] = t;
        return 1;
    }
}

Music_collection::~Music_collection(){
    delete [] collection;
}

Music_collection& Music_collection::operator=(const Music_collection &m){
    if(this != &m){
        delete [] collection;
        this->max = m.max;
        this->number = m.number;
        this->collection = new Tune[m.max];
        for(int q = 0; q < m.max; ++q){
            collection[q] = m.collection[q];
        }
    }
    return *this;
}

ostream & operator<<(ostream & out, const Music_collection &m){
    for(int q = 0; q < m.number; ++q){
        out << m.collection[q].get_title() << endl;
    }
    return out;
}