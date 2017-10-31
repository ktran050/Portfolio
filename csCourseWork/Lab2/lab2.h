//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab2.h 
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
#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

//  =============== TEST FUNCTION DECLARATION ================

void testIsPrime();
void testPrimeCount();
void testListCopy();
void testListFunctions();
void testPrintLots();

//  =============== Part 1 ================

int primeCount( forward_list<int> lst );
// Count the number of prime numbers in a singly linked list and
/// impliment a helper function bool isPrime( int i )

bool isPrime( int i );
// Helper function to decide whether the number entered is prime

//  =============== Part 2 ================
template<class Type>
class Node{
    private:
    public:
        Type data;
        Node* next;
        Node(){ next = 0;}
        Node( Type val ){ data = val; next = 0;}
};
// Write a member function void elementSwap(int pos)
// This function swaps the element at pos and pos+1
// DO NOT just swap the data values
// This function is a part of a class named List
// Make list's constructors as well as Node's
template<class Type>
class List{
    private:
        
    public:
        Node<Type>* head;
        Node<Type>* tail;
        List(){ head = 0; tail = 0;}
        void push_back( Type val );
        void pop_back();
        void print();
        void elementSwap(int pos);
};
template<class Type>
void List<Type>::push_back( Type val ){
    if( head == 0){
        Node<Type>* temp = new Node<Type>(val);
        head = temp; tail = temp;
    }
    else{
        Node<Type>* temp = new Node<Type>(val);
        tail->next = temp;
        tail = temp;
    }
}
template<class Type>
void List<Type>::pop_back(){
    if(head == 0){
        return;
    }
    else if(head == tail){ delete head; head = 0; tail = 0; }
    else{
        Node<Type>* traveler = head;
        while(traveler->next != tail){
            traveler = traveler->next;
        }
        delete tail;
        tail = traveler;
    }
}
template<class Type>
void List<Type>::print(){
    Node<Type>* traveler = head;
    while(traveler != 0){
        cout << "Data: " << traveler->data << endl;
        traveler = traveler->next;
    }
}
template<class Type>
void List<Type>::elementSwap(int pos){
    if(head == 0){
        return;
    }
    else if(head == tail){
        return;
    }
    else{
        Node<Type>* traveler = head;
        Node<Type>* holdPos;
        Node<Type>* holdPosPlus;
        Node<Type>* holdPosMinus;
        
        for(int i = 1; i < pos - 1; ++i){
            if(traveler->next == 0){
                cout << "ERROR: Invalid position" << endl;
                return;
            }
            traveler = traveler->next;
        }
        holdPosMinus = traveler;
        
        if(traveler->next == 0){
                cout << "ERROR: Invalid position" << endl;
                return;
        }
        traveler = traveler->next;
        holdPos = traveler;
        
        if(traveler->next == 0){
                cout << "ERROR: Invalid position" << endl;
                return;
        }
        traveler = traveler->next;
        holdPosPlus = traveler;
        
        holdPos->next = holdPosPlus->next;
        holdPosPlus->next = holdPos;
        holdPosMinus->next = holdPosPlus;
    }
}

//  =============== Part 3 ================

// Everything is in the .cpp because of the usage of templates

//  =============== Part 4 ================
template <class Type>
void printLots (forward_list<Type> L, forward_list <int> P);
// Given the positions of what to cout in P
// Cout the the data at those positions from L
