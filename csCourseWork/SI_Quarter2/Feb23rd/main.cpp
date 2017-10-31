#include <iostream>
using namespace std;

void test1();
void test2();

int main(){
    
    test1();
    test2();
    int *c = new int;
    *c = 0;
    c = new int;
    *c = 88;
    delete c;
    
    return 0;
}

void test1(){
    // int *q = NULL;
    // cout << *q;
}

void test2(){
}