//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Assignment 6
// Lab Section: 23
// Approach: Declaration goes here.
//=================================================
#include <iostream>
#include <vector>
#include "bucket.h"
using namespace std;

int main(){
    
    cout << "Test 1: empty vector" << endl;
    vector<unsigned> cc;
    bucketsort( cc );
    cout << "Test 2: 1 element vector" << endl;
    cc.push_back(8);
    bucketsort(cc);
    cout << "Test 3: 69 element vector" << endl;
    for(int i = 0; i < 69; ++i){
        cc.push_back(i);
    }
    bucketsort(cc);
    
    cout << "Test 4: the sorting" << endl;
    vector<unsigned> dd;
    for(int i = 0; i < 69; ++i ){
        dd.push_back(69 - i);
    }
    cout << "pre: ";
    for(int i = 0; i < dd.size(); ++i ){
        cout << dd.at(i) << " ";
    }
    cout << endl;
    bucketsort(dd);
    cout << "post: ";
    for(int i = 0; i < dd.size(); ++i ){
        cout << dd.at(i) << " ";
    }
    cout << endl;
    
    
    return 0;
}