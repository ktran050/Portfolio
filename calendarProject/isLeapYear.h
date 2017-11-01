// This function tells you whether a year is a leap year or not.
// Input: int
// Output: bool
// Leap years are years divisible by 4. The caveeat is years divisible by 100 are NOT leap years, except for those also divisible by 400.
// Takes int just to make the program more general

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
