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
#include <iostream>
#ifndef __DistanceClass__
#define __DistanceClass__

using namespace std;

class Distance{
    
    private:
        unsigned feet;
        double inches;
        
    public:
        Distance();
        Distance(unsigned, double);
        Distance(double);
        void DistObjDisp();
        void init();
        double convertToInches();
        Distance operator+(Distance& rhs){
            double QQ = convertToInches() + rhs.convertToInches();
            Distance q(QQ);
            return q;
        }
        Distance operator-(Distance& rhs){
            if(convertToInches() > rhs.convertToInches()){
                double QQ = convertToInches() - rhs.convertToInches();
                Distance q(QQ);
                return q;
            }
            else{
                double QQ =rhs.convertToInches() - convertToInches();
                Distance q(QQ);
                return q;
            }
        }
};
#endif