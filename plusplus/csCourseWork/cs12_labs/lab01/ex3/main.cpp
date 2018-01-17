//  =============== BEGIN ASSESSMENT HEADER ================
/// @file Exercise 1 / main.cpp 
/// @brief Lab 1 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 8th, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 023
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <vector>

using namespace std;


//function Search
//find the number the user had input
int search(int p, const vector <int> &v){
    int tempSwitch = -1;
    for(int i = 0; i < v.size(); ++i){
        if(v.at(i) == p){
            tempSwitch = i;
            i = v.size();
        }
    }
    if(tempSwitch == -1){
        return -1;
    }
    else{
        return tempSwitch;
    }
}

//function Remove
//take the vector out using function Search
void remove(vector <int> &v, int p){
    if(search(p, v) != -1){
        int stain = search(p, v);
        for(int i = stain; i < v.size() - 1; ++i){
            swap(v.at(i), v.at(i + 1));
        }
        v.pop_back();
    }
    v.pop_back();
}

//function Main
//receive input until user enters 0
//put those inputs into a vector (but not 0)
//ask the user what number to search for
//print the first index that number is found in
//remove the index (if it exists) and print the new vector
int main(){
    vector <int> storage;
    int userInput, targNum;
    do{
        cout << "Please enter in integers (0 to stop): " << endl;
        cin >> userInput;
        storage.push_back(userInput);
    }while(userInput != 0);
    
    cout << "What number would you like to find and remove?: " << endl;
    cin >> targNum;
    
    cout << "Found: " << search(targNum, storage) << endl;
    
    remove(storage, targNum);
    cout << "Result: ";
    for(int i = 0; i < storage.size(); ++i){
        cout << storage.at(i) << " ";
    }
     
    return 0;
}