#include <vector>
#include <iostream>
using namespace std;

class AdjacencyMatrix{
    private:
        int n;
        vector<vector<int> > adj;
        vector<bool> visited;
    public:
        // AdjacencyMatrix(int n) : adj( n,vector<int>(n) ){}
        
        ~AdjacencyMatrix(){
            while( !adj.empty() ){
                adj.pop_back();
            }
        }
        
        void add_edge(int origin, int destin, int weight){
            if( origin>=n || destin>=n){
                adj.resize( max(origin, destin), vector<int>() );
                for(int i = 0; i < max(origin, destin); ++i ){
                    adj.at(i).resize( max(origin, destin), 0 );
                }
                n = max(origin, destin);
            }
            adj.at(origin).at(destin) = weight;
        }
        
        void display(){
            // for(int i = 0; i < n; ++i){
            //     // if its the first row output 0 to n-1
            //     for(int s = 0; s < n; ++i){
            //         cout << "  "
            //     }
            // }
        }
        /* etc. */
};