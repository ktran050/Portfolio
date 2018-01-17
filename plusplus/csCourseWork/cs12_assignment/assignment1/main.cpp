//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 2 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 1````````3th, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 023
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>


using namespace std;

double randFloat (double a, double b){
    return a + (static_cast<double>(rand())/ RAND_MAX) * (b-a);
}

void generate(double array[], int i){
    double inputMin, inputMax, theoMean, pracMean, theoDev, pracDev;
    cin >> inputMin >> inputMax;
    theoMean = (inputMin + inputMax) / 2;
    theoDev = pow((inputMax - inputMin),2) / 12;
    pracMean = 0;
    for(int a = 0; a < i; ++a){
        array[a] = randFloat(inputMin, inputMax);
    }
    for(int a = 0; a < i; ++a){
        pracMean = pracMean + array[a];
    }
    pracMean = pracMean / i;
    pracDev = 0;
    for(int a = 0; a < i; ++a){
        pracDev = pracDev + pow((array[a] - pracMean),2);
    }
    pracDev /= i;
    
    cout << theoMean << " " << pracMean << " " << theoDev << " " << pracDev
    << endl;
    return;
}

int main(){
    srand(333);
    int i = 0;
    i = 1000;
    double storage[i];
    generate(storage, 1000);
    
    i = 100000;
    storage[i];
    generate(storage, 100000);
    
    
    return 0;
}