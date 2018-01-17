//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab3.cpp
/// @brief Lab 3
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date October 21, 2014
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

        // Storing two values
        int userValOne, userValTwo;
        // Both values aren't involved in any specific problem.
        // As per the example, both values are int.

        // Prompt user for input (just like the examples.)
        // Aquire two inputs
        cout << "Enter first integer: " << endl << endl;
        cin >> userValOne;
        cout << "Enter second integer: " << endl << endl;
        cin >> userValTwo;
    
        // Output the sum, product, integer, quotient, and modulus.
        // Have the same spacing as the examples.

        cout << userValOne << " + " << userValTwo;
        cout << " = " << userValOne + userValTwo << endl;
        cout << userValOne << " * " << userValTwo << " = ";
        cout << userValOne * userValTwo << endl;
        cout << userValOne << " / " << userValTwo << " = ";
        cout << userValOne / userValTwo << endl;
        cout << userValOne << " % " << userValTwo;
        cout << " = " << userValOne % userValTwo << endl;



    }

    else if ( ex == 2 )

    {
        // Variables: cost, paid, nickels , pennies, dimes, quarters, dollars
        // doubles: cost, paid int: nickels, pennies, dimes, dollars
        // const int: cent values of various coins, cent to dollar ratio,
        // loop variable is temporary storage
        int nickels, dimes, pennies, dollars, quarters, cents;
        double cost, paid, loop, totalChange;
        //    const int NICKEL_PRICE, PENNY_PRICE, DIME_PRICE, QUARTER_PRICE;


        // Ask for purchase amount and amount paid
        cout << "Enter purchase amount: " << endl;
        cin >> cost;
        cout << "Enter amount received: " << endl;
        cin >> paid;
        // Calculate total change and quantities of each denomination
        totalChange = paid - cost;
        cout << "Total Change: $" << totalChange << endl;
        loop = paid - cost;
        dollars = static_cast<int> (loop);
        cout << "dollars " << dollars << endl;
        cents = static_cast<int>((loop - dollars) * 100 + .5);
        //cout << "cents " << cents << endl;
        quarters = static_cast<int> (cents / 25);
        cout << "quarters " << quarters << endl;
        loop = cents % 25;
        dimes = loop / 10;
        cout << "dimes " << dimes << endl;
        loop = static_cast<int> (loop) % 10;
        nickels = loop / 5;
        cout << "nickels " << nickels << endl;
        pennies = static_cast <int> (loop) % 5;
        cout << "pennies " << pennies << endl;
    
    
        // Output total change and each type of money returned

 

        return 0;


    }
}


