//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861182609
// Assignment Name: Assignment 8
// Lab Section: 23
// Approach: Test harness goes here.
//=================================================
#include "dfs.h"
#include <vector>
using namespace std;
int main(){
    
    // create a test adjacency list
    vector<vector<bool> > sparta( 8, vector<bool>(8, false) );
    sparta.at(0).at(1) = true;
    sparta.at(2).at(5) = true;
    sparta.at(4).at(6) = true;
    sparta.at(5).at(1) = true;
    sparta.at(5).at(6) = true;
    sparta.at(6).at(5) = true;
    sparta.at(6).at(7) = true;
    sparta.at(7).at(5) = true;
    
        // output the test list
    cout << "pre: " << endl;
    for(int i = 0; i < 8; ++i){
        
        if( i == 0 ){ // special case for the top row output the index
            cout << " ";
            for(int c = 0; c < 8; ++c){
                cout << " " << c;
            }
            cout << endl;
        }
        
        cout << i; // special case for first column, output the index
        for(int c = 0; c < 8; ++c){
            cout << " " << sparta.at(i).at(c);
        }
        cout << endl;
    }
    
    
    // // call dfs
    // dfs(sparta);
    
    // // output the test list
    // cout << "post(start0): " << endl;
    // for(int i = 0; i < 8; ++i){
        
    //     if( i == 0 ){ // special case for the top row output the index
    //         cout << " ";
    //         for(int c = 0; c < 8; ++c){
    //             cout << " " << c;
    //         }
    //         cout << endl;
    //     }
        
    //     cout << i; // special case for first column, output the index
    //     for(int c = 0; c < 8; ++c){
    //         cout << " " << sparta.at(i).at(c);
    //     }
    //     cout << endl;
    // }
    
    // call dfs
    dfs(sparta,2);
    
    // output the test list
    cout << "post(start2): " << endl;
    for(int i = 0; i < 8; ++i){
        
        if( i == 0 ){ // special case for the top row output the index
            cout << " ";
            for(int c = 0; c < 8; ++c){
                cout << " " << c;
            }
            cout << endl;
        }
        
        cout << i; // special case for first column, output the index
        for(int c = 0; c < 8; ++c){
            cout << " " << sparta.at(i).at(c);
        }
        cout << endl;
    }
    
    return 0;
}