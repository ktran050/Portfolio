//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab2.cpp
/// @brief Lab 2
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date October 14, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    /* Task List
        Have the user input their name
        Take name input
        Ask a question about nice days
        Take input
        Ask about how many days the user wants
        Take input
        Output response using all inputs
    */
    
    
    
    
    string userName;
    int wantedDays;
    
    cout << "Good day, what is your name?" << endl;
    cin >> userName;
    cout << "How many nice days would you like, " << userName << "?" << endl;
    cin >> wantedDays;
    wantedDays = wantedDays * 2;
    cout << "Hi, " << userName << ", have " << wantedDays <<" wonderful days!";
    
    
    
    
    return 0;
}