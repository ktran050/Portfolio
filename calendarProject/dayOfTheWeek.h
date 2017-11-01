// This program tells you what day of the week it is on a given date.
// Inputs: int day, month, year
// Outputs: Error messages or day of the week (ex. Monday, Wednesday)
#include <string>

std::string dayOfTheWeek(int day,int month, int year){ 
  const int daysPerMonth[]={31,28,31,30,31,30,31,31,30,31,30,31};
  int daysApart;

  // Check for invalid inputs
  if(day < 0)
    return "Error: Day cannot be negative. ";
  if(month < 0)
    return "Error: Month cannot be negative. ";
  if(year < 0)
    return "Error: Negative years not supported. ";

  // Calculate number of days apart from genesis based on year
  daysApart=(year-2001)*365;
  for(unsigned i=0;i<month-1;++i){
    daysApart+=daysPerMonth[i];
  }
  daysApart+=day-1;

  // Add days from leap years for future dates
  for(unsigned i=2001;i<year;++i){
    if(isLeapYear(i))
      ++daysApart;
  }

  // Subtract days from leap years for past dates
  for(unsigned i=year;i<2000;++i){
    if(isLeapYear(i))
      --daysApart;
  }
  
  // Add or subtract days if the given year is a leap year
  if(isLeapYear(year)){
    if(month>2 && year>2001)
      ++daysApart;
    else if(month<2 && year<2001)
      --daysApart;
  }

  // Decide the day of the week given the total number of days apart
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
  return "Error: daysApart went out of bounds"; 	// if this point is reached ten daysApart%7 went out of bounds {-6,6}
}
