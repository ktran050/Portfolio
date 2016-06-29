// URL: http://www.cprogramming.com/complete/guessing.html
// Date/Time:   6/29/2016 4:48 PM
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    srand(time(NULL));
    int number=rand()%100;
    int guess=-1;
    int trycount=0;
    
    while(guess!=number && trycount<8){
        cout<<"Please enter a guess: ";
        cin>>guess;
        
        if(guess<number)
        cout<<"Too low"<<endl;
        else if(guess>number)
        cout<<"Too high"<<endl;
        ++trycount;
    }
    
    if(guess==number)
    cout<<"You guessed the number!";
    else
    cout<<"Sorry, the number was: "<<number;
    
    return 0;
}