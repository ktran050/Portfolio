//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 4 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 27th, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 023
/// @par
///     TA: Brian
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============


//Write a program to add, subtract, multiply, and divide fractions
//use a class to hold fractions using pairs (numerator, denominator)
//numerator and denominator should be PRIVATE
//create 3 constuctors
//one with 2 parameters (num, denom)
// one with 1 parameter (int/ 1)
//one wiht no parameters (0/1)

#include <iostream>

using namespace std;

class Rational{
    int numer;
    int denom;
    
 public:
    Rational();
    Rational(int, int);
    Rational(int);
    int displayNum();
    int displayDen();
    void display() const;
    const Rational add(const Rational &q) const;
    const Rational subtract(const Rational &q) const;
    const Rational multiply(const Rational &q) const;
    const Rational divide(const Rational &q) const;
};

//Create objects based on the number of parameters given
Rational::Rational(){
    numer = 0;
    denom = 1;
}
Rational::Rational(int a, int b){
    numer = a;
    denom = b;
}
Rational::Rational(int a){
    numer = a;
    denom = 1;
}

//First 2 return numerator and denominator
//Last one displays the objects numerator and denominator
int Rational::displayNum(){
    return numer;
}
int Rational::displayDen(){
    return denom;
}
void Rational::display() const{
    cout << numer << " / " << denom << endl;
}


//The functions doing the actual calculations
const Rational Rational::add(const Rational &q) const{
    Rational z = Rational((numer*q.denom + denom*q.numer), (denom*q.denom));
    return z;
}
const Rational Rational::subtract(const Rational &q) const{
    Rational z = Rational((numer*q.denom - denom*q.numer),(denom*q.denom));
    return z;
}
const Rational Rational::multiply(const Rational &q) const{
    Rational z = Rational((numer*q.numer),(denom*q.denom));
    return z;
}
const Rational Rational::divide(const Rational &q) const{
    Rational z = Rational((numer*q.denom),(q.numer*denom));
    return z;
}

//Main to test things
int main(){
    
//Creates test objects
    Rational a(6, 9);
    Rational b(9, 6);
    Rational c;
    Rational d(1000);
    Rational e;
    
//test their values
    // a.display();
    // b.display();
    // c.display();
    // d.display();
    // e.display();
    
//call addition
    cout << "C add: ";
    c = a.add(b);
    c.display();
    
    cout << "C subract: ";
    c= a.subtract(b);
    c.display();
    
    cout << "C multiply: ";
    c= a.multiply(b);
    c.display();
    
    cout << "C divide: ";
    c= a.divide(b);
    c.display();
    return 0;
}