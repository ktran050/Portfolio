//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 7 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date February 16th, 2015
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
//Create a class of vectors containing ints
//Call it IntVector
//Private Data
//-unsigned sz
//-unsigned cap
//-int *
//Public Data
//IntVector();
//IntVector(unsigned size);
//IntVector( unsigned size, int value)
//unsigned size()const
//unsigned capacity() const
//bool empty() const
//const int &at(unsigned index) const
#include <iostream>
#include <cstdlib>
#include "IntVector.h"

using namespace std;

void IntVector::expand(){
    IntVector cpp(sz);
    for(int q = 0; q < sz; ++q){
        cpp.at(q) = this->at(q);
    }
    delete [] this->data;
    this->data = new int[cap * 2];
    for(int q = 0; q < sz; ++q){
         this->at(q) = cpp.at(q);
    }
    this->cap = cap * 2;
}

void IntVector::expand(unsigned amount){
    if((cap ==0) || (sz == 0)){
        expand();
    }
    else{
        IntVector cpp(sz);
        for(int q = 0; q < sz; ++q){
            cpp.at(q) = this->at(q);
        }
        delete [] this->data;
        this->data = new int[cap + amount];
        for(int q = 0; q < sz; ++q){
             this->at(q) = cpp.at(q);
        }
        this->cap = cap + amount;
    }
}

IntVector::IntVector(){
    sz = 0;
    cap = 0;
    data = NULL;
}
IntVector::IntVector(unsigned size){
    sz = size;
    cap = size;
    data = new int[cap]();
}
IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[cap];
    for(int q = 0; q < size; ++q){
        data[q] = value;
    }
}
IntVector::~IntVector(){
    delete [] data;
    data = NULL;
}

unsigned IntVector::size() const{
    return sz;
}
unsigned IntVector::capacity() const{
    return cap;
}
const int & IntVector::front() const{
    return this->at(0);
}

int & IntVector::front(){
    return this->at(0);
}

const int & IntVector::back() const{
    return this->at(sz - 1);
}

int & IntVector::back(){
    return this->at(sz - 1);
}

void IntVector::push_back(int value){
    if(sz + value > cap){
        expand();
        sz += 1;
        this->at(sz - 1) = value;
    }
}

void IntVector::assign(unsigned n, int value){
    if(cap < n){
        if((n) > (cap * 2)){
            expand(n - cap);
        }
        else if((n) > (cap * 2)){
            expand();
        }
    }
    for(int q = 0; q < sz; ++q){
        this->at(q) = value;
    }
}

void IntVector::pop_back(){
    if(sz != 0){
        sz -= 1;
    }
    else{
        exit(1);
    }
}

void IntVector::clear(){
    sz = 0;
}

void IntVector::resize(unsigned size){
    if(cap < size){
        if((size) > (cap * 2)){
            expand(size - cap);
        }
        else if ((size) < (cap * 2)){
            expand();
        }
    }
    if(size < sz){
        sz = size;
    }
    else if(size > sz){
        sz = size;
        for(int q = sz; q < size; ++q){
            this->at(q) = 0;
        }
    }
}

void IntVector::resize(unsigned size, int value){
    if(cap < size){
        if((size) > (cap * 2)){
            expand(size - cap);
        }
        else if ((size) < (cap * 2)){
            expand();
        }
    }
    if(size < sz){
        sz = size;
    }
    else if(size > sz){
        sz = size;
        for(int q = sz; q < size; ++q){
            this->at(q) = value;
        }
    }
}

bool IntVector::empty() const{
    if(sz > 0){
        return 0;
    }
    else{
        return 1;
    }
}
const int & IntVector::at(unsigned index) const{
    //returns value at parameter index
    if(index >= sz){
        exit(1);
    }
    //exit the program if the value is greater than sz
    else{
        return this->data[index];
    }
}

int & IntVector::at(unsigned index){
    //returns value at parameter index
    if(index >= sz){
        exit(1);
    }
    //exit the program if the value is greater than sz
    else{
        return this->data[index];
    }
}

void IntVector::reserve(unsigned n){
    if(cap < n){
        cap = n;
    }
    if(cap > n){
        if((cap + n) > (cap * 2)){
            expand(n);
        }
        else{
            expand();
        }
    }
}


void IntVector::insert(unsigned index, int value){
    if(index > sz){
        exit(1);
    }
    if(sz + 1 > cap){
        expand();
    }
    for(int q = this->size() - 1; q >= index; q--){
        this->at(q + 1) = this->at(q);
    }
    this->at(index);
}

void IntVector::erase(unsigned index){
    for(int q = index; q < this->size(); ++q){
        this->at(q) = this->at(q + 1);
    }
    sz -= 1;
}