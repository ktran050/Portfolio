//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Assignment 7
// Lab Section: 23
// Approach: Write a function dfs.
//          Inputs: Adjacency matrix in the form of vector<vector<bool>>
//                  unsigned start defaulted to 0. (node to start at)
//          Returns: Spanning tree reachable from that start node
//          Notes:  It has to go in ascending order
//                  Try and use a static local variable to keep track of visted nodes
//                  When it's all done, clear the adjacency matrix
//=================================================
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs( vector<vector<bool> >& adjacency, unsigned start = 0 ){
    static int recursionDepth = 0; // only gets initialized once per run
    ++recursionDepth;       // incremented once per invocation
    bool sweetch = 0;
    
    // static list to hold all rows that have been visited
    static vector<pair<unsigned, unsigned> > visited;
    

    for(unsigned i = 0; i < adjacency.at(start).size(); ++i ){
        sweetch = false;
        if( adjacency.at(start).at(i) ){ // if theres an edge at start to 
        
            // add that value to our static vector
            // don't add the value to our list if any first in our vector matches the second
            for(unsigned c = 0; c < visited.size(); ++c){
                if(i == visited.at(c).first ){ sweetch = true; }
            }
            if( sweetch == false ){
                visited.push_back( pair<unsigned,unsigned>(start,i) );
            }
            
            adjacency.at(start).at(i) = false;
            dfs(adjacency, i); // go to that vertex and continue
        }
    }
    
    
    --recursionDepth;   // returns to value as of this invocation
    // populate our stuff at the end
    if( recursionDepth == 0 ){
        // clear the list
        
        for(unsigned i = 0; i < adjacency.size(); ++i){
            for(unsigned c = 0; c < adjacency.size(); ++c){
                adjacency.at(i).at(c) = false;
            }
        }
        // assert bools on values in our vector
        for(unsigned i = 0; i < visited.size(); ++i){
            adjacency.at( visited.at(i).first ).at( visited.at(i).second ) = true;
        }
    }
    if( recursionDepth == 0 ){  // This invocation was first so
        visited.clear(); // re-initialize visited before returning
    }
}