#include <iostream>
#include <vector>
using namespace std;
int main(){int test, tempOne;
cin >> test;
vector <int> p;
do{tempOne=test%10;test=test/10;p.push_back(tempOne);}while(test!=0);
for(int i = 0; i < p.size();++i){cout<<p.at(i) << endl;}
return 0;}
// #include <iostream>
// #include <vector>
// using namespace std;
// void backwards(int &input, vector <int> &v){int tempOne, i = 0;
// do{tempOne=input%10;input=input/10;v.push_back(tempOne);++i;}while(input!=0);
// }int main(){int test = 1234;
//     vector <int> p;
//     backwards(test, p);
//     for(int i = 0; i < p.size();++i){cout<<p.at(i) << endl;}
// return 0;}