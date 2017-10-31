#include <iostream>
#include <string>
#include <ctype.h>
#include "isLeapYear.h"
#include <stdlib.h>
 
using namespace std;

string dayOfTheWeek(unsigned day,unsigned month, unsigned year){
    int daysApart;
    const int monthsOfTheYear[]={31,28,31,30,31,30,31,31,30,31,30,31};

    // Find the number of days apart the date and the genesis date are
    daysApart=(year-2001)*365;
    for(unsigned i=0;i<month-1;++i){
        daysApart+=monthsOfTheYear[i];
    }
    daysApart+=day-1;

    // Add days from leap years for future dates
    for(unsigned i=2001;i<year;++i){
	if(isLeapYear(i))
    	    ++daysApart;
    }
    // Add days from leap years for past dates
    for(unsigned i=year;i<2000;++i){
	if(isLeapYear(i))
	    --daysApart;
    }

    if(isLeapYear(year)){
	if(month>2 && year>2001)
	   ++daysApart;
        else if(month<2 && year<2001)
	   --daysApart;
	else{}
    }

    // Given the number of days apart return the day of the week it is 
    switch(daysApart%7){
	case -6: return "Tuesday";
	case -5: return "Wednesday";
	case -4: return "Thursday";
	case -3: return "Friday";
	case -2: return "Saturday";
	case -1: return "Sunday";
        case 0: return "Monday";
        case 1: return "Tuesday";
	case 2: return "Wednesday";
	case 3: return "Thursday";
	case 4: return "Friday";
	case 5: return "Saturday";
	case 6: return "Sunday";
    }

    cout<<"Something went very wrong daysApart%7 \n";
    return "O snap";
}

int main(){
   unsigned day; unsigned month; unsigned year;
   string writtenDay;

   // Take in the date in DD/MM/YYYY
   std::cout<<"Input month \n";
   std::cin>>month;
   std::cout<<"Input day \n";
   std::cin>>day;
   std::cout<<"Input year \n";
   std::cin>>year;

   // Calculate what day of the week it would be
   writtenDay=dayOfTheWeek(day, month, year);

   // Output
   cout << "The day of the week that date falls on is: "<<writtenDay<<endl;


   return 0;
}
