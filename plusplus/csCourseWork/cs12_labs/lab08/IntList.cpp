#include "IntList.h"
#include <iostream>
#include <vector>

using namespace std;


IntList::IntList(){
    head = 0;
    tail = 0;
}
IntList::~IntList(){
    while(head != 0){
        pop_front();
    }
}


void IntList::display() const{
    if(head == 0){
        return;
    }
    else{
        for(IntNode *temp = head; temp != 0; temp = temp->next){
            cout << temp->data;
            if(temp->next != 0){
                cout << " ";
            }
        }
    }
}
void IntList::push_front(int value){
    IntNode *temp = new IntNode(value);
    temp->next = head;
    if(head == 0){
        tail = temp;
    }
    head = temp;
}
void IntList::pop_front(){
    IntNode *temp = head;
    head = head->next;
    delete temp;
}

void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    if(head == 0){
        head = temp;
    }
    else{
        (*tail).next = temp;
    }
    tail = temp;
}

void select_sort(){
    // int tempLeast = 0;
    // IntNode *traverse = new IntNode(0);
    // *traverse = *head;
}