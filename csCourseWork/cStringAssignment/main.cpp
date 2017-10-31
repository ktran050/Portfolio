// Write the four c-str functions we should know
/// strcat
/// strcpy
/// strcmp
/// strlen
// Write everything over again except strcmp as a recurrsive

#include <iostream>

using namespace std;

void CSTRINGS::strcat( char arr[] ){
    int DestCount = 0;
    int SourCount = 0;
    // Counters for sizes of the source and destination cstrings
    
    while(this[DestCount] != NULL){
        ++DestCount;
    }
    // While loop to count destination's size
    
    while(arr[SourCount] != NULL){
        ++SourCount;
    }
    // While loop to count source's size
    
    char newString[SourCount + DestCount];
    // Create a new string with both source's size
    
    for(int q = 0; q < DestCount; ++q){
        newString[q] = this->[q];
    }
    // Add destination string
    
    for(int q = 0; q < SourCount; ++q){
        
    }
    // Add source string
}

int main(){
    
    return 0;
}