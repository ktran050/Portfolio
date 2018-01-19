#include "bst.h"
using namespace std;

void testBasics(){
    cout << "===================== testBasics ========================" << endl;
    BST<int> best;
    best.insert( 8 );
    best.insert( 7 );
    best.insert( 6 );
    best.insert( 5 );
    cout << "====== Size ======" << endl;
    cout << "Size: " << best.size() << endl;
    
    cout << "====== Empty ======" << endl;
    if( best.empty() ){
        cout << "BST is empty " << endl;
    }
    else{
        cout << "BST has something " << endl;
    }
    
    cout << "====== Search ======" << endl;    
    if( best.search(69) ){
        cout << "I found it." << endl;
    }
    else{ cout << "Nope, not there. " << endl;}
}

void orderTest(){
    cout << "===================== orderTest ========================" << endl;
    BST<char> best;
    best.insert( 'F' );
    best.insert( 'B' );
    best.insert( 'G' );
    best.insert( 'A' );
    best.insert( 'D' );
    best.insert( 'C' );
    best.insert( 'E' );
    best.insert( 'I' );
    best.insert( 'H' );
    cout << "====== Pre Order ======" << endl;
    best.preorder();
    cout << "====== In Order ======" << endl;
    best.inorder();
    cout << "====== Post Order ======" << endl;
    best.postorder();
}

void testOperator(){
    // BST<char> best;
    // best.insert( 'F' );
    // best.insert( 'B' );
    // best.insert( 'G' );
    // best.insert( 'A' );
    // best.insert( 'D' );
    // best.insert( 'C' );
    // best.insert( 'E' );
    // best.insert( 'I' );
    // best.insert( 'H' );
    // cout << best[0] << endl;
    BST<int> best;
    best.insert( 8 );
    best.insert( 7 );
    best.insert( 6 );
    best.insert( 5 );
    cout << best[3] << endl;
}

int main(){
    testBasics();
    orderTest();
    testOperator();
    return 0;
}