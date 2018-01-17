#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>


using namespace std;

double randFloat (double a, double b){
    return a + (static_cast<double>(rand())/ RAND_MAX) * (b-a);
}

void generate(int i){
    //declarations
    double theoMean, pracMean, theoDev, pracDev, min, max;
    double array[i];
    
    //request user for input
    cout << "Give me your min and max." << endl;
    cin >> min >> max;
    
    //populate the array
    for(int a = 0; a < i; ++a){
        array[a] = randFloat(min, max);
    }
    
    //theoretical mean
    theoMean = (min + max) / 2;
    
    //practical mean
    for(int a = 0; a < i; ++a){
        pracMean += array[a];
    }
    pracMean /= i;
    
    //theoretical deviation
    theoDev = pow((max - min), 2) / 12;
    
    //pracDev
    for(int a = 0; a < i; ++a){
        pracDev += pow((array[a] - theoMean), 2);
    }
    pracDev /= i;
    
    //test cout the answers
    // cout << "theoMean: " << theoMean << " pracMean: " << pracMean << endl;
    // cout << "theoDev: " << theoDev << " pracDev: " << pracDev << endl;
    
    // cout the answers
    cout << theoMean << " " << pracMean << " " << theoDev << " "
    << pracDev << endl;

}

int main(){
    srand(333);
    
    generate(1000);
    generate(100000);
    
    return 0;
}