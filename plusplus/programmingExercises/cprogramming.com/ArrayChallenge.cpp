// URL: http://www.cprogramming.com/complete/array.html
// Date/Time: 6/29/16 4:38 PM
#include <iostream>
using namespace std;

int main(){
    int array[8];
    for(int x=0; x<8; x++){
        cout<<"Please enter one digit"<<endl;
        cin>>array[x];
    }
    for(int x=0; x<8; x++)
    cout<<array[x];
    cout<<endl;
    return 0;
}