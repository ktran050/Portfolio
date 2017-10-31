//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab7.cpp
/// @brief Lab 7
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date November 17, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int genRandInt(int smallNum, int bigNum) {
    int tempRand = (rand() % (bigNum - smallNum + 1)) + smallNum;
    // cout << "Random number: " << tempRand << endl;
    return tempRand;
}

int main(){
    int ex;
    
    cout << "Which exercise?" << endl;
    cin >> ex;
    
    if(ex == 1){
        srand(time(0));
        int smallNum, bigNum, tempVar;
        
        cout << "Enter the smallest possible number: " << endl;
        cin >> smallNum;
        
        cout << "Enter the biggest possible number:" << endl;
        cin >> bigNum;
        
        tempVar = genRandInt(smallNum, bigNum);
        cout << "Random number: " << tempVar << endl;
        tempVar = genRandInt(smallNum, bigNum);
        cout << "Random number: " << tempVar << endl;
        tempVar = genRandInt(smallNum, bigNum);
        cout << "Random number: " << tempVar << endl;
    }
    
    if(ex == 2){
        srand(time(0));
        string userResponse = "yes";
        int smallNum = 1, bigNum = 2;
        
        do{
            cout << "Flip: ";
            if(genRandInt(smallNum, bigNum) == 1){
                cout << "heads" << endl;
            }
            else{
                cout << "tails" << endl;
            }
            cout << "Toss the coin again (yes/no)?" << endl;
            cin >> userResponse;
        }while(userResponse != "no");
        
    }
    
    return 0;
}


/* Write a function
    name it GenRandInt
    integer return type
    two integers
    the first integer is the smallest
    the second is the biggest
        
    Use the function multiple times
    Store the returned result
    Use the key phrase "Random number" to preface your output results,
*/
