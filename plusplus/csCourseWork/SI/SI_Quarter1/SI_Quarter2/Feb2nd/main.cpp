#include <iostream>
#include "Integer.h"
#include <cmath>

using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    return 0;
}

// void test1(){
//     cout << "Test 1: i + k. i = 1, b = 2" << endl;
//     Integer a(1); Integer b(2);
//     Integer q = a + b;
//     cout << q.display() << endl;
//     cout << "---------------------" << endl;
// }
// void test2(){
//     cout << "Test 2: i - k. i = 2, b = 1" << endl;
//     Integer a(2); Integer b(1);
//     Integer q = a - b;
//     cout << q.display() << endl;
//     cout << "---------------------" << endl;
// }
// void test3(){
//     cout << "Test 3: i + 2. i = 1" << endl;
//     Integer a(1);
//     Integer q = a + 2;
//     cout << q.display() << endl;
//     cout << "---------------------" << endl;
// }
void test4(){
    cout << "Test 4: i * b. i = 8, b = 8" << endl;
    Integer a(8); Integer b(8);
    Integer q = a * b;
    cout << q.display() << endl;
    cout << "---------------------" << endl;
}
void test5(){
    cout << "Test 5: i / 8. i = 8.0" << endl;
    Integer a(8);
    Integer q = a / 2.5;
    cout << q.display() << endl;
    cout << "---------------------" << endl;
}
void test6(){
    
}