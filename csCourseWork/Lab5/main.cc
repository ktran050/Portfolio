//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Lab 5
// Lab Section: 23
// Approach: Use code from Assigment 3 to add new functions findSumPath,minCover
// and vertSum. This will be done by calling the functions and the functions calling
// their helper functions usually on root first and traversing the tree if need be.
// Helper function functions either overload the name or are very similar to their head
// functions in name. These functions will have extra parameters compared to their 
// head functions.
//=================================================
#include <iostream> 
#include "lab5.h"
using namespace std; 

int main()
{
	cout << "Testcase Uno" << endl; 
	BST<int> a; 
	a.insert(50); 
	a.insert(20); 
	a.insert(60); 
	a.insert(10); 
	a.insert(40); 
	a.insert(35); 
	a.insert(45); 
	a.insert(70); 

	cout << "Part 1" << endl; 
	a.minCover(); 
	a.displayMinCover(); cout << endl;
	
	cout << "Part 2" << endl; 
	int buffer[1000]; 
	a.findSumPath(80, buffer); 
	
	cout << "Part 3" << endl;
	map<int, int> m; 
	a.vertSum(m);
	
	
	
	return 0; 
}