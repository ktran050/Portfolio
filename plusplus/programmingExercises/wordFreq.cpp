// This program takes inputs from .txt files and will provide varying statistics
// Features implemented: most and least frequent words ranked
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void prompt(){
  cout << "To rank word frequency enter 1:\n";
  cout << "To exit enter 0:\n";
}

void wordFreq(ifstream &useFile){
}

int main(){
  string useText;
  int useChoice;
  ifstream useFile;
  
  // Prompt users for file
  cout << "Please input the file to be analyzed. Enter 0 to exit. \n";
  cin >> useText;

  // Based on response exit or open file
  if(useText == "0"){
    cout << "Goodbye \n";
    return 0;
  }
  else{
    useFile.open(const_cast<char*>(useText.c_str()) );
    if( !(useFile.is_open()) ){		// Throw an error if the file can't be opened
      cout << "ERROR: File could not be opened.\n";
      return 0;
    }
  }
  
  // Prompt the user for a choice of analysis
  prompt();
  cin >> useChoice;

  switch(useChoice){
    case 1:  wordFreq(useFile);
      break;
    case 0: cout << "Exiting.\n";
      break;
    default: cout << "ERROR: invalid choice\n";
      break;
  }

  return 0;
}
