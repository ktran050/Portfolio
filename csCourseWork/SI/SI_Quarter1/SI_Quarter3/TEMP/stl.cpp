// Calling functions using the operator()
// Creating a struct with string and int data members. Take info via user input and then be able to organize it based on the number
// *use of auto*
// *ranged based for loop*
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct StringInt{
    int data;
    string name;
    
    StringInt(string namee, int numbb){
        namee = data;
        data = numbb;
    }
};

int main(){
    const string EMPTY_STRING = ""; const int FALSE_INT = 0;
    string Sinput; int Ninput;
    list<StringInt> qq;
    
    do{
        cout << "Name?" << endl; getline(cin, Sinput);
        cout << "Number?" << endl; cin >> Ninput; cin.ignore();
        
        
        qq.push_back( StringInt(Sinput, Ninput) );
    }while( (Sinput != "") );
    
    return 0;
}