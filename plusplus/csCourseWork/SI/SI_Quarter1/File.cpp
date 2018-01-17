#include <iostream>
using namespace std;

int main ()
{
  
    
    //Pi is 3.14159
    double area, volume, circumfrence, r, pi = 3.14159;
    
    cout << "What is the radius?" << endl;
    
    
    cin >> r;
    area = r * r * pi;
    circumfrence = 2 * pi * r;
    volume = (4.0/3.0) * pi * r * r * r;
    
    
    
    cout << "Your area is " << area << "." << endl;
    cout << "Your circumfrence is " << circumfrence << "." << endl;
    cout << "Your volume is " << volume << "." << endl;
    
    return 0;
}