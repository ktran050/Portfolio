//====================HEADER===================
//
// Name: Kevin Tran
// SID: 861172609
// Date: 4/26/2015
// Approach: main.cc holds all of the testing and test cases
//
//====================HEADER===================
# include "lab3.h"
# include <stack>
using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5part1();
void test5part2();
void test6();
void test7();
void test8();
void test9();
void test10();

int main(){
    

    
    // test1();
    // test2();
    // test3();
    // test4();
    // test5part1();
    // test5part2();
    // test6();
    // test7();
    // test8();
    // test9();
    test10();
    
    return 0;
}

void test1(){
    cout << "======================Test 1====================" << endl;
    cout << "Array display (empty stacks)" << endl;
    cout << "Array size: 8" << endl; cout << "Stack partition: 6" << endl;
    
    TwoStackFixed<int> cc( 8, 6 );
    cout << "arrSize: " << cc.arrSize << endl;
    cout << "Display: "; cc.display(); cout << endl;
}

void test2(){
    cout << "======================Test 2====================" << endl;
    cout << "Array display (empty array, empty stacks)" << endl;
    cout << "Array size: 0" << endl; cout << "Stack partition: 0" << endl;
    
    TwoStackFixed<int> cc( 0, 0 );
    cout << "Display: "; cc.display(); cout << endl;
}

void test3(){
    cout << "======================Test 3====================" << endl;
    cout << "Array display (invalid partition)" << endl;
    cout << "Array size: 4" << endl; cout << "Stack partition: 8" << endl;
    
    TwoStackFixed<int> cc( 4, 8 );
    cout << "Display: "; cc.display(); cout << endl;
}

void test4(){
    cout << "======================Test 4====================" << endl;
    cout << "Array member elements test" << endl << endl;
    
    cout << "Empty array, no partition" << endl;
    TwoStackFixed<int> cc( 0, 0);
    cout << "sizeStack1: " << cc.sizeStack1 << endl;
    cout << "sizeStack2: " << cc.sizeStack2 << endl;
    cout << "partition: " << cc.partition << endl;
    cout << "arrSize: " << cc.arrSize << endl;
    cout << endl;
    
    cout << "Array size 8, no partition" << endl;
    TwoStackFixed<int> dd( 8, 0);
    cout << "sizeStack1: " << dd.sizeStack1 << endl;
    cout << "sizeStack2: " << dd.sizeStack2 << endl;
    cout << "partition: " << dd.partition << endl;
    cout << "arrSize: " << dd.arrSize << endl;
    cout << endl;
}

void test5part1(){
    cout << "======================Test 5====================" << endl;
    cout << "Push test" << endl << endl;
    
    TwoStackFixed<int> cc ( 8, 6 );
    
    cout << "Before pushes: " << endl;
    cout << "sizeStack1: " << cc.sizeStack1 << endl;
    cout << "sizeStack2: " << cc.sizeStack2 << endl;
    cout << "partition: " << cc.partition << endl;
    cout << "arrSize: " << cc.arrSize << endl;
    cc.display(); cout << endl;
    
    cc.pushStack1( 1 );
    cc.pushStack2( 8 );
    
    cout << "After pushes to stack1 and stack2: " << endl;
    cout << "sizeStack1: " << cc.sizeStack1 << endl;
    cout << "sizeStack2: " << cc.sizeStack2 << endl;
    cout << "partition: " << cc.partition << endl;
    cout << "arrSize: " << cc.arrSize << endl;
    cc.display(); cout << endl;
    
    cout << endl;
    cout << "After pushes up to the partition(on stack1): " << endl;
    cc.pushStack1( 2 );
    cc.pushStack1( 3 );
    cc.pushStack1( 4 );
    cc.pushStack1( 5 );
    cc.pushStack1( 6 );
    cc.display(); cout << endl;
    
    cout << "One more push" << endl;
    cc.pushStack1( 7 );
}

void test5part2(){
    cout << "New TwoStackFixed, ARR size 8 partition size 3" << endl;
    TwoStackFixed<int> cc ( 8, 3 );
    
    cout << endl;
    cc.pushStack1( 3 );
    cc.pushStack1( 2 );
    cc.pushStack1( 1 );
    cout << "After pushes to stack1 and stack2: " << endl;
    cout << "sizeStack1: " << cc.sizeStack1 << endl;
    cout << "sizeStack2: " << cc.sizeStack2 << endl;
    cout << "partition: " << cc.partition << endl;
    cout << "arrSize: " << cc.arrSize << endl;
    cc.display(); cout << endl;
    
    cout << endl;
    cc.pushStack2( 8 );
    cc.pushStack2( 7 );
    cc.pushStack2( 6 );
    cc.pushStack2( 5 );
    cc.pushStack2( 4 );
    cout << "Pushing up to the partition(on stack2): " << endl;
    cout << "sizeStack1: " << cc.sizeStack1 << endl;
    cout << "sizeStack2: " << cc.sizeStack2 << endl;
    cout << "partition: " << cc.partition << endl;
    cout << "arrSize: " << cc.arrSize << endl;
    cc.display(); cout << endl;
    
    cout << endl;
    cout << "One more push on stack2" << endl;
    cc.pushStack2( 4 );
    cc.display(); cout << endl;
}

void test6(){
    cout << "======================Test 6====================" << endl;
    TwoStackFixed<int> cc( 10, 3 );
    cc.pushStack1(1);
    cc.pushStack1(2);
    cc.pushStack1(3);
    cc.display(); cout << endl;
    
    cc.pushStack2(4);
    cc.pushStack2(5);
    // cc.pushStack2(6);
    // cc.pushStack2(7);
    // cc.pushStack2(8);
    // cc.pushStack2(9);
    // cc.pushStack2(10);
    cc.display(); cout << endl;
    
    // cc.popStack1();
    // cc.popStack1();
    // cc.popStack1();
    // cc.display(); cout << endl;
    
    // cc.popStack2();
    // cc.popStack2();
    // cc.popStack2();
    // cc.display(); cout << endl;
    
}

void test7(){
    cout << "======================Test 7====================" << endl;
    TwoStackFixed<int> cc( 10, 3 );
    cc.pushStack1(1);
    cc.pushStack1(2);
    cc.pushStack1(3);
    cc.display(); cout << endl;
    
    cc.pushStack2(4);
    cc.pushStack2(5);
    cc.pushStack2(6);
    cc.pushStack2(7);
    cc.pushStack2(8);
    cc.pushStack2(9);
    cc.pushStack2(10);
    cc.display(); cout << endl;
    
    cc.popStack1();
    cc.popStack1();
    // cc.popStack1();
    cc.display(); cout << endl;
    
    cc.popStack2();
    cc.popStack2();
    cc.popStack2();
    cc.popStack2();
    cc.popStack2();
    cc.popStack2();
    cc.popStack2();
    cc.popStack2();
    cc.display(); cout << endl;
    
}

void test8(){
    cout << "======================Test 8====================" << endl;
    TwoStackOptimal<char> ab( 10 );
    ab.display(); cout << endl;
    char a = 'a';
    char b = 'b';
    char c = 'c';
    char d = 'd';
    char e = 'e';
    char f = 'f';
    char g = 'g';
    char h = 'h';
    char i = 'i';
    char j = 'j';
    ab.pushFlexStack1(a);
    ab.pushFlexStack1(b);
    ab.pushFlexStack1(c);
    ab.pushFlexStack1(d);
    ab.pushFlexStack1(e);
    ab.pushFlexStack1(f);
    ab.pushFlexStack1(g);
    ab.pushFlexStack1(h);
    ab.pushFlexStack1(i);
    ab.pushFlexStack2(j);
    
    // ab.pushFlexStack2(10);
    // ab.display(); cout << endl;
}

void test9(){
    
    stack<int> stack1;
    stack<int> stack2;
    stack<int> stack3;
    
    stack1.push(3);
    stack1.push(2);
    stack1.push(1);
    
    showTowerStates1( 3, stack1, stack2, stack3);
    
}

void test10(){
    
    stack<char> stack1;
    stack<char> stack2;
    stack<char> stack3;
    
    stack1.push('e');
    stack1.push('d');
    stack1.push('c');
    stack1.push('b');
    stack1.push('a');




    
    showTowerStates1( 5, stack1, stack2, stack3);
    
}