//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Lab 4
// Lab Section: 23
// TA: 
//
// I hereby certify that I have not received 
// assistance on this assignment, or used code,
// from ANY outside source other than the
// instruction team. 
//=================================================
#ifndef __lab4__  // Guard
#define __lab4__

#include <iostream> // Includes and namespace
#include <queue>
#include <cstdlib>
#include <utility>
#include <stack>
using namespace std;

// ============================ Pre order =============================
void CPTree_Pre(int k, int m, int n){
    if( (m + n) >= k ){
        return;
    }
    else{
        cout << m << " " << n << endl;
        CPTree_Pre(k, (2*m - n), m);    // first child
        CPTree_Pre(k, (2*m + n), m);    // second child
        CPTree_Pre(k, (m + 2*n), n);    // third child
    }
}
// k is the constraint for the tree
// m is the first number in the "node"
// n is the second number in the "node"
// this function is called only by headCPTree_pre

void headCPTree_Pre(int k){ // Code
    if(k < 4){  // The sum of two coprimes can't be less than 4
        cout << "Error: k is less than the node's children" << endl;
        exit(-1);
    }
    else if(k == 4){    // If k is 4 the only comprimes less than that are (2,1)
        cout << "pre-order" << endl;
        cout << "2 1" << endl;
    }
    else{   // If it's anything but 4 and <4 then call recursive function
        cout << "pre-order" << endl;
        CPTree_Pre(k, 2, 1);    // first child
        CPTree_Pre(k, 3, 1);    // second child
    }
}
// k is the constraint for the tree

// ============================ Post order =============================
void CPTree_Post(int k, int m, int n){
    if( (m + n) >= k ){
        return;
    }
    CPTree_Post(k, (2*m - n), m);    // first child
    CPTree_Post(k, (2*m + n), m);    // second child
    CPTree_Post(k, (m + 2*n), n);    // third child
    cout << m << " " << n << endl;
}
// k is the constraint for the tree
// m is the first number in the "node"
// n is the second number in the "node"
// this function is called only by headCPTree_pre

void headCPTree_Post(int k){ // Code
    if(k < 4){  // The sum of two coprimes can't be less than 4
        cout << "Error: k is less than the node's children" << endl;
        exit(-1);
    }
    else if(k == 4){    // If k is 4 the only comprimes less than that are (2,1)
        cout << "post-order" << endl;
        cout << "2 1" << endl;
    }
    else{   // If it's anything but 4 and <4 then call recursive function
        cout << "post-order" << endl;
        CPTree_Post(k, 2, 1);    // first child
        CPTree_Post(k, 3, 1);    // second child
    }
}
// k is the constraint for the tree

// ============================ Sorted order =============================
void CPTree_Sorted(int k, int m, int n, priority_queue< pair<int,int> >& cc){
    if( (m + n) >= k ){
        return;
    }
    CPTree_Sorted(k, (2*m - n), m, cc);    // first child
    CPTree_Sorted(k, (2*m + n), m, cc);    // second child
    CPTree_Sorted(k, (m + 2*n), n, cc);    // third child
    cc.push( pair<int,int>(m,n) );
}
// k is the constraint for the tree
// m is the first number in the "node"
// n is the second number in the "node"
// this function is called only by headCPTree_pre

void headCPTree_Sorted(int k){ // Code
    priority_queue< pair<int,int> > results;
    if(k < 4){  // The sum of two coprimes can't be less than 4
        cout << "Error: k is less than the node's children" << endl;
        exit(-1);
    }
    else if(k == 4){    // If k is 4 the only comprimes less than that are (2,1)
        cout << "Sorted-order" << endl;
        cout << "2 1" << endl;
    }
    else{   // If it's anything but 4 and <4 then call recursive function
        cout << "Sorted-order" << endl;
        CPTree_Sorted(k, 2, 1, results);    // first child
        CPTree_Sorted(k, 3, 1, results);    // second child
        
        stack< pair<int,int> > outputList;
        while( !results.empty() ){  // output loop
            outputList.push( results.top() );
            results.pop();
        }
        while( !outputList.empty() ){
            cout << outputList.top().first << " "
            << outputList.top().second << endl;
            outputList.pop();
        }
    }
}
// k is the constraint for the tree
// results holds the ordered list
// queue will hold and output
// test

#endif  // Finished
