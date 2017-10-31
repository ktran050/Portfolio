//This program takes 2 command line inputs for text files that contain first
//and last names
//it removes 3 numers after the names
//generates a random name
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]){
    //declarations
    srand(time(NULL));
    vector<string> first; vector<string> last;
    string goIn;
    ifstream inFS;
    string firstFile = argv[1]; string secFile = argv[2];
    string firstName; string lastName;
    int temp;
    
    //Open file
    inFS.open(firstFile.c_str());
    if(!inFS.is_open()) {
        cout << "File couldn't be opened. " << endl;
        return 1;
    }
    
    //Populate a vector for all names
    while(inFS >> goIn){
        first.push_back(goIn);
        inFS >> goIn;
        inFS >> goIn;
        inFS >> goIn;
    }
    
    
    //Take a random name
    temp = first.size();
    firstName = first.at(rand() % temp);
    
    //Close file
    inFS.close();
    
    //Open file
    inFS.open(secFile.c_str());
    if(!inFS.is_open()) {
        cout << "File couldn't be opened. " << endl;
        return 1;
    }
    
    //Populate the vector with last names
    while(inFS >> goIn) {
        last.push_back(goIn);
        inFS >> goIn;
        inFS >> goIn;
        inFS >> goIn;
    }
    
    //Take a random name
    temp = last.size();
    lastName = last.at(rand() % temp);
    
    //Close file
    inFS.close();
    
    //output both names
    cout << "First name: " << firstName << " ";
    cout << endl;
    cout << "Last name: " << lastName << " ";
    cout << endl;
    
    return 0;
}

