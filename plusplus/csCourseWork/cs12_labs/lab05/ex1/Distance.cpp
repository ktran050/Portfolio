//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 5 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date February 4th, 2015
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
#include "Distance.h"
#include <cmath>

using namespace std;

Distance::Distance(){
    this->feet = 0;
    this->inches = 0;
}
Distance::Distance(unsigned feet, double inches){
    this->feet = feet;
    this->inches = inches;
    init();
}
Distance::Distance(double inches){
    this-> feet = 0;
    this->inches = inches;
    init();
}

void Distance::DistObjDisp(){
    cout << "Feet: " << feet << "' " << inches << "\"" << endl;
}

void Distance::init(){
    if(this->inches < 0){
        this->inches = abs(this->inches);
    }
    while(this->inches >= 12){
        ++feet;
        this->inches = this->inches - 12;
    }
}

double Distance::convertToInches(){
    return ((int)(feet) * 12) + inches;
}