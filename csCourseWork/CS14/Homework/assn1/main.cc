#include <iostream>
#include "MyList.h"
#include <string>

using namespace std;

void test1(); void test2();
void test3(); void test4();
void test5(); void test6();
void test7(); void test8();
void test9(); void test10();
void test11(); void test13();
void test14(); void test15();
void test16(); void test17();
void test18(); void test12();
void test19(); void test20();
void test22(); void test23();
void test24(); void test25();
void test26(); void test27();
void test28(); void test22();
void test29(); void test30();
void test21();

int main(){
    
    // test1(); test2();
    // test3(); test4();
    // test5(); test6();
    // test7(); test8();
    // test9(); test10();
    // test11(); test12();
    // test13(); test14();
    // test15();test16();
    // test17(); //test18();
    // test19(); test20();
    // test21(); test22();
    // test25(); test26();
    
    return 0;
}

void test1(){
    cout << "Test 1: MyList default constructor / push_back / display"
    << endl;
    MyList aa;
    
    aa.push_back( 'a' ); aa.push_back( 'b' );
    aa.push_back( 'c' ); aa.push_back( 'd' );
    aa.push_back( 'e' ); aa.push_back( 'f' );
    aa.push_back( 'g' ); aa.push_back( 'h' );
    aa.push_back( 'i' ); aa.push_back( 'j' );
    aa.push_back( 'k' ); aa.push_back( 'l' );
    
    aa.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test2(){
    cout << "Test 2: MyList const str constructor / push_back / display"
    << endl;
    
    MyList bb( "literal" );
    
    bb.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test3(){
    cout << "Test 3: MyList const str constructor / push_back / display"
    << " / empty string" << endl;
    
    MyList cc;
    
    cc.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test4(){
    cout << "Test 4: MyList string var constructor / push_back / display"
    << endl;
    string str = "Hello World";
    
    MyList dd( str );
    
    dd.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test5(){
    cout << "Test 5: MyList MyList constructor / push_back / display"
    << endl;
    MyList ee1("Hello World");
    MyList ee2( ee1 );
    
    cout << "ee1: ";
    ee1.print(); cout << endl;
    cout << "ee2: ";
    ee2.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test6(){
    cout << "Test 6: MyList default constructor / push_front(empty) / display"
    << endl;
    MyList ff;
    ff.push_front( 'a' );
    
    ff.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test7(){
    cout << "Test 7: MyList default constructor / "
    << "push_front(notEmpty) / display" << endl;

    MyList gg;
    gg.push_front( 'l' ); gg.push_front( 'k' );
    gg.push_front( 'j' ); gg.push_front( 'i' );
    gg.push_front( 'h' ); gg.push_front( 'g' );
    gg.push_front( 'f' ); gg.push_front( 'e' );
    gg.push_front( 'd' ); gg.push_front( 'c' );
    gg.push_front( 'b' ); gg.push_front( 'a' );
    
    gg.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test8(){
    cout << "Test 8: MyList default constructor / pop_front(empty)" << endl;

    MyList hh;
    hh.pop_front();
    
    hh.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test9(){
    cout << "Test 9: MyList default constructor / pop_front(1)" << endl;

    MyList ii("Hello World");
    ii.pop_front();
    
    ii.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test10(){
    cout << "Test 10: MyList default constructor / pop_front(4)" << endl;

    MyList jj("Hello World");
    jj.pop_front();
    jj.pop_front();
    jj.pop_front();
    jj.pop_front();
    
    
    jj.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test11(){
    cout << "Test 11: MyList default constructor / pop_front(too many)" << endl;

    MyList kk("Hello World");
    kk.pop_front(); kk.pop_front();
    kk.pop_front(); kk.pop_front();
    kk.pop_front(); kk.pop_front();
    kk.pop_front(); kk.pop_front();
    kk.pop_front(); kk.pop_front();
    kk.pop_front();
    kk.pop_front();
    
    
    kk.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test12(){
    cout << "Test 12: MyList default constructor / pop_back(empty)" << endl;

    MyList hh;
    hh.pop_back();
    
    hh.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test13(){
    cout << "Test 13: MyList default constructor / pop_back(1)" << endl;

    MyList ii("Hello World");
    ii.pop_back();
    
    ii.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test14(){
    cout << "Test 14: MyList default constructor / pop_back(4)" << endl;

    MyList jj("Hello World");
    jj.pop_back();
    jj.pop_back();
    jj.pop_back();
    jj.pop_back();
    
    
    jj.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test15(){
    cout << "Test 15: MyList default constructor / pop_back(too many)" << endl;

    MyList kk("Hello World");
    kk.pop_back(); kk.pop_back();
    kk.pop_back(); kk.pop_back();
    kk.pop_back(); kk.pop_back();
    kk.pop_back(); kk.pop_back();
    kk.pop_back(); kk.pop_back();
    kk.pop_back();
    kk.pop_back();
    
    
    kk.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test16(){
    cout << "Test 16: MyList default constructor / size(empty)"<< endl;

    MyList hh;
    
    hh.print(); cout << endl;
    cout << hh.size() << endl;
    cout << "==================================================" << endl;
}

void test17(){
    cout << "Test 17: MyList default constructor / size(something) "<< endl;

    MyList ii("Hello World");
    
    ii.print(); cout << endl;
    cout << ii.size() << endl;
    cout << "==================================================" << endl;
}


void test19(){
    cout << "Test 19: MyList literal constructor/ swap(list) "<< endl;

    MyList ii("Hello World");
    
    ii.print(); cout << endl;
    ii.swap(0, 5);
    ii.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test20(){
    cout << "Test 20: MyList default constructor/ swap(empty) "<< endl;

    MyList ii;
    
    ii.print(); cout << endl;
    ii.swap(0, 5);
    ii.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test21(){
    cout << "Test 21: MyList literal constructor/ insert(not empty) "<< endl;

    MyList ii("Hello World");
    
    ii.print(); cout << endl;
    ii.insert_at_pos(6,'Z');
    ii.print(); cout << endl;
    cout << "==================================================" << endl;
}

void test22(){
    cout << "Test 22: MyList default constructor/ insert(not empty) "<< endl;

    MyList ii;
    
    ii.print(); cout << endl;
    ii.insert_at_pos(6,'Z');
    ii.print(); cout << endl;
    cout << "==================================================" << endl;
}


void test25(){
    cout << "Test 25: MyList literal constructor/ [] operator "<< endl;

    MyList ii("Hello World");
    
    cout << ii[0] << endl;
    cout << "==================================================" << endl;
}

void test26(){
    cout << "Test 26: MyList literal constructor/ [] operator(empty) "<< endl;

    MyList ii;
    
    cout << ii[0] << endl;
    cout << "==================================================" << endl;
}
