#include <iostream>
#include <string>
#include <ctype.h>
#include "isLeapYear.h"
#include <stdlib.h>
#include "dayOfTheWeek.h"
 
using namespace std;

int main(){
   int day; int month; int year;
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
