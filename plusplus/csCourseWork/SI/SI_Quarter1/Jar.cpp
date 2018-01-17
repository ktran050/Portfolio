#include <iostream>
using namespace std;



int main()
{
    //Ask how many jars
    //Ask how many gallons
    
    double gallons, totalJars, cost, leftOver, jarSize, jarCost;
    
    cout << "How much water do you have?" << endl;
    cin >> gallons;
    
    cout << "How big are the jars?" << endl;
    cin >> jarSize;
    
    cout << "How much are you paying per jar?" << endl;
    cin >> jarCost;
    
    totalJars = gallons / jarSize;
    cost = totalJars * jarCost;
    leftOver = gallons % jarSize;
    
    cout << "That'll be " << cost << " dollars." << endl;
    cout << "You have " << leftOver << " gallons of water left over." << endl;
    
    return 0;   
}