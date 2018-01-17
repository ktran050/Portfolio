//  =============== BEGIN ASSESSMENT HEADER ================
/// @file mathematics.cpp
/// @brief Lab 8
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date November 25, 2014
///
/// @par Plagiarism Section
/// I hereby certify that I have not received assistance on this assignment,
/// or used code, from ANY outside source other than the instruction team.
//  ================== END ASSESSMENT HEADER ===============

#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

const int OK = 0;
const int DIV_ZERO = 1;
const int SQRT_ERR = 2;

int acquireOperands(const string &op, double &x, double &y, double &z);
int division(double a, double b, double &result);
int quadratic(double a, double b, double c, double &root1, double &root2);
int pythagorean(double a, double b, double &c);

int main(){
    string mathType;
    double j, k ,l, answer;
    cout << "Please choose an operation: " << endl;
    cin >> mathType;
    while(mathType != "quadratic" && mathType != "division" 
    && mathType != "pythagorean"){
        cout << "Error: Operation not supported." << endl;
        cin >> mathType;
    }
    acquireOperands(mathType, j, k, l);
    if(mathType == "division"){
        division(j,k, answer);
    }
    // else if(mathType == "quadratic"){
     
    // }
    // else{
        
    // }
}

int acquireOperands(const string &op, double &x, double &y, double &z){
    cout << "Enter your first number: " << endl;
    cin >> x;
    cout << "Enter your second number: " << endl;
    cin >> y;
    if(op == "quadratic"){
        cout << "Enter your third number: " << endl;
        cin >> z;
        return 3;
    }
    return 2;
}

int division(double a, double b, double &result){
    cout << "Equation: " << a << " / " << b << endl;
    if(b > 0 || b < 0){
        cout << "Result: " << a / b << endl;  
        return OK;
    }
    else{
        cout << "Error: Cannot divide by zero." << endl;
        return DIV_ZERO;
    }
}

int quadratic(double a, double b, double c, double &root1, double &root2){
    cout << "Equation: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
    cout << "Result: " << 
}
//Here are comments.