//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab4.cpp
/// @brief Lab 4
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date October 28, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
using namespace std;
int main()

{
    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    if ( ex == 1 )
    {
        string userString;
        char firstLetter;
        char letter = 'a';
        int letterPositionTwo;
        
        // Ask user to input string
        cout << "Enter a string: " << endl;
        cin >> userString;
        
        // Extract the first character of the string provided using at(0)
        firstLetter = userString.at(0);
        cout << firstLetter << endl;
        
        // Use character math to calculate the position of the character in the
        //      alphabet
        letterPositionTwo = firstLetter - letter + 1;
        cout << letterPositionTwo << endl;
        
        // Output that location
        cout << firstLetter << " is letter " << letterPositionTwo;
        cout << " of the alphabet" << endl;
    }

    else if ( ex == 2 )
    {
        char userLetter;

        // Have user enter input
        cout << "Enter a character: " << endl;
        // Store in char datatype
        cin >> userLetter;
        // Tell user with if - else what kinda letter it is
        if((userLetter >= 'a') && (userLetter <= 'z'))
        {
            cout << "You entered a lowercase letter." << endl;
        }
        else if ((userLetter >= 'A') && (userLetter <= 'Z'))
        {
            cout << "You entered an uppercase letter." << endl;
        }
        else if ((userLetter >= '0') && (userLetter <= '9'))
        {
            cout << "You entered a numeric digit." << endl;
        }
        else
        {
            cout << "You entered an unknown character type." << endl;
        }
    } 
    return 0;

}