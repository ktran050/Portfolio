// This function tells you whether a year is a leap year or not.
// Input: int
// Output: bool
// Leap years are years divisible by 4. The caveeat is years divisible by 100 are NOT leap years, except for those also divisible by 400.
// Takes int just to make the program more general
#include <iostream>
using namespace std;
#ifndef ISLEAPYEAR_H
#define ISLEAPYEAR_H


bool isLeapYear(int year){
  if(year < 0)
    return false;
  else if(year%4){
    return false;
  }
  else if(!(year%400))
    return true;
  else if(!(year%100))
    return false;
  else
    return true;		// This point is only reached if the year is divisible by 4, and not divisible by 100 or 400
}


void isLeapYear(){
  int year; bool isLeap=false;

  cout << "Please input a year.\n";
  if(!(cin>>year)){
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "ERROR: Invalid input \n";
    return;
  }

  if(year < 0)
    isLeap = false;
  else if(year%4)
    isLeap = false;
  else if(!(year%400))
    isLeap = true;
  else if(!(year%100))
    isLeap = false;
  else
    isLeap = true;		// This point is only reached if the year is divisible by 4, and not divisible by 100 or 400

  if(isLeap)
    cout << year << " was a leap year.\n";
  else
    cout << year << " was not a leap year.\n";
}

#endif
