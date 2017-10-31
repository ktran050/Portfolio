//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab2.cpp 
/// @brief Lab 2 for CS 14 Spring 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date April 21st, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 023
/// @par
///     TA:
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <forward_list>
#include <iostream>
#include <vector>
#include <list>
#include "lab2.h"
using namespace std;

template <class Type>
void print( forward_list<Type> AJ );
template <class Type>
forward_list<Type> listCopy( forward_list<Type> L, forward_list<Type>& P);

int main(){
    testIsPrime();
    testPrimeCount();
    testListCopy();
    testListFunctions();
    testPrintLots();
    return 0;
}

//  =============== Part 1 ================
int primeCount( forward_list<int> lst ){
    if( lst.empty() ){
        return 0;
    }
    else{
        // cout << lst.front() << endl;
        if( isPrime( lst.front()) ){
            lst.pop_front();
            return 1 + primeCount( lst );
        }
        else{
            lst.pop_front();
            return primeCount( lst );
        }
    }
}
// Returns zero if empty
// End/Base case is when the beginning of the list is the end
// Else pop_front and have a recursive call

void testPrimeCount(){
    cout << "=============== primeCount ================" << endl;
    forward_list<int> testList1;
    for(int i=0; i<10;++i){testList1.push_front(i);}
    print( testList1 );
    cout << primeCount( testList1 ) << endl;
}

bool isPrime( int i ){
    if( i % 2 == 0){
        return 0;
    }
    else{
        return 1;
    }
}
// If i mod 2 is zero then numbers even else its odd.
void testIsPrime(){
    cout << "=============== isPrime ================" << endl;
    if( isPrime(0) ) cout << "Prime: 0" << endl;
    else cout << "Even: 0" << endl;
    
    if( isPrime(-7) ) cout << "Prime: -7" << endl;
    else cout << "Even: -7" << endl;
    
    if( isPrime(99) ) cout << "Prime: 99" << endl;
    else cout << "Even: 99" << endl;
    
    if( isPrime(8) )cout << "Prime: 8" << endl;
    else cout << "Even: 8" << endl;
    
    if( isPrime(-100) ) cout << "Prime: -100" << endl;
    else cout << "Even: -100" << endl;
}

//  =============== Part 2 ================

void testListFunctions(){
    cout << "=============== ListFunctions ================" << endl;
    List<int> aa;
    aa.pop_back();
   for(int i = 0; i < 10; ++i){
       aa.push_back( i );
   }
    // aa.print();
    aa.elementSwap( 20 );
    aa.print();
}

//  =============== Part 3 ================
template <class Type>
forward_list<Type> listCopy( forward_list<Type> L, forward_list<Type>& P ){
    L.reverse();
    P.reverse();
    while( !L.empty() ){
        P.push_front( L.front() );
        L.pop_front();
    }
    P.reverse();
    return P;
}
// Concatenate a reversed list L to the back of P
/// By using reverses and push_front we can avoid too much hassle

void testListCopy(){
    cout << "=============== listCopy ================" << endl;
    forward_list<int> LL;
    LL.push_front(3);
    LL.push_front(2);
    LL.push_front(1);
     
    forward_list<int> PP;
    PP.push_front(6);
    PP.push_front(5);
    PP.push_front(4);
    
    cout << "Before listCopy: " << endl;
    print( LL ); print( PP );
    listCopy( LL, PP );
    cout << "After listCopy: " << endl;
    print( PP );
}

template <class Type>
void print( forward_list<Type> AJ ){
    while( !AJ.empty() ){
        cout << AJ.front() << " ";
        AJ.pop_front();
    }
    cout << endl;
}
// Function to display

//  =============== Part 4 ================
template <class Type>
void printLots (forward_list<Type> L, forward_list<int> P){
    vector<Type> cheeky;
    L.reverse();
    while( !L.empty() ){
        cheeky.push_back( L.front() );
        L.pop_front();
    }
    while( !P.empty() ){
        cout << cheeky.at( P.front() ) << " ";
        P.pop_front();
    }
    cout << endl;
}

void testPrintLots(){
    cout << "=============== printLots ================" << endl;
    forward_list<int> inventory = {0,4,5,6,10};
    cout << "Inventory: "; print( inventory ); cout << endl;
    
    forward_list<int> ayyy;
    for(int i = 0; i < 26; ++i){
        ayyy.push_front(i);
    }
    cout << "ayyy: "; print( ayyy ); cout << endl;
    
    printLots(ayyy, inventory);
    
}