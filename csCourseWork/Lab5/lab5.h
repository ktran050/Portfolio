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
#ifndef BST_H
#define BST_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

#define nil 0
// #define Value int // restore for testing
template <typename Value>
class BST{
    
    class Node{     // Start binary tree node
    public:
    
        Node* left;     // Pointer to Node's child on the left
        Node* right;    // Pointer to Node's child on the right
        Value value;    // Value of the node
        bool switched = false;
        
        Node( const Value v = Value() ) : value(v), left(nil), right(nil){}
        // Constructor for a Node sets value to V and null left/right pointers
        Value& content(){return value;}
        // Helper function returning value of the node
        bool selected(){return switched;}
        // Helper functionn returning bool selected
        
        bool isInternal(){return left != nil && right != nil;}
        // Helper function returning true if the node isn't at the edges
        bool isExternal(){return left != nil || right != nil;}
        // Helper function returning true if neither of the node's children
        /// are leaves
        bool isLeaf(){return left == nil && right == nil;}
        // Helper function returning true if the node is a leaf
        
        int height(){
            Node* travel = *this;       // Step 1
            int heightVal = 0;          // Step 2
            ++heightVal;                // Step 3
            
            while( !isLeaf() ){   // Step 4
                if( travel->left != 0){
                    travel = travel->left;
                    ++heightVal;
                }
                else{
                    travel = travel->right;
                    ++heightVal;
                }
            }
            return heightVal;
        }
        // returns the height of the subtree rooted in this node
        // Step 1: Create a pointer to traverse the subtree
        // Step 2: Create a counter for height
        // Step 3: Increment the counter
        // Step 4: Start while loop
        // Step 5: After the pointer moves to a child, then increment
        int size(){
            Node* travel = this;   // Step 1
            if( isLeaf() ){
                return 1;   // Step 2
            }
            else{
                if( isInternal() ){ // Step 3
                    return 1 + travel->left->size() + travel->right->size();
                }
                else{   // Step 4
                    if( travel->left != nil ){
                        return 1 + travel->left->size();
                    }
                    else{
                        return travel->right->size() + 1;
                    }
                }
            }
        }
        // returns the size of the subtree rooted in this node
        // Step 1: Create a node to traverse the tree
        // Step 2: If the node has no children you're done (return 1)
        // Step 3: If it's internal return 1 + sizes of both its children
        // Step 4: If external return 1+ whichever child.size it can
    };              // END NODE
    
    // const Node* nil;    // later nil will point to a sentinel node
    Node* root;
    int count;
    
public:
    int size(){
        if( root != nil){
            return root->size();
        }
        return 0;
    }
    
    bool empty(){ return size() == 0;} // Return 1 if it is empty
    
    void print_node( const Node* n ){
        cout << n->content() << endl;
    }
    // Print this node's value
    
    bool search( Value x ){
        Node *travel = root;
        while(travel != nil){
            if(travel->value == x){ return 1; }
            else{
                if(x < travel->value){
                    travel = travel->left;
                }
                else{
                    travel = travel->right;
                }
            }
        }
        return 0;
    }
    // Return true if the value is found
    
    void preorder() const{
        preorderParam( root );
    }
    // Traverse and print the tree one Value per line in preorder
    void preorderParam( Node* LoR ) const{
        cout << LoR->content() << endl;
        if(LoR->left != nil){
            preorderParam( LoR->left );
        }
        if(LoR->right != nil){
            preorderParam( LoR->right );
        }
    }
    // The recurssive part of preorder
    
    void postorder() const{
        postorderParam( root );
    }
    // Traverse and print the tree on Value per line in post order
    
    void postorderParam( Node* LoR ) const{
        if(LoR->left != nil){
            postorderParam( LoR->left );
        }
        if(LoR->right != nil){
            postorderParam( LoR->right );
        }
        cout << LoR->content() << endl;
    }
    
    void inorder() const{
        inorderParam( root );
    }
    
    void inorderParam( Node* LoR ) const{
        if(LoR->left != nil){
            inorderParam( LoR->left );
        }
        cout << LoR->content() << endl;
        if(LoR->right != nil){
            inorderParam( LoR->right );
        }
    }
    // Traverse and print the tree one Value per line in order
    
	void brackOp(vector<Value> &cc, Node* current)
	{
		if(current == nil) return;
		// Traverses the left
		operatorHelper(cc, current->left);
		// Pushes into cc
		cc.push_back(current->content());
		// Traverses the right
		operatorHelper(cc, current->right); 
	}
	// Helper for []

	Value& operator[] (int num) {
	  	//returns reference to the value field of the n-th Node
	  	if(num >= size())
	  	{
	  		cout << "Out of bounds" << endl; 
	  		exit(-1); 
	  	}
	  	else if(num == 0)
	  	{
	  		return root->content(); 
	  	}
	  	vector<Value> cc; 
	  	operatorHelper(cc, root);
	  	return cc.at(num);
	}
	// Calls its helper function which populates its vector
	// then returns the value at the last member of the vector

    
    BST() : count(0), root(nil){}
    
    void insert( Value X ){ root = insert( X, root); }
    Node* insert( Value X, Node* T ){
        // The normal binary-tree insertion procedure
        if( T == nil ){
            T = new Node( X );  // The only place where T gets updated
        }
        else if( X < T->value ){
            T->left = insert( X, T-> left );
        }
        else if( X > T->value ){
            T->right = insert( X, T->right );
        }
        else{
            T->value = X;
        }
        // Later, rebalancing code will be written here
        return T;
    }
    
    void minCover(Node* LoR ){
        if( LoR->isLeaf() ){ return; }// Leaves are never part of the min cover
        else if( LoR->isInternal() ){ // invalid/special cases accounted for
            minCover( LoR->left );    // Call for left
            minCover( LoR->right );   // Call for right
            
            if( (!LoR->left->selected())||(!LoR->right->selected()) ){ // then true
                LoR->switched = true;
            }
        }
        else if( LoR->isExternal() ){// externals have to be handled differently
            if( LoR->left == nil ){// if lefts empty go right
                minCover( LoR->right );
                if( !LoR->right->selected() ){ LoR->switched = true; }
            }
            else if( LoR->right == nil ){// if rights empty go left
                minCover( LoR->left );
                if( !LoR->left->selected() ){LoR->switched = true; }
            }
        }
    }
    void minCover(){
        minCover(root);
    }
    
    void displayMinCover() const{
        queue<Value> spoils;
        displayHamburgerHelper( root, spoils );
        while( !spoils.empty() ){
            cout << spoils.front() << " ";
            spoils.pop();
        }
    }
    
    void displayHamburgerHelper( Node* LoR, queue<Value>& cc ) const{
        if(LoR->left != nil){
            displayHamburgerHelper( LoR->left, cc );
        }
        if( LoR->selected() ){
            cc.push( LoR->content() );
        }
        if(LoR->right != nil){
            displayHamburgerHelper( LoR->right, cc );
        }
    }
    
    void findSumPath( Node* nptr, int sum, int buffer[], int& counter,int& county ){
        if( !nptr->isLeaf()&&sum==0  ){counter  = 0;return;}
        else if( sum == 0){return;}
        if(sum - nptr->content() <= nptr->content() && nptr->left != nil){
            findSumPath( nptr->left, sum - nptr->content(), buffer, ++counter, county);
        }
        // cout << "county " << county << endl;
        // cout << "counter " << counter << endl;
        // cout << "buffer[county]" << buffer[county] << endl;
        // cout << "nptr->content()" << nptr->content() << endl;
        buffer[county] = nptr->content();
        ++county;
        if(sum - nptr->content() >= nptr->content() && nptr->right != nil){
            findSumPath( nptr->right, sum - nptr->content(), buffer, ++counter, county);
        }
    }
    
    void FSPdisp(int buffer[], int counter){
        if(counter == 0){cout << "0 " << endl; return;}
        for(int i = 0; i < counter + 1; ++i){cout << buffer[i] << " ";}
        cout << endl;
    }
    
    void findSumPath(int sum, int buffer[]){
        int counter = 0;
        int county = 0;
        findSumPath(root, sum, buffer, counter,county);
        FSPdisp(buffer, counter);
    }
    
	void vertSum(Node* node, int hd, std::map<int, int>& m)
	{
		if(node == nil)
		{
			return; 
		}
		vertSum(node->left, hd - 1, m); // traverses left
		m[hd] += node->value;   // adds it
		vertSum(node->right, hd + 1, m); // traverses right
	}

	// Calls helper
	void vertSum(std::map<int, int>& m)
	{

		vertSum(root, 0, m);
		for(map<int, int>::iterator i = m.begin(); i != m.end(); i++)
		{
			cout << i->second << " "; 
		} // Displays our result
		cout << endl; 
	}
    
    void okay() { okay(root); }
    void okay( Node* T ){
        // Diagnostic code can be installed here
        return;
    }
    
    // void LOL(){
    //     cout << root->content() << endl;
    // }
};   // End BST
#endif