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
        
        Node( const Value v = Value() ) : value(v), left(nil), right(nil){}
        // Constructor for a Node sets value to V and null left/right pointers
        Value& content(){return value;}
        // Helper function returning value of the node
        
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
    
    
    Value& operator[]( int n ){
        // if( n >= size() ){
        //     cout << "Error: Index is larger than tree" << endl;
        //     exit(-1);
        // }
        // return BrackParam(n, root)->value;
    }
    
    Node* BrackParam( int n, Node* LoR ){
        // if (LoR == nil)
        // {
        //     exit(-1);
        // }
        // if(LoR->left != nil){
        //     BrackParam( n, LoR->left );
        // }
        // if(n == 0){
        //     return LoR;
        // }
        // n--;
        // if(LoR->right != nil){
        //     BrackParam( n, LoR->right );
        // }
    }

    
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