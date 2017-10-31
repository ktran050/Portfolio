#include <iostream>
#include <list>

using namespace std;


// Write a function mergeList() to merge linked lists 1 and 2
/// A resulting list should be created that alternates nodes between 1 and 2
/// Be sure to include an extra element at the end of this new list
/// List 1{ 12, 3, 56, 5} List 2{ 45, 66, 2}
/// Output: 12 45 3 66 56 2 5
// typedef int T;
// typedef string T;
template < typename T>
list<T> mergeList( list<T> list1, list<T> list2 ){
    list <T> resultList;
    unsigned smallForLoopSize; unsigned bigForLoopSize;
    
    if( list1.size() >  list2.size() ){
        bigForLoopSize = list1.size();
        smallForLoopSize = list2.size();
    }
    else{
        bigForLoopSize = list2.size();
        smallForLoopSize = list1.size();
    }
    // find how many times the for loop needs to iterate
    
    for(int qq = 0; qq < smallForLoopSize; ++qq){
        resultList.push_back( list1.front() );
        list1.pop_front();
        
        resultList.push_back( list2.front() );
        list2.pop_front();
    }
    // Add values of both lists starting with list 1 up until one of them
    /// runs out of numbers
    for(int qq = smallForLoopSize; qq < bigForLoopSize; ++qq){
        if( list1.size() > list2.size() ){
            resultList.push_back( list1.front() );
        }
        if( list1.size() < list2.size() ){
            resultList.push_back( list2.front() );
        }
    }
    // Whichever list is left has its values added
    
    resultList.push_back( T() );
    // Add a space
    
    return resultList;
    // end the program
}
// Write a function called mergeSortList
/// Merge a pre-sorted list into another list
/// The resulting list should be sorted
/// EX. List 1{ 3, 5, 12, 56} List2{ 2, 45, 66}
/// Result: {2 3 5 12 45 56 66}
// Algorithm
/// 1) Check values at IT1 and IT2
/// 2) Add the value that is lesser to resultList
/// 3) Increment the IT that had a lesser value
/// 4) Do that while both IT aren't at the end
/// 5) Continue with whichever IT isn't at end
template < typename T>
list<T> mergeSortList( list<T> &listA, list<T> &listB){
    list<T> resultList;
    typename list<T>::iterator itListA = listA.begin();
    typename list<T>::iterator itListB = listB.begin();

    /// 5) Continue with whichever IT isn't at end
    while( (itListA != listA.end())||(itListB != listB.end()) ){
        /// 1) Check values at IT1 and IT2
        /// 2) Add the value that is lesser to resultList
        /// 3) Increment the IT that had a lesser value
        if(*itListA > *itListB){
            resultList.push_back( *itListB );
            itListB++;
            listB.pop_front();
        }
        else{
            resultList.push_back( *itListA );
            itListA++;
            listA.pop_front();
        }
    }
    /// 5) Continue with whichever IT isn't at end
    if( itListA == listA.end() ){
        while( itListB != listB.end() ){
            resultList.push_back( *itListB );
            listB.pop_front();
            itListB++;
        }
    }
    if( itListB == listB.end() ){
        while( itListA != listA.end() ){
            resultList.push_back( *itListA );
            listA.pop_front();
            itListA++;
        }
    }
    
    // Add a blank after
    resultList.push_back( T() );
    
    // list<T>::iterator bIterator;
    // for(bIterator = resultList.begin(); bIterator != resultList.end(); bIterator++ ){
    //     cout << *bIterator << endl;
    // }
    
    return resultList;
    // Return the new sorted list
}
template < typename T>
void addListA( list<T> &listA );

template < typename T>
void addListB( list<T> &listB );

template < typename T>
void addListD( list<T> &listD );

template < typename T>
void addListE( list<T> &listE );


int main(){
    // Declarations for part A
    list<T> listA; list<T> listB; list<T> listC;
    addListA ( listA );
    addListB ( listB );
    listC = mergeList( listA, listB );
    
    // Output to test part A
    typename list<T>::iterator aIterator;
    for(aIterator = listC.begin(); aIterator != listC.end(); aIterator++ ){
        cout << *aIterator << " ";
    }
    cout << endl;
    
    // Declarations for part B
    list<T> listD; list<T> listE; list<T> listF;
    addListD ( listD );
    addListE ( listE );
    listF = mergeSortList( listD, listE );
    
    // Output to test part B
    typename list<T>::iterator bIterator = listF.begin();
    for(bIterator = listF.begin(); bIterator != listF.end(); bIterator++ ){
        cout << *bIterator << " ";
    }
    cout << endl;
    
    return 0;
}

void addListA( list<T> &listA ){
    // listA.push_back(12);
    // listA.push_back(3);
    // listA.push_back(56);
    // listA.push_back(5);
    listA.push_back("12");
    listA.push_back("3");
    listA.push_back("56");
    listA.push_back("5");
    return;
}
// Function to populate A

void addListB( list<T> &listB){
    listB.push_back("45");
    listB.push_back("66");
    listB.push_back("2");
    // listB.push_back(45);
    // listB.push_back(66);
    // listB.push_back(2);
    return;
}
// Function to populate B

void addListD( list<T> &listD ){
    listD.push_back("3");
    listD.push_back("5");
    listD.push_back("12");
    listD.push_back("56");
    // listD.push_back(3);
    // listD.push_back(5);
    // listD.push_back(12);
    // listD.push_back(56);
    return;
}
// Function to populate D

void addListE( list<T> &listE ){
    listE.push_back("2");
    listE.push_back("45");
    listE.push_back("66");
    // listE.push_back(2);
    // listE.push_back(45);
    // listE.push_back(66);
    return;
}
// Function to populate E