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
#include <fstream>
#include <string>


using namespace std;

int main (){
    
    //declarations
    ifstream inFS;
    ofstream outFS;
    string inFile; string outFile;
    double topTemp, rightTemp, bottomTemp, leftTemp, tol;
    double tempMax, tempMaxUp;
    double a[6][8] = {0};
    
    
    //Take the input file
    cout << "What is the input file? " << endl;
    cin >> inFile;
    
    //take the output file
    cout << "What is the output file? " << endl;
    cin >> outFile;
    
    //Open input file
    inFS.open(inFile.c_str());
    
    //Take top, right, bottom, left temperatures as well as tolerance
    inFS >> topTemp >> rightTemp >> bottomTemp >> leftTemp >> tol;
    
    //close the input file
    inFS.close();
    
    //initialize the grid's edges to 0
    //Grid is 6x8
    for(int q = 0; q < 8; ++q){
        a[0][q] = topTemp;
        a[5][q] = bottomTemp;
    }
    for(int q = 1; q < 5; ++q){
        a[q][0] = leftTemp;
        a[q][7] = rightTemp;
    }
    
    //tempCheck
    for(int q = 0; q < 6; ++q){
        for(int c = 0; c < 8; ++c){
            cout << a[q][c] << " ";
        }
        cout << endl;
    }
    
    //continue until inner cells equilibrium
    tempMax = tempMaxUp = 0;
    do{
        tempMaxUp = 0;
        for(int q = 1; q < 5; ++q){
            for(int c = 1; c < 7; ++c){
                tempMax = a[q][c];
                a[q][c] = a[q + 1][c] + a[q - 1][c] + a[q][c + 1] + a[q][c - 1];
                a[q][c] /= 4;
                tempMax = a[q][c] - tempMax;
                if(tempMaxUp < tempMax){
                    tempMaxUp = tempMax;
                }
            cout << endl;
            }
        }
    }while(tempMaxUp > tol);
    
    //open output
    outFS.open(outFile.c_str());
    
    //save inner temp to output file
    for(int q = 1; q < 5; ++q){
        for(int c = 1; c < 7; ++c){
            outFS << a[q][c] << " ";
        }
        outFS << endl;
    }
    //close output file
    outFS.close();
    
    
    //Program ended without a problem
    return 0;
}