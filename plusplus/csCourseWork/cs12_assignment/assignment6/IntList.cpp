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

void IntList::select_sort(){

}

void IntList::insert_sorted(int value){
    if(head != 0){
        bool sweetch = 0;
        
        
        
        for(IntNode *trans = head; trans != 0; trans = trans->next){
            if(trans->data > value){
                    // cout << "I WENT HERE TOO1" << endl;
                    IntNode *PNN = new IntNode(value);
                    PNN->next = head;
                    sweetch = 1;
                    head = PNN;
                    // cout << "I WENT HERE TOO1" << endl;
                    return;
            }
            if(trans->next != 0){
                // cout << "I WENT HERE" << endl;
                if(trans->next->data > value){
                    // cout << "I WENT HERE TOO" << endl;
                    IntNode *PNN = new IntNode(value);
                    PNN->next = trans->next;
                    trans->next = PNN;
                    sweetch = 1;
                    return;
                }
            }
        }
        
        if(sweetch == 0){
            for(IntNode *trans = head; trans != 0; trans = trans->next){
                if(trans->next == 0){
                    IntNode *PNN = new IntNode(value);
                    PNN->next = 0;
                    trans->next=PNN;
                    tail = PNN;
                    return;
                }
            }
        }
    }
    else{
        push_back(value);
    }
}

void IntList::remove_duplicates(){

}