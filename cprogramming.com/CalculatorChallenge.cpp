// URL: http://www.cprogramming.com/complete/calc.html
// Date/Time:   6/29/2016 5:01 PM
#include <iostream>
using namespace std;

int multiply(int x, int y){
    return x*y;
}

double divide(int x, int y){
    return x/y;
}

int add(int x, int y){
    return x+y;
}

int subtract(int x, int y){
    return x-y;
}

int main(){
    char op='c';
    int x, y;
    while(op!='e'){
        cout<<"What operation would you like to perform: add(+), subract(-),"
        << " divide(/), multiply(*), [e]xit?";
        cin>>op;
        switch(op){
            case '+':
            cin>>x;
            cin>>y;
            cout<<x<<"+"<<y<<"="<<add(x,y)<<endl;
            break;
            
            case '-':
            cin>>x;
            cin>>y;
            cout<<x<<"-"<<y<<"="<<subtract(x,y)<<endl;
            
            case '/':
            cin>>x;
            cin>>y;
            cout<<x<<"/"<<y<<"="<<divide(x,y)<<endl;
            break;
            
            case '*':
            cin>>x;
            cin>>y;
            cout<<x<<"*"<<y<<"="<<multiply(x,y)<<endl;
            break;
            
            case 'e':
            cin>>x;
            cin>>y;
            cout<<"Sorry, try again"<<endl;
        }
    }
    return 0;
}