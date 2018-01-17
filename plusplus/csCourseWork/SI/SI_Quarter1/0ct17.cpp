#include <ctime>
#include <iostream>

using namespace std;

int main(){
    
    int t = time(0);
    
    cout << t << endl;
    int seconds = t % 60;
    t = t / 60;
    int minutes = t % 60;
    t = t / 60;
    int hours = t % 24 - 7;
    
    
    

    
    
    cout << hours << ":" << minutes << ":" << seconds << endl;
    
    /*
    t / 60 will give the while # of minutes
    t % 60 will give seconds left over
    
    */
    
    return 0;
}