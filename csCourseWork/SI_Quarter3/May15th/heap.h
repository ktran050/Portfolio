// #include <vector>
// #include <algorithm>
// #include <functional>

// template<typename T, typename Less=std::less<T> >
// class MinHeap {
//     public:
//         // const T & top();
//         // void push(const T & elem);
//         // void pop();
//         bool empty();
//         // void heapify(const std::vector<T> & vec);
//     private:
//         std::vector<T> _heap;
//         Less _less;
// };

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;

template<typename T, typename Less=std::less<T> >
class MinHeap {
    public:
        const T & top(){
            if( _heap.size()<=1 ){ cout << "Empty heap" << endl; exit(-1);}
            return _heap.at(1);
        }
        // Gives the top element of the heap
        void push(const T & elem){
            if(_heap.size() == 0){ _heap.push_back(-9999999); }
            _heap.push_back(elem);
            int currPos = _heap.size() - 1;
            // if last element is smaller than parent then swap
            if(_heap.back() < _heap.at(_heap.size()/2) ){
                swap( _heap.back(), _heap.at(heap.size()/2) );
            }
        }
        void pop(){
            int currPos = 1;
            // swap front and back
            swap(_heap.at(1), _heap.at(_heap.size() - 1));
            // erase the back
            _heap.pop_back();
            if(_heap.size()==1){return;}
            // sort
            // if the first child is greater
            while( ( _heap.at(currPos)>_heap.at(2*currPos) ) || ( _heap.at(currPos)>_heap.at(2*currPos + 1) ) ){
                if( _heap.at(currPos)>_heap.at(2*currPos) ){
                    // swap positions
                    swap( _heap.at(currPos), _heap.at(2*currPos) );
                    // change our current position
                    currPos*=2;
                }
                // if the second child is greater
                else if( _heap.at(currPos)>_heap.at(2*currPos + 1) ){
                    // swap positions
                    swap( _heap.at(currPos), _heap.at(2*currPos + 1) );
                    // change our current position
                    currPos = (currPos*2) + 1;
                }
            }
        }
        bool empty(){
            if( _heap.empty() ){ return true; }
            return false;
        }
        // if empty return true, else return false
        void heapify(const std::vector<T> & vec){
            for(int i = 0; i < vec.size(); ++i ){
                push( vec.at(i) );
            }
        }
    private:
        std::vector<T> _heap;
        Less _less;
};
