// Name: Kevin Tran
// SID: 861172609
// Date: 4/13/2013
// Approach: 
///
#ifndef __ExampleList__
#define __ExampleList__

#include <iostream>
#include <list>
#include <string>
#include "Lab1List.h"
using namespace std;

Lab1List::Lab1List(){
    head = 0;
    tail = 0;
    // cout << "Lab1List constructor ran!" << endl;
}
// Default constructor

Lab1List::Lab1List( const string& str ){
    for(int q = 0; q < str.size(); ++q){
        push( str.at(q) );
    }
}
// Make a singly-linked list from a passed in string typed object
/// Each character goes into a separate node
//// Take the string
//// Take offthe beginning piece
//// Create a node with that data value
//// Add that node to the list of nodes (using push)

Lab1List::~Lab1List(){
    if( head == 0){
        return;
    }
    while( head != 0){
        pop_front();
    }
    cout << "Deconstructor ran!" << endl;
}
// Deconstructor
//// If the next node = 0 stop


void Lab1List::push( char val ){
    if( head == 0){
        Node *toAdd = new Node(val);
        head = toAdd;
        tail = 0;
        return;
    }
    else{
        Node *toAdd = new Node(val);
        tail->next = toAdd;
        tail = toAdd;
        return;
    }
}
// inserts 'val' to the end of the list

void Lab1List::display() const{
    if( head == 0){
        return;
    }
    else{
        for(Node *temp = head; temp != 0; temp = temp->next){
            cout << temp->retChar();
            if(temp->next != 0){
                cout << " ";
            }
        }
    }
}
// prints the contents of list

void Lab1List::rotate(int k)
{
    Node *pre;
    Node *hold;
    for (int q = 0; q < k; ++q){
        pre = head;
        while(pre->next != tail){
            pre = pre->next;
        }
        pre->next = 0;
        hold = head;
        tail->next = hold;
        head = tail;
        tail = pre;
    }
    return;
}
// Rotates the liked list counter-clockwise by k positions

void Lab1List::pop_front(){
    Node* temp = head;
    head = head->next;
    delete temp;
}
// Destroys the front-most node


Lab1List& Lab1List::operator+( Lab1List& head2 ){
    if ( (head == 0) || (head2.head == 0) ){
        // Only continue if both lists have data
        head->ip = (head->ip + head2.head->ip);
        Node *firstTrans = head->next;
        Node *secTrans = head2.head->next;
        // Add values in head and move to the next node
        while (firstTrans != 0 || secTrans != 0){
            // Continue if there is still data left in the lists
            if (firstTrans != 0 && secTrans != 0){
                // if both lists have data
                firstTrans->ip = (firstTrans->ip + secTrans->ip);
                firstTrans = firstTrans->next;
                secTrans = secTrans->next;
                // add the values and move on with the traversal
            }
            else if(firstTrans == 0 && secTrans != 0){
                // if the first list runs out of data but the second still has
                /// a node
                push(secTrans->ip);
                firstTrans = firstTrans->next;
                secTrans = secTrans->next;
                // copy over this new data
            }
            else{
                return *this;
            }
        }
        return *this;
    }
    else if(head != 0 && head2.head == 0){
        // if the first list has nodes but the second doesn't
        /// return the first list
        return *this;
    }
    else if(head == 0 && head2.head != 0){
        // if the second list has data but the first doesn't
        push(head2.head->ip);
        Node *secTrans = head2.head->next;
        while (secTrans != 0){
            push(secTrans->ip);
            secTrans = secTrans->next;
        }
        return *this;
        // copy values over
    }
    else{
        return *this;
    }
}
// Add the rotated linked list and returns it. This receives a new
/// rotated linked list object. Output may be weird.


Node::Node( char data ){
    ip = data;
    next = 0;
}

void Node::display(){
        cout << "Node value: " << ip << endl;
}

char Node::retChar(){
    return ip;
}

#endif