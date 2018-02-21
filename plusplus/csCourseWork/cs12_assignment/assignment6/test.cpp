#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int> chcklst;
    int userNum;
    
    // cout << "Enter a number: " << endl;
    // cin >> userNum;
    // while(userNum != 999){
    //     chcklst.push_back(userNum);
    //     cout << "Enter a number: " << endl;
    //     cin >> userNum;
    // }
    chcklst.push_back(9);
    chcklst.push_back(7);
    chcklst.push_back(5);
    chcklst.push_back(2);
    chcklst.push_back(4);

    for(int q = 0; q < chcklst.size(); ++q){
        int min = chcklst.at(q);
        for(int c = q; c < chcklst.size(); ++c){
            if(chcklst.at(c) < min){
                swap(min, chcklst.at(c));
            }
        }
        chcklst.at(q) = min;
        cout << "This was min: " << chcklst.at(q) << endl;
    }
    
    
    cout << endl;
    cout << endl;
    for(int q = 0; q < chcklst.size(); ++q){
        cout << chcklst.at(q) << endl;
    }
    
    return 0;
}