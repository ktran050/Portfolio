// Name: Kevin Tran
// SID: 861172609
// Date: 4/13/2013
// Approach: 
///
#ifndef __Lab1List__
#define __Lab1List__

#include <list>
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

class Lab1List{
    private:
        list<Node> qq;
        Node* head;
        Node* tail;
    public:
        Lab1List();
        // Default constructor
        
        Lab1List( const string& str );
        // Make a singly-linked list from a passed in string typed object
        /// Each character goes into a separate node
        
        ~Lab1List();
        // Deconstructor
        
        
        void push( char val );
        // inserts 'val' to the end of the list
        
        void display() const;
        // prints the contents of list
        
        void rotate( int k );
        // Rotates the liked list counter-clockwise by k positions
        
        void pop_front();
        // Destroys the front-most node
        
        
        Lab1List& operator+( Lab1List& head2 );
        // Add the rotated linked list and returns it. This receives a new
        /// rotated linked list object. Output may be weird.
};

#endif