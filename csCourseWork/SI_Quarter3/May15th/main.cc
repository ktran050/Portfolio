#include "heap.h"
#include <assert.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <queue>
#include <random>
using namespace std;

// C++11 way of getting random ints
int get_random_int() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(-50, 50);

    return dis(gen);
}


// Only corner case should be size of 1 push and pop
bool corner_test() {
    MinHeap<int> h;
    
    // 1 element
    h.push(1);
    int h_top_before_pop = h.top();

    h.pop();
    // return h_top_before_pop == 1 && h.empty();
}

bool ascending_test() {
   MinHeap<int> h;

   for(int elem : {1, 2, 3, 4, 5}) {
        h.push(elem);
   }
   return h.top() == 1;
}

bool descending_test() {
    MinHeap<int> h;

    for(int elem : {5, 4, 3, 2, 1}) {
        h.push(elem);
    }
    return h.top() == 1;
}


/* use std::greater comparator
 * instead of the default std::less
 * to determine the "min" priority.
 *
 * Becomes a "max" heap, top should
 * return the greatest element.
 */
bool max_test() {
    MinHeap<int, std::greater<int>> h;

    for(int elem : {1, 2, 3, 4, 5}) {
        h.push(elem);
    }
    return h.top() == 5;
}

bool random_test() {
    MinHeap<int> h;
    std::vector<int> v;

    int rand_int = 0;
    int smallest_elem = 0;
    std::vector<int>::iterator smallest_elem_itr;

    for(unsigned int i = 0; i < 100; ++i) {
        rand_int = get_random_int();
        h.push(rand_int);
        v.push_back(rand_int);
       
        /* returns an iterator to the smallest element in
         * in the vector
         */
        smallest_elem_itr = std::min_element(v.begin(), v.end());
        smallest_elem = *smallest_elem_itr;

        /* If smallest_elem and the pq don't agree,
         * then the test fails
         */
        if(h.top() != smallest_elem) {
            return false;
        }
    }

    return true;
}



bool heap_sort_test() {
    MinHeap<int> h;
    std::vector<int> v;
    
    for(unsigned int i = 0; i < 100; ++i) {
        int rand_int = get_random_int();
        h.push(rand_int);
    }

    while(!h.empty()) {
        v.push_back(h.top());
        h.pop();
    }

    /* Popping elements from a MinHeap into a
     * vector should result in the vectors
     * elements being in sorted order
     */

    return std::is_sorted(v.begin(), v.end());
}

bool std_pq_test() {
    MinHeap<int> h;
    
    std::priority_queue<int, std::vector<int>, 
        std::greater<int>> pq;

    int action_flip = 0;
    int random_int = 0;
    for(int i = 0; i < 100; ++i) {
        /* per iterator, do a random action -
         * if the "action flip" is even, add
         * the same random element to the std::priority_queue
         * and to our min-heap, otherwise it the flip
         * is odd and both heaps are non-empty, pop
         */
        action_flip = get_random_int();
        if(action_flip % 2 == 0) {
            random_int = get_random_int();
            h.push(random_int);
            pq.push(random_int);
        } else if (!h.empty() && !pq.empty()) {
            h.pop();
            pq.pop();
        }

        /* At each step, both the std::priority_queue and
         * the min-heap must agree on what the smallest
         * element is
         */
        if(!h.empty() && !pq.empty() &&
                h.top() != pq.top()) {
            return false;
        }
    }
    return true;
}

bool heap_sort_heapify_test() {
    std::vector<int> v;
    
    for(unsigned int i = 0; i < 100; ++i) {
        v.push_back(get_random_int());
    }

    MinHeap<int> h;

    // batch heapify with elements from v
    h.heapify(v);

    // Need to reuse v, so clear elements in it
    v.clear();

    while(!h.empty()) {
        v.push_back(h.top());
        h.pop();
    }

    return std::is_sorted(v.begin(), v.end());
}

int main() {
    /* A collection of pairs of function pointers of tests
     * and messages. The test functions return true 
     * if the test passed, false if it failed
     */
    std::vector<std::pair<bool (*)(), std::string>> tests {
        {corner_test, "Corner-case test"},
        // {ascending_test, "In ascending order test"},
        // {descending_test, "In descending order test"},
        // {max_test, "Use as a max-heap test"},
        // {random_test, "Random set of integers test"},
        // {heap_sort_test, "Heap sort random set of integers test"},
        // {std_pq_test, "Random Push/Pop actions test vs std::priority_queue"},
        // {heap_sort_heapify_test, "Heap sort with O(n) heapify test"},
    };

    // Run all of the tests
    for (const auto & test_message_pair : tests) {
        auto run_test = test_message_pair.first;
        std::string test_message = test_message_pair.second;
        std::cout << "Running: " <<  test_message << std::endl; 
        assert(run_test());
        std::cout << "Passed test!" 
            << std::endl << std::endl;
    }

    std::cout << "Finished all tests!" << std::endl;

    return 0;
}