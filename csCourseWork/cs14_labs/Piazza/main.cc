// Name: Kevin Tran
// SID: 861172609
// Date: 4/13/2013
// Approach: 
///
#include <iostream>
#include "Lab1List.h"
#include "Node.h"
using namespace std;


void test1(){
    cout << "Test 1: Default constructor / deconstructor test -- Lab1List.h"
    << endl;
    Lab1List aa;
    cout << "=========================================================" << endl;
}

void test2(){
    cout << "Test 2: Default constructor / deconstructor test -- Node.h"
    << endl << "Test value: 'z' " << endl;
    Node ba( 'z' );
    ba.display();
    cout << "=========================================================" << endl;
}


int main(){
    
    test1();
    // test2();
    
    return 0;
}