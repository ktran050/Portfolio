#ifndef __Message__
#define __Message__
#include <string>
#include <iostream>

using namespace std;

class Message{
    private:
        string author;
        string subject;
        string body;
    public:
        Message();
        //default constructor
        
        Message(const string& athr, const string& sbjct,
        const string& body);
        //Message object with parameters
        
        void display() const;
        //displays message in this format
        //Message #: TITLE
        //from USER: MESSAGE
        //endl;
};
#endif