//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Lab 6
// Lab Section: 23
// Approach: Declaration goes here.
//=================================================
#include <iterator>
#include <utility>
#include <iostream>
using namespace std;

template<class L>
void selectionsort(L &l){
    // testing purposes
    int moves = 0;
    
    // pointer to the smallest value of the unsorted group
    auto foundIt = begin(l);
    auto traveler = begin(l);
    
    // while( beginning+count != end )
    while( traveler != end(l) ){
        foundIt = traveler;
        auto posedTaBe = foundIt;
        
        // loop from count to the end and find the smallest element
        for( auto curr = posedTaBe; curr != end(l) ; ++curr ){
            
            // find the smallest element out of the unsorted group
            if( *foundIt > *curr){ foundIt = curr;}
            // one comparison and if true then one more move
            
        } // end for loop
        if(*posedTaBe != *foundIt ){
            swap(*posedTaBe, *foundIt); // swap the element into place
            moves += 3; // swaps are 3 moves
        }
        ++traveler; // increment count
    } // end while loop
    // if( ){ cout << "moves: " << moves << endl; }
} // end function