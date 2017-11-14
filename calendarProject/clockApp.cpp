#include <iostream>
#include "dayOfTheWeek.h"
#include "isLeapYear.h"
#include <ctype.h>
#include <string>

using namespace std;

void prompt(){
    cout << "~~~~~~~~~~~~~~~~~~~~~Menu~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "Welcome to the clock app! Please choose an option below: \n";
    cout << "To check if a given year is a leap year enter: 1 \n";
    cout << "To check what day of the week it was on a given date enter: 2 \n";
    cout << "To exit enter: -1\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

int main(){
    int progNum = 0;
    bool exit = false;

    do{
      // Prompt users and take input
      prompt();
      cin>>progNum;
      cin.clear();
      cin.ignore(10000, '\n');

      // Based on the inputs run a program or exit
      switch(progNum){
        case -1: cout << "Goodbye. \n"; exit=true; break;	// Symbols and alpha chars count as 0. We use 23 instead
        case 1: cout << "Running isLeapYear \n";
                isLeapYear(); break;
        case 2: cout << "Running dayOfTheWeek \n"; break;
        default: cout << "ERROR: Invalid option. Please try again.\n"; break;
      }
    }while(exit != true);

    return 0;
}
