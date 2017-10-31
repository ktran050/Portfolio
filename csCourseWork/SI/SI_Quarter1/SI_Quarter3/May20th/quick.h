#include <utility>
#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>

/*
 * takes three values and uses comp to put them in sorted order.
 * the median ends up at b.
 */
template<typename T, typename Compare = std::less<T> >
void median_of_three(T & a, T & b, T & c, Compare comp = Compare()){
    if( comp(b,a) ){ std::swap(b,a); }
    if( comp(c,a) ){ std::swap(c,a); }
    if( comp(c,b) ){ std::swap(c,b); }
}

/*
 * partitions v from first to last using mid as the pivot
 */
template<typename T, typename Compare = std::less<T>>
int partition(std::vector<T> & v, int first, int mid, int last, Compare comp = Compare());

/*
 * same as other partition;
 * creates two vectors for the left and right, then puts all the elements (except for mid)
 * in the two. Then, they are put back in v so that v is partitioned, and returns the
 * index of the pivot value.
 */
template<typename T, typename Compare = std::less<T>>
int naive_partition(std::vector<T> & v, int first, int mid, int last, Compare comp = Compare()){
    // create two vectors
    std::vector<T> lessThan;
    std::vector<T> moreThan;
    
    // populate the vectors
    for(int i = first; i < last + 1; ++i ){
        if( comp(v.at(i), v.at(mid) ) ){ lessThan.push_back( v.at(i) ); }
        else if( comp( v.at(mid),v.at(i) )){ moreThan.push_back(v.at(i)); }
    }
    lessThan.push_back( v.at(mid) );
    
    // put em back
    int c = first;
    for(int i = 0; i < lessThan.size(); ++i ){
        v.at(i + c) = lessThan.at(i);
    }
    for(int i = 0; i < moreThan.size(); ++i ){
        v.at(c + lessThan.size()-1 ) = moreThan.at(i);
    }
    return lessThan.size()-1;
}

/*
 * uses the median of three pivot selection method, and the naive partition method
 * to implement quicksort
 *
 * has a base case of a list of size 1 or fewer
 */
template<typename T, typename Compare = std::less<T>>
void naive_quicksort(std::vector<T> & v, int first, int last, Compare comp = Compare()){
    if( v.size()<1 || v.size()==0 ){
        return;
    }
}

/*
 * overload
 */
template<typename T>
void naive_quicksort(std::vector<T> & v) {
    naive_quicksort(v, 0, v.size());
}

/*
 * uses the median of three pivot selection method, and the faster partition method
 *
 * has a base case of a list of size 1 or fewer
 */
template<typename T, typename Compare = std::less<T>>
void quicksort(std::vector<T> & v, int first, int last, Compare comp = Compare());

/*
 * overload
 */
template<typename T>
void quicksort(std::vector<T> & v) {
    quicksort(v, 0, v.size());
}

/*
 * InsertionSort
 */
template<typename T, typename Compare = std::less<T>>
void insertionsort(std::vector<T> & v, int first, int last, Compare comp = Compare()) {
    for(int sorted = first + 1; sorted < last; ++sorted) {
        for(int i = sorted; i > first && comp(v.at(i), v.at(i-1)); --i) {
            std::swap(v.at(i), v.at(i-1));
        }
    }
}

/*
 * overload
 */
template<typename T>
void insertionsort(std::vector<T> & v) {
    insertionsort(v, 0, v.size());
}

/*
 * uses the median of three pivot selection method and the faster partition method
 *
 * insertion sort is called for reasonably small lists
 */
template<typename T, typename Compare = std::less<T>>
void faster_quicksort(std::vector<T> & v, int first, int last, Compare comp = Compare());

/*
 * overload
 */
template<typename T>
void faster_quicksort(std::vector<T> & v) {
    faster_quicksort(v, 0, v.size());
}