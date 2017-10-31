#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

bool Date::isLeap(int y) const{
    //if divisible by 4 more checking is needed
    if(y % 4 == 0){
        //if divisible by 100 but not by 400 its not a leap
        if(y % 100 == 0){
            //if divisible by 400 its a leap
            if(y % 400 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
    else{
        return 0;
    }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
    //if its not a leap year
    if(isLeap(y) == 0){
        //if its april, june, sept, or nov
        if((m == 4)||(m == 6)||(m == 9)||(m == 11)){
            return 30;
        }
        //if its feb
        else if(m == 2){
            return 28;
        }
        //if its the rest
        else{
            return 31;
        }
    }
    //if it is a leap year
    else{
        //if its april, june, sept, or nov
        if((m == 4)||(m == 6)||(m == 9)||(m == 11)){
            return 31;
        }
        //if its feb
        else if(m == 2){
            return 29;
        }
        //if its the rest
        else{
            return 32;
        }
    }
}

unsigned Date::number(const string &mn) const {
    if((mn == "January") || (mn == "january")){
        return 1;
    }
    else if((mn == "February") || (mn == "february")){
        return 2;
    }
    else if((mn == "March") || (mn == "march")){
        return 3;
    }
    else if((mn == "April") || (mn == "april")){
        return 4;
    }
    else if((mn == "May") || (mn == "may")){
        return 5;
    }
    else if((mn == "June") || (mn == "june")){
        return 6;
    }
    else if((mn == "July") || (mn == "july")){
        return 7;
    }
    else if((mn == "August") || (mn == "august")){
        return 8;
    }
    else if((mn == "September") || (mn == "september")){
        return 9;
    }
    else if((mn == "October") || (mn == "october")){
        return 10;
    }
    else if((mn == "November") || (mn == "november")){
        return 11;
    }
    else if((mn == "December") || (mn == "december")){
        return 12;
    }
    else{
        return 31;
    }
}
string Date::number(unsigned m) const{
    if(m == 1){
        return "January";
    }
    else if(m == 2){
        return "February";
    }
    else if(m == 3){
        return "March";
    }
    else if(m == 4){
        return "April";
    }
    else if(m == 5){
        return "May";
    }
    else if(m == 6){
        return "June";
    }
    else if(m == 7){
        return "July";
    }
    else if(m == 8){
        return "August";
    }
    else if(m == 9){
        return "September";
    }
    else if(m == 10){
        return "October";
    }
    else if(m == 11){
        return "November";
    }
    else if(m == 12){
        return "December";
    }
    else{
        return "Error";
    }
}
Date Date::addDays(int a) const{
    Date x;
    x.day = day;
    x.month = month;
    x.monthName = monthName;
    x.year = year;
    if(a < 0){
        x.day = static_cast<int>(x.day) - (a*-1);
    }
    else{
        x.day += a;
    }
    if(x.day > daysPerMonth(x.month, x.year)){
        ++x.month;
        if(x.month >= 13){
            ++x.year;
            x.month -= 12;
        }
        x.day -= daysPerMonth(x.month, x.year);
    }
    if(x.day <= 0){
        --x.month;
        if(x.month <= 0){
            --x.year;
            x.month += 12;
        }
        x.day = daysPerMonth(x.month, x.year) - x.day;
    }
    return x;
}

Date::Date(){
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}
Date::Date(unsigned m, unsigned d, unsigned y){
    int sweetch = 0;
    if((m <= 0) || (m >=13) || (d <= 0) || (d >= 28)){
        if(m <= 0){
            m = 1;
            sweetch = 1;
        }
        if(m >= 13){
            m = 12;
            sweetch = 1;
        }
        if(d <= 0){
            d = 1;
            sweetch = 1;
        }
        if(daysPerMonth(m, y) < d){
            d = daysPerMonth(m, y);
            sweetch = 1;
            }
        if(sweetch != 0){
            cout << "Invalid date values: Date corrected to " << m << "/"
            << d << "/" << y << "." << endl;
        }
    }
    day = d;
    month = m;
    monthName = number(m);
    year = y;
}
Date::Date(string mn, unsigned d, unsigned y){
    int sweetch = 0;
    if(number(mn) == 31){
        cout << "Invalid date value: Date corrected to 1/1/2000." << endl;
        day = 1;
        month = 1;
        monthName = "January";
        year = 2000;
    }
    else{
        if(d <= 0){
            d = 1;
            sweetch = 1;
        }
        if(daysPerMonth(number(mn), y) < d){
            d = daysPerMonth(number(mn), y);
            sweetch = 1;
        }
        if(sweetch != 0){
            cout << "Invalid date values: Date corrected to " << number(mn)
            << "/" << d << "/" << y << "." << endl;
        }
        day = d;
        month = number(mn);
        monthName = mn;
        year = y;
    }
}
void Date::printNumeric() const{
    cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const{
    cout << monthName << " " << day << ", " << year;
}