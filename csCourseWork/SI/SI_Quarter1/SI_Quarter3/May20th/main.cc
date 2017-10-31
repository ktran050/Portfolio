#include <assert.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <chrono>

#include "quick.h"

// Typedefs for convenience

// Function object of void functions that take in a reference to an int vector
typedef std::function<void(std::vector<int>&)> IntSortFn; 

/* 
 * Function pointer of void functions that take in a reference to an int vector
 * Used once because function objects fail during overload resolution.
 * See: http://stackoverflow.com/a/29811240/4654998
 */
typedef void(*IntSortFnPtr)(std::vector<int> &);


// Seperate functions into their own namespaces

// helper functions for correctness/speed tests 
namespace test_helper {
    // C++11 way of getting random ints
    int get_random_int() {
        const int lower = -50;
        const int upper = 50;
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(lower, upper);

        return dis(gen);
    }
}

//functions for testing if a sort is correct
namespace sort_test {
    bool corner_case(IntSortFn sort_fn) {
        std::vector<int> vec;
        sort_fn(vec);
        vec.push_back(1);
        sort_fn(vec);
        return vec.size() == 1 && vec.front() == 1;
    }

    bool ascending(IntSortFn sort_fn) {
       std::vector<int> vec {1, 2, 3, 4, 5};
       std::vector<int> sorted {1, 2, 3, 4, 5};
       sort_fn(vec);
       return std::equal(vec.begin(), vec.end(), sorted.begin()); 
    }

    bool descending(IntSortFn sort_fn) {
        std::vector<int> vec {5, 4, 3, 2, 1};
        std::vector<int> sorted {1, 2, 3, 4, 5};
        sort_fn(vec);
        return std::equal(vec.begin(), vec.end(), sorted.begin()); 
    }
    
    bool random(IntSortFn sort_fn) {
        const unsigned size = 10000;
        std::vector<int> vec(size);

        // generate and insert random ints into vec
        std::generate_n(vec.begin(), size, test_helper::get_random_int);
        
        // copy vec into sorted
        std::vector<int> sorted(vec);
        sort_fn(vec);

        // use STL sort to sort the copy of vec
        std::sort(sorted.begin(), sorted.end());
        
        /* 
         * A correct sort should have the same result as std::sort.
         * std::is_sorted is not enough because sort_fn can mess
         * up in a way that such that sort_fn can leave a vector
         * in sorted order, but accidently duplicate or delete
         * elements from the original input.
         * 
         * e.g. if input is {4, 3, 1, 2}, then the vector
         * with elements {1, 1, 1} is sorted, but doesn't sort
         * the vector correctly.
        */
         return std::equal(vec.begin(), vec.end(), sorted.begin()); 
    }
}


// functions used to time each sort
namespace speed_test {
   /*
    * returns the time it takes to run a single sort with sort_fn on
    * a vector of test_size random ints
   */
   std::chrono::duration<double> time_sort(IntSortFn sort_fn, 
           unsigned int test_size) {
        
        std::vector<int> vec(test_size);
        std::generate_n(vec.begin(), test_size, test_helper::get_random_int);
     
        // C++11 way of getting the exact system time
        auto start = std::chrono::system_clock::now();
        sort_fn(vec); 
        auto end = std::chrono::system_clock::now();
        return end - start;
   }

   /* 
    * returns the time it takes to sort num_sorts number of
    * vectors, each with test_size number of random ints
    */
   std::chrono::duration<double> time_sorts(IntSortFn sort_fn, 
           unsigned int test_size, unsigned int num_sorts) {
       std::chrono::duration<double> total_time;
       for(unsigned i = 0; i < num_sorts; ++i) {
            total_time += time_sort(sort_fn, test_size);
       }
       return total_time;
   }
}


int main() {
    /* 
     * The sorts we will be using to test correctness and
     * also time along with a sort description/name of each sort
     *
     * Comment out sorts that you have yet to implement.
     */
    std::vector<std::pair<IntSortFnPtr, std::string>> sort_functions {
        //{insertionsort, "Insertion Sort"},
        {naive_quicksort, "Naive QuickSort"},
        {quicksort, "QuickSort"},
        {faster_quicksort, "Faster QuickSort"},
        {[](std::vector<int> & v){std::sort(v.begin(), v.end());}, "std::sort"},
    };
     /* 
      * The tests to be run on each sort to show that it works correctly.
      * 
      * Represented as a pair of function objects and a string - a function
      * along with a short description of the test.
     */
    std::vector<std::pair<std::function<bool(IntSortFn)>, std::string>> correctness_tests {
        {sort_test::corner_case, "Corner-case"},
        {sort_test::ascending, "In ascending order"},
        {sort_test::descending, "In descending order"},
        {sort_test::random, "Random set of integers"},
    };  
    
    // Run all of the tests for each sort function to show it behaves correctly
    std::cout << "Starting correctness tests ..." << std::endl;
    for (const auto & sort_with_description : sort_functions) {  
        auto sort_fn = sort_with_description.first;
        std::string sort_description = sort_with_description.second;
        std::cout << "Starting " << sort_description << " tests"
            << "\n---------------" << std::endl;

        for (const auto & test_with_description: correctness_tests) {
            auto run_test = test_with_description.first;
            std::string test_description = test_with_description.second;
            std::cout << "Running test: " <<  test_description << std::endl; 
            
            // if the test returns false, stop running all of the tests!
            assert(run_test(sort_fn));
            std::cout << "Passed test!\n" << std::endl;
        }
        std::cout << "Finished all correctness tests for " << sort_description << "!"
            << "\n---------------" << std::endl;
    }

    std::cout << "Finished all correctness tests!" << std::endl;

    
    const unsigned int NUMBER_ITEMS_PER_TEST = 10000;
    const unsigned int NUMBER_TESTS = 100;

    std::cout << "\n////////////////////////////////////////\n"
        << "Starting Speed tests ... \n"  
        << "Number of items per test: " << NUMBER_ITEMS_PER_TEST << '\n'
        << "Number of tests per sort: " << NUMBER_TESTS << '\n' << std::endl;

    // run speedtests on each sort
    for (const auto & sort_with_description : sort_functions) {
        auto sort_fn = sort_with_description.first;
        std::string sort_description = sort_with_description.second;

        /* 
         * time_it has the time it takes to sort a NUMBER_TEST
         * vectors with NUMBER_ITEMS_PER_TEST random ints
        */
        double time_it = speed_test::time_sorts(sort_fn, NUMBER_ITEMS_PER_TEST, NUMBER_TESTS).count();
        std:: cout << sort_description << ": " << time_it << std::endl;
    } 
    return 0;
}