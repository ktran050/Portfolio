#ifndef __WordLadder__
#define __WordLadder__

#include "includes.h"
using namespace std;

class WordLadder{
    public:
        list<string> Dictionary;
        WordLadder( const string listFile );
        // Take in the string containing the file name
        void outputLadder( string start, string end );
        // Output the ladder (if there is a ladder)
        bool compareString( string a, string b);
        // Checks if the string is one letter different
        // Used in output ladder
    private:
        
};

#endif