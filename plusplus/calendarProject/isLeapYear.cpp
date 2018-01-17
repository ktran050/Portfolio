// The purpose of this program is to test the isLeapYear function
#include <iostream>
#include "isLeapYear.h"

int main(){

unsigned givenYear;
bool leapYear;

do{

    // Receive user input
    std::cout << "This program checks if a given year is a leap year. Input a year to check. Input 1 to exit \n";
    std::cin >> givenYear;

    // Compute whether or not the year is a leap year
    leapYear=isLeapYear(givenYear);

    // Return
    if(leapYear){
        std::cout<<givenYear<<" is a leap year. \n";
    }   
    else{
        std::cout<<givenYear<<" is not a leap year. \n";
    }
} while(givenYear!=1);


return 0;
}
