//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab6.cpp
/// @brief Lab 6
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date November 11, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    
    if (1 == ex){
        int x = 0, y = 0, tempTarg;
        // Ask user for two inputs, x and y, separated by space
        cout << "Enter beginning and ending numbers, separated by space: "
        << endl;
        cin >> x >> y;
        // Output [x,y]
        for( ; x <= y; ++x ){
            cout << x;
            if(x+1 <= y){
                cout << ", ";
            }
        }
            
        
        
        // Ask user for two inputs, x and y, separated by space
        cout << endl << "Enter beginning and ending numbers, ";
        cout << "separated by space: " << endl;
        cin >> x >> y;
        // Output [x,y] (or as close to y as possible) by adding two
        tempTarg = y - ((y - x) % 2);
        for( ; x <= tempTarg; x += 2){
            cout << x;
            if(x+2 <= tempTarg){
                cout << ", ";
            }
        }
        
        // Ask user for two inputs, x and y, separated by space
        cout << endl << "Enter the beginning and largest positive numbers, ";
        cout << "separated by space:" << endl;
        cin >> x >> y;
        // Output [x, y * -2] by multiplying by negative two
        for( ; x <= y ; x *= -2 ){
            cout << x;
            if(x * - 2 <= y ){
                cout << ", ";
            }
        }
        cout << endl;
        
    }
    
    else {
        int userGrade, a = 0, b = 0, c = 0, d = 0, f = 0;
        cout << "Enter one or more grades, or -1 to stop:" << endl;
        
        // Receive user input until -1 is input
        do{
            cin >> userGrade;
            if((userGrade <= 100) && (userGrade >= 90)){
                ++a;
            }
            if((userGrade <= 89) && (userGrade >= 80)){
                ++b;
            }
            if((userGrade <= 79) && (userGrade >= 70)){
                ++c;
            }
            if((userGrade <= 69) && (userGrade >= 60)){
                ++d;
            }
            if((userGrade <= 59) && (userGrade >= 0)){
                ++f;
            }
        }while(userGrade != -1);
        // Record # of each grade AFTER all of the grades are input
        /*You will need a separate int variable to keep track of the 
        number receiving each letter grade; 
        increment that variable within a branch of an if / else if / else 
        structure;
        make sure the SENTINEL isn't accidentally entered as a grade.
        Since we do not know how many iterations the loop will execute,
        the while or do-while loop is the best choice for 
        this exercise. */
        cout << "The grades breakdown is:" << endl;
        cout << "As: " << a << endl << "Bs: " << b << endl;
        cout << "Cs: " << c << endl << "Ds: " << d << endl;
        cout << "Fs: " << f << endl;

        
    }
    return 0;
}