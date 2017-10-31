// Name: Kevin Tran
// SID: 861172609
// Date: 4/13/2013
// Approach: 
///
#ifndef __Node__
#define __Node__
#include <iostream>
using namespace std;

class Node{
    private:
        
    public:
        char ip;
        Node( char data );
        Node* next;
        
        void display();
        char retChar();
};

#endif