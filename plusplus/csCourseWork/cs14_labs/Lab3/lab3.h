//====================HEADER===================
//
// Name: Kevin Tran
// SID: 861172609
// Date: 4/26/2015
// Approach: lab3.h contains all of the implementation
//
//====================HEADER===================
#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
using namespace std;

// typedef int T;
/// For testing purposes
template<class T>
class TwoStackFixed{
    private:
        
    public:
    // Declarations here and definitions further below
        unsigned sizeStack1;
        unsigned sizeStack2;
        unsigned partition;
        unsigned arrSize;
        T* arr;
    
        TwoStackFixed( int size, int maxtop );
        // Constructor should create an array of size stack
        // Create two stacks in this array
        // The partition of stacks is defined by max top's value
        
        void pushStack1( T value );
        void pushStack2( T value );
        // Functions to add to each stack
        
        T popStack1();
        T popStack2();
        // Functions to pop each stack
        
        bool isFullStack1();
        bool isFullStack2();
        // Function checking whether each stack is full
        
        bool isEmptyStack1();
        bool isEmptyStack2();
        // Function checking whether each stack is empty
        
        void display();
        // Displays the whole array
};

template<class T>
TwoStackFixed<T>::TwoStackFixed( int size, int maxtop ){
    if( maxtop > size ){
        cout << "Error: Partition of stacks can't be larger than array allocated"
        << endl;
    } // This would create an error ( seg fault maybe? )
    
    arr = new T[ size ];    // Step 1
    arrSize = size; // Step 2
    partition = maxtop; // Step 3
    // Step 4
    sizeStack1 = 0;
    sizeStack2 = 0;
}
// Step 1: Allocated memory to the array
// Step 2: Take the max size of an array
// Step 3: Take the max partition size of a stack
// Step 4: Initialize stack sizes

template<class T>
void TwoStackFixed<T>::pushStack1( T value ){
    if( sizeStack1 + sizeStack2 + 1 >  arrSize){
        cout << "Error: No room in array to push" << endl;
        return;
    }
    if( isFullStack1() ){
        cout << "Error: Stack has already hit partition cannot push" << endl;
        return;
    }
    ++sizeStack1;
    arr[sizeStack1 - 1] = value;
    display();
}
// When we can't push: 1) When the new size is bigger than the array
// 2) When we've already hit our partition limit on either stack
// If we can push, as we push whatever is already in the stack stays and the new
// value is added to the end

template<class T>
void TwoStackFixed<T>::pushStack2( T value ){
    if( sizeStack1 + sizeStack2 + 1 >  arrSize){
        cout << "Error: No room in array to push" << endl;
        return;
    }
    if( isFullStack2() ){
        cout << "Error: Stack has already hit partition cannot push" << endl;
        return;
    }
    cout << "Index: " << arrSize - sizeStack2 - 1 << endl;
    arr[ arrSize - sizeStack2 - 1] = value;
    ++sizeStack2;
    display();
}
// Errors are the same as for pushStack1
// When we push we have to push from the end:
// The bottom of the stack is the end of the array
// We push the top of the stack

template<class T>
T TwoStackFixed<T>::popStack1(){
    if( sizeStack1 == 0){
        cout << "Cannot pop further" << endl;
        return static_cast<T>(NULL);
    }
    T result = arr[sizeStack1 - 1];
    arr[sizeStack1 - 1] = T();
    --sizeStack1;
    return result;
}
// Set the last element of stack1 to default;

template<class T>
T TwoStackFixed<T>::popStack2(){
    if( sizeStack2 == 0){
        cout << "Cannot pop further" << endl;
        return static_cast<T>(NULL);
    }
    T result = arrSize - sizeStack2;
    arr[ arrSize - sizeStack2 ] = T();
    --sizeStack2;
    return result;
}
// Set the last element of stack2 to default


template<class T>
bool TwoStackFixed<T>::isFullStack1(){
    if( (sizeStack1 == partition) ){
        return 1;
    }
    return 0;
}
// if the size of stack 1 is the same as partition then return true
// else return false

template<class T>
bool TwoStackFixed<T>::isFullStack2(){
    if( (sizeStack2 == arrSize - partition ) ){
        return 1;
    }
    return 0;
}
// if the size of stack 2 is the same as arrSize - partition then return true
// else return false

template<class T>
bool TwoStackFixed<T>::isEmptyStack1(){
    if( sizeStack1 == 0){
        return 1;
    }
    return 0;
}

template<class T>
bool TwoStackFixed<T>::isEmptyStack2(){
    if( sizeStack2 == 0){
        return 1;
    }
    return 0;
}


template<class T>
void TwoStackFixed<T>::display(){
    unsigned whiteSpace = arrSize - sizeStack1 - sizeStack2;    // Step 1
    
    if( sizeStack1 != 0){   // **
        for( int i = 0; i <= sizeStack1 - 1; ++i){   // Step 2
            cout << arr[i] << " ";
            // cout << "I'm here! " << endl;
        }
    }
    
    for( int i = 0; i < whiteSpace; ++i){       // Step 3
        cout << "  ";
    }
    
    if( sizeStack2 != 0){   // **
        for( int i = 0; i < sizeStack2; ++i ){
            cout << arr[arrSize - sizeStack2 + i] << " ";
        }
    }
    cout << endl;
}
// Step 1: Figure out how much whitespace we're going to need
// Step 2: Output for all of the first stack
// Step 3: Output white spaces where neither stacks occupy
// Step 4: Output the second stack
// **: If either stack is empty skip their output loops



// List of written things
// List of tested things
/// Constructor
/// push stack 1
/// push stack 2
/// display
/// isFullStack1
/// isFullStack2
/// isEmptyStack1
/// isEmptyStack2

template<class T>
class TwoStackOptimal{
    private:
        
    public:
    // Declarations here and definitions further below
    unsigned sizeStack1;
    unsigned sizeStack2;
    unsigned arrSize;
    T* arr;
    
    TwoStackOptimal( int size );
    // Constructor that creates an array of size size
    
    void pushFlexStack1( T value );
    void pushFlexStack2( T value );
    
    T popFlexStack1();
    T popFlexStack2();
    
    bool isFullStack1();
    bool isFullStack2();
    
    bool isEmptyStack1();
    bool isEmptyStack2();
    
    void display();
};

template<class T>
TwoStackOptimal<T>::TwoStackOptimal( int size ){
    arr = new T[size];
    sizeStack1 = 0;
    sizeStack2 = 0;
    arrSize = size;
}
// Constructs an object with array size size
// Stacks initialized to size zero

template<class T>
void TwoStackOptimal<T>::pushFlexStack1( T value ){
    if( sizeStack1 + sizeStack2 == arrSize ){
        cout << "Error: No space for adding to a stack" << endl;
        return;
    }
    arr[sizeStack1] = value;
    ++sizeStack1;
    display();
}
// Checks if adding a value would be valid
/// NOT VALID when adding size of both stacks is greater than size of array
// If valid add values starting from the top down

template<class T>
void TwoStackOptimal<T>::pushFlexStack2( T value ){
    if( sizeStack1 + sizeStack2 == arrSize ){
        cout << "Error: No space for adding to a stack" << endl;
        return;
    }
    arr[ arrSize - sizeStack2 - 1] =  value;
    ++sizeStack2;
    display();
}
// Checks if adding a value would be valid
/// NOT VALID when adding size of both stacks is greater than size of array
// If valid add values starting from the bottom of the array and move up


template<class T>
T TwoStackOptimal<T>::popFlexStack1(){
    if(sizeStack1 == 0){
        cout << "Error: Cannot pop empty stack" << endl;
        return static_cast<T>(NULL);
    }
    T result = sizeStack1 - 1;
    arr[sizeStack1 - 1] = T();
    --sizeStack1;
    return result;
}
// Invalid when sizeStack1 is 0
// Set the last value of stack1 to default
template<class T>
T TwoStackOptimal<T>::popFlexStack2(){
    if(sizeStack2 == 0){
        cout << "Error: Cannot pop empty stack" << endl;
        return static_cast<T>(NULL);
    }
    T result = arrSize - 1 - sizeStack2;
    arr[ arrSize - 1 - sizeStack2 ] = T();
    --sizeStack2;
    return result;
}
// Invalid when sizeStack2 is zero
// Set the earliest occurring element of stack2 to default


template<class T>
bool TwoStackOptimal<T>::isFullStack1(){
    if(sizeStack1+sizeStack2 == arrSize){
        return 1;
    }
    return 0;
}

template<class T>
bool TwoStackOptimal<T>::isFullStack2(){
    if(sizeStack1+sizeStack2 == arrSize){
        return 1;
    }
    return 0;
}
template<class T>
bool TwoStackOptimal<T>::isEmptyStack1(){
    if(sizeStack1 == 0){
        return 1;
    }
    return 0;
}

template<class T>
bool TwoStackOptimal<T>::isEmptyStack2(){
    if(sizeStack2 == 0){
        return 1;
    }
    return 0;
}

template<class T>
void TwoStackOptimal<T>::display(){
    unsigned whitespace = arrSize - sizeStack1 - sizeStack2;    // Step 1

    if(sizeStack1 != 0){

        for(int i = 0; i <= sizeStack1 - 1; ++i){    // Step 2
            cout << arr[i] << " ";
        }
    }
    for(int i = 0; i < whitespace; ++i){    // Step 3
        cout << "  ";
    }
    if(sizeStack2 != 0){
        for(int i = 0; i <= sizeStack2 - 1; ++i){    // Step 4
            cout << arr[ arrSize - sizeStack2 + i] << " ";
        }
    }
    cout << endl;
}
// Step 1: Calculate how much whitespace we need
// Step 2: Loop for all of the first stack
// Step 3: Loop for the whitespace
// Step 4: Loop for the last stack

template <typename T>
void showTowerStates2(int n, stack<T> &A, stack<T> &B, stack <T>&C,
char source = ' ', char spare = ' ', char dest = ' '){
    if( n > 0 ){ // As long as it isnt the base case continue
        showTowerStates2( n - 1, A, C, B, source, dest, spare );
        cout << "Moved " << A.top() << " from peg " << source << " to " << dest << endl;    // The output
        C.push( A.top() ); A.pop();     // Move our disk to destination and pop
        showTowerStates2( n - 1, B, A, C, spare, source, dest );
    }
}
// The actual recurssion part

template <typename T>
void showTowerStates1( int n, stack<T> &A, stack<T> &B, stack <T>&C ){
    showTowerStates2( n, A, B, C, 'A', 'B', 'C' );
}
// Head of the recurssive function