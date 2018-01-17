// This program implements the Monte Carlo Method for estimating the value of PI.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// given the coordinates of a point (x,y) computes if the point is inside the circle 
// centered at origin with radius R. Returns 'true' if it is inside, 'false' otherwise.

    bool is_inside(double x, double y, double R){
        if(sqrt(pow(x,2) + pow(y,2)) <= R){
            return true;
        }
        else{
            return false;
        }
    }

// given the side,s, of a square that is centered at origin, 
// chooses a random coordinates inside the square, and calls is_inside function 
// to test if the point is inside the circle or not.
// assign x and y to two random numbers between -s/2 and s/2
bool throw_dart(int s){
    int x, y, R;
    R = s / 2;
    x = (rand() % s) - R;
    y = (rand() % s) - R;
    cout << x << " " << y << endl;
    return is_inside(x, y, R);
}

// see the previous exercise to see an example. 
//Call the is_inside function and return its output. 
//You do not have to cast x,y to floats, it is done automatically.
int main(){
    srand(time(0));
    // const bool TRUE = 1;
    int side = 1000; // this is the side of the square and is also our resolution. 
    int tries; // this is the number of tries.
    double pi;
    
    //Ask the user for the number of tries using cout.
    cout << "How many tries would you like?" << endl;
    
    //Get the users input using cin.
    cin >> tries;
    int in_count = 0; //counter to track number of throws that fall inside
    
        for(int i = 0; i < tries; i++){
        //throw a dart using throw_dart method and increment the counter depending on its output.
            if(throw_dart(side) == true){
                ++in_count;
                // cout << in_count << endl;
            }
            cout << in_count << endl;
        }
    
    //Compute and display the estimated value of PI. Make sure you are not doing integer division.
    pi = static_cast<double>(4 * in_count) / tries;
    cout << "Pi equals: " << pi << endl;
    
    return 0;
}