//=================================================
// Name: <Tran, Kevin>
// Username: ktran050
//
// SID: 861172609
// Assignment Name: Assignment 6
// Lab Section: 23
// Approach: Declaration goes here.
//=================================================
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void bucketsort ( vector<unsigned>& vctr2Bsrtd, int loadfactor = 20 ){
    if( vctr2Bsrtd.size() == 0 ){ return; }
    int numBuckets = (vctr2Bsrtd.size() - 1) / loadfactor;
    numBuckets += 1; // holds the number of buckets we'll need
    
    // create a vector to put buckets in
    vector< list <unsigned> > bigDaddy;

    
    unsigned max_input = 0; // find max input
    for(unsigned i = 0; i < vctr2Bsrtd.size(); ++i){
        if( max_input<vctr2Bsrtd.at(i) ){ max_input = vctr2Bsrtd.at(i); }
    }
    
    // populate the vector with buckets( lists per the instructors' requests )
    for(int i = 0; i < numBuckets; ++i ){
        bigDaddy.push_back( list<unsigned>() );
    }
    // cout << "bigDaddy.size(): " << bigDaddy.size() << endl;
    
    // populate the buckets
    for(int i = 0; i < vctr2Bsrtd.size(); ++i){
        // bucket index = min(N-1,(N*i)/max_input)
        bigDaddy.at( min(numBuckets-1,static_cast<int>((numBuckets*vctr2Bsrtd.at(i))/max_input ))).push_back( vctr2Bsrtd.at(i) );
    }
    
    // sort the buckets
    for(int i = 0; i < bigDaddy.size(); ++i ){
        bigDaddy.at(i).sort();
    }
    
    // clear vector
    vctr2Bsrtd.clear();
    
    // put them back into the vector
    for(int i = 0; i < bigDaddy.size(); ++i ){
        while( !bigDaddy.at(i).empty() ){
            vctr2Bsrtd.push_back( bigDaddy.at(i).front() );
            bigDaddy.at(i).pop_front();
        }
    }
}
// sort vctr2Bsrtd with bucket sort