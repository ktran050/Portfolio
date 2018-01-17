#include <iostream>
#include <string>

using namespace std;

class Date{
    unsigned day;
    unsigned month;
    string monthName;
    unsigned year;
    
    bool isLeap(int);
    unsigned daysPerMonth(unsigned, unsigned);
    unsigned number(const string &) const;
    string number(unsigned) const;
    
    public:
    Date();
    Date(unsigned, unsigned, unsigned);
    Date(string, unsigned, unsigned);
    void printNumeric() const;
    void printAlpha() const;
};

bool Date::isLeap(int y){
    if(y % 4 == 0){
        if(y % 100 == 0){
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

unsigned Date::daysPerMonth(unsigned m, unsigned y){
    if(isLeap(y) != 0){
        if((m == 4)||(m == 6)||(m == 9)||(m == 11)){
            return 30;
        }
        else if(m == 2){
            return 28;
        }
        else{
            return 31;
        }
    }
    else{
        if((m == 4)||(m == 6)||(m == 9)||(m == 11)){
            return 31;
        }
        else if(m == 2){
            return 29;
        }
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
        cout << "Error: month name not recognized in function number."
        << endl;
        return 99999;
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
        cout << "Error: month number not recognized in function number"
        << endl;
        return "Error";
    }
}

Date::Date(){
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}
Date::Date(unsigned m, unsigned d, unsigned y){
    day = d;
    month = m;
    monthName = number(m);
    year = y;
}
Date::Date(string mn, unsigned d, unsigned y){
    day = d;
    month = number(mn);
    monthName = mn;
    year = y;
}
void Date::printNumeric() const{
    cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const{
    cout << monthName << " " << day << ", " << year;
}

int main(){
    return 0;
}