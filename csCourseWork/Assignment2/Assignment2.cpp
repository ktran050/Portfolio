//=====================================Required algorithm:
/// Create a stack of strings
/// Push the start word onto the stack
/// Create a queue of stacks
/// Enqueue this stack
/// While this stack isn't empty    
//// For each word in the dictionary
///// If a word is exactly one letter different from the word on top
///// If this word == end word
////// You're done output the top word and the end word
///// Copy the front stack
///// Push the found word onto the stack
///// Enqueue the copy
//// End for loop
//// Dequeue front stack
//====================Implementation
/// Use queue and stack templates from STL
/// WordLadder( const string listFile )
//// Constructor that accepts the name of the dictionary file
/// void outputLadder( const string start, const string end )
//// Takes the start and end words and outputs the word ladder
//// Otherwise print this error cout << "There is no word ladder from \"
//// << start << "\" to \"" << end << "\".\n"; and end
//============================Notes
/// Read in the dictionary once and store it
/// Use a list data structor that we've been learning about
/// (vector, stack, list, queue)
/// We have to use list (why is this good?)
#include "includes.h"
#include <cstdlib>
#include "WordLadder.h"
using namespace std;

int main(int argc, char** argv){
    if( argc != 4 ){
        cout << "Usage: wordladder <dictionary_file> <start_word> <end_word>\n";
        exit(-1);
    }
    WordLadder wl( argv[1] );
    wl.outputLadder( argv[2], argv[3] );
}
