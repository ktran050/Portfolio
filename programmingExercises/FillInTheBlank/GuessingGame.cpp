/*
#include <stdlib.h>
#include <iostream>

using namespace std;
int main()
{
int number=rand()___; 
int
guess=-1;
int trycount=0;
while(guess__number __ trycount<8)
{

cout__"Please enter a guess: ";
cin__guess;
__(guess_number)

cout<<"Too low"<<endl;
 __(guess_number)

cout<<"Too high"<<endl;
_______________;
_

if(guess==number)
cout<<"You guessed the number";
____

cout<<"Sorry, the number was: "<<_____;
______
0;
_
*/

#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
    srand(time(NULL));
    int number=rand()%100;
    int guess=-1;
    int trycount=0;
    while(guess!=number && trycount<8){
        cout<<"Please enter a guess ";
        cin >> guess;
        
        if(guess<number)
        cout<<"Too low"<<endl;
        else if(guess>number)
        cout<<"Too high"<<endl;
        ++trycount;
    }
    
    if(guess==number)
    cout<<"You guessed the number!"<<endl;
    
    else
    cout<<"Sorry, the number was: "<<number<<endl;
    return 0;
}