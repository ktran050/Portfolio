#include <iostream>
#include "priority_queue.h"
using namespace std;

int main(){
    priority_queue<int> cc;
    int c = 3;
    cc.push(3, 4);
    cc.push(4, 5);
    cc.push(5, 6);
    cc.push(6, 7);
    cc.push(7, 8);
    cc.push(8, 9);
    cc.push(9, 10);
    cout << cc.front() << endl;
    cc.pop();
    cout << cc.front() << endl;
    cc.pop();
    cout << cc.front() << endl;
    cc.pop();
    cout << cc.front() << endl;
    cc.pop();
    cout << cc.front() << endl;
    cc.pop();
    cout << cc.front() << endl;
    cc.pop();
    cout << cc.front() << endl;cc.pop();
    cout << cc.front() << endl;
    
    return 0;
}