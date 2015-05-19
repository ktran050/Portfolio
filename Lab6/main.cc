//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Lab 6
// Lab Section: 23
// Approach: 
//=================================================
// Implement selection sort.
// Take the smallest element and swaps it to the beginning, Take the next smallest
// and swap it to the spot right after the sorted element. Repeat until sorted.
//
// If the algorithm is on the ith item, i-1 elements are already sorted and in the
// first i-1 locations. Everything else goes from i to the end and is unsorted.
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include "selectionsort.h"
using namespace std;

int main(){
    
    // populate
    vector<int> OTTa;
    OTTa.push_back(2);
    OTTa.push_back(4);
    OTTa.push_back(5);
    OTTa.push_back(1);
    OTTa.push_back(8);
    OTTa.push_back(9);
    // pre
    cout << "pre:  ";
    for(unsigned i = 0; i < OTTa.size(); ++i){
        cout << OTTa[i] << " ";
    }
    cout << endl;
    selectionsort(OTTa);
    // post
    cout << "post: ";
    for(unsigned i = 0; i < OTTa.size(); ++i){
        cout << OTTa[i] << " ";
    }
    cout << endl;
    
    //populate
    vector< pair<int, int> > OTTb;
    OTTb.push_back( pair<int,int> (1,2) );
    OTTb.push_back( pair<int,int> (3,-1) );
    OTTb.push_back( pair<int,int> (-1,3) );
    OTTb.push_back( pair<int,int> (0,0) );
    OTTb.push_back( pair<int,int> (2,3) );
    OTTb.push_back( pair<int,int> (1,2) );
    OTTb.push_back( pair<int,int> (1,-2) );
    OTTb.push_back( pair<int,int> (8,10) );
    // pre
    cout << "pre:  ";
    for(unsigned i = 0; i < OTTb.size(); ++i){
        cout << "(" << OTTb.at(i).first << "," << OTTb.at(i).second << ") ";
    }
    cout << endl;
    selectionsort(OTTb);
    // post
    cout << "post: ";
    for(unsigned i = 0; i < OTTb.size(); ++i){
        cout << "(" << OTTb.at(i).first << "," << OTTb.at(i).second << ") ";
    }
    cout << endl;
        // (1,2), (3,-1), (-1,3), (0,0), (2,3), (1,2), (1,-2), (8,10) };
    
    // populate
    list< pair<int,int> >OTTc;
    OTTc.push_back( pair<int,int> (10,2) );
    OTTc.push_back( pair<int,int> (-3,-1) );
    OTTc.push_back( pair<int,int> (-8,0) );
    OTTc.push_back( pair<int,int> (1,1) );
    OTTc.push_back( pair<int,int> (1,1) );
    OTTc.push_back( pair<int,int> (0,0) );
    OTTc.push_back( pair<int,int> (10,2) );
    OTTc.push_back( pair<int,int> (5,5) );
    OTTc.push_back( pair<int,int> (5,-5) );
    OTTc.push_back( pair<int,int> (0,0) );
    OTTc.push_back( pair<int,int> (10,2) );
    // pre
    cout << "pre:  ";
    for(auto it = OTTc.begin(); it != OTTc.end(); ++it){
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(OTTc);
    // post
    cout << "post: ";
    for(auto it = OTTc.begin(); it != OTTc.end(); ++it){
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    
    // populate
    list< pair<int,int> >OTTd;
    OTTd.push_back( pair<int,int> (-1,3) );
    OTTd.push_back( pair<int,int> (0,0) );
    OTTd.push_back( pair<int,int> (1,-2) );
    OTTd.push_back( pair<int,int> (1,2) );
    OTTd.push_back( pair<int,int> (1,2) );
    OTTd.push_back( pair<int,int> (2,3) );
    OTTd.push_back( pair<int,int> (3,-1) );
    OTTd.push_back( pair<int,int> (8,10) );
    // pre
    cout << "pre:  ";
    for(auto it = OTTd.begin(); it != OTTd.end(); ++it){
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    selectionsort(OTTd);
    // post
    cout << "post: ";
    for(auto it = OTTd.begin(); it != OTTd.end(); ++it){
        cout << "(" << it->first << "," << it->second << ") ";
    }
    cout << endl;
    
    return 0;
}