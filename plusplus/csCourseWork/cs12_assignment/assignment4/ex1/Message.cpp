#include "Message.h"
#include <string>
#include <iostream>

using namespace std;

Message::Message(){
    author = "blank";
    subject = "blank";
    body = "blank";
}

Message::Message(const string &athr, const string &sbjct, const string &body){
    author = athr;
    subject = sbjct;
    this->body = body;
}

void Message::display() const{
    cout << subject << endl;
    cout << "from: " << author << body << endl;
    cout << endl;
}