// URL: http://www.cprogramming.com/complete/guessing.html
// Date/Time:   6/29/2016 4:48 PM
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    srand(time(0));
    int number=(rand()%11)+10;
    int guess=-1;
    int trycount=0;
    
    // while(guess!=number && trycount<8){
        cout<<"number: "<< number<<endl;
    //     cout<<"Please enter a guess between 10 and 20: ";
    //     cin>>guess;
        
    //     if(guess<number)
    //     cout<<"Too low. ";
    //     else if(guess>number)
    //     cout<<"Too high. ";
    //     ++trycount;
    //     cout << "You have "<<8-trycount<<" tries left."<<endl;
    // }
    
    // if(guess==number)
    // cout<<"You guessed the number!"<<endl;
    // else
    // cout<<"Sorry, the number was: "<<number<<endl;
    
    return 0;
}