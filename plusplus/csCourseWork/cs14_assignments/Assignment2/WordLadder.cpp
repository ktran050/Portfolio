#include "includes.h"
#include "WordLadder.h"
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

WordLadder::WordLadder( const string listFile ){
    string fileInput;
    ifstream inFS;
    inFS.open( listFile.c_str() );
    
    if( !inFS.is_open() ){
        cout << "Error: File name incorrect or not found." << endl;
        exit(-1);
    }
    
    while(inFS >> fileInput){
        Dictionary.push_back( fileInput );
    }
    inFS.close();
}
// Create an input file stream
// Open the file *make sure you convert string to cstring*
// While we take input pushback the input into our dictionary list
// Close the file stream

void WordLadder::outputLadder( string start, string end ){
    if(start == end){ return; }
    
    stack<string> ofStrings;
    ofStrings.push( start );
    
    queue<stack<string> > ofStacks;
    ofStacks.push( ofStrings );
    
    while( !ofStacks.empty() ){
        for(list<string>::iterator it = Dictionary.begin(), itEnd = Dictionary.end(); it != itEnd; ++it){
            if( compareString( *it, ofStacks.front().top()) ){
                if(*it == end){
                    cout << "it: " << *it << endl;
                    ofStacks.front().push(*it);
                    while( !ofStacks.front().empty() ){
                        cout << ofStacks.front().top() << " ";
                        ofStacks.front().pop();
                    }
                    return;
                }
                // cout << "it: " << *it << endl;
                stack<string> copyOfStrings = ofStacks.front();
                copyOfStrings.push( *it );
                ofStacks.push( copyOfStrings );
                Dictionary.erase(it);
                it--;
            }
        }
        ofStacks.pop();
    }

    cout << "There is no word ladder from \"" << start << "\" to \"" << end
    << "\".\n" << endl;
    return;
}
// Take the starting word and ending word
// Take out all the words not involved in this word ladder
// Output the word ladder
// If there is no word ladder cout the special message

bool WordLadder::compareString(string a, string b ){
    // unsigned numCharDiffAB = 0;
    // for(int i = 0; i < 5; ++i){
    //     if( a.at(i) != b.at(i) ){
    //         ++numCharDiffAB;
    //     }
    // }
    // if( numCharDiffAB == 1 ){
    //     return 1;
    // }
    // else if( numCharDiffAB == 0 ){
    //     return 1;
    // }
    // else{
    //     return 0;
    // }
    int diffcount = 0;
    for(int i = 0; i < 5; ++i){
        if( a[i] != b[i] ){
            ++diffcount;
        }
    }
    return diffcount == 1;
}