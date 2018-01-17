// URL: http://www.dreamincode.net/forums/topic/78802-martyr2s-mega-project-ideas-list/
// Date/Time:   6/30/2016 12:25PM
// Objective: Count the number of vowels in a user-given string
// Modified Objective: The program now counts exactly how many of each vowel is seen
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void vCount(); void vCount(string useFile);

int main(){
  int uChoice;
  string useFile;

  cout << "To input from file enter: 1 \nElse enter: 2\n";
  cin >> uChoice;

  switch(uChoice){
    case 1:  cout << "Please input the file name (including .txt extension) \n";
      cin >> useFile;
      vCount(useFile); break;
    case 2:
      vCount(); break;
    default:  cout << "Invalid option\n";
      break;
  };
}

void vCount(){
    string userString;
    unsigned vowelCount,aCount,eCount,iCount,oCount,uCount;
    vowelCount = aCount = eCount = iCount  = oCount = uCount = 0;

    // Prompt users for a string
    cout<<"Please input a string: ";
    cin>>userString;
    
    // Count the number of total vowels and how many of each
    for(int i=0; i<userString.size(); ++i){
        switch(userString.at(i)){
          case 'a':
	    vowelCount++;
	    aCount++;
	    break;
          case 'e':
	    vowelCount++;
	    eCount++;
	    break;
          case 'i':
	    vowelCount++;
	    iCount++;
	    break;
          case 'o':
	    vowelCount++;
	    oCount++;
	    break;
          case 'u':
	    vowelCount++;
	    uCount++;
	    break;
          case 'A':
	    vowelCount++;
	    aCount++;
	    break;
          case 'E':
	    vowelCount++;
	    eCount++;
	    break;
          case 'I':
	    vowelCount++;
	    iCount++;
	    break;
          case 'O':
	    vowelCount++;
	    oCount++;
	    break;
          case 'U':
            vowelCount++;
            uCount++;
            break;
      };
  }
  cout<<"Number of vowels: "<<vowelCount<<endl;
  cout<<"Number of A occurences: "<<aCount<<endl;
  cout<<"Number of E occurences: "<<eCount<<endl;
  cout<<"Number of I occurences: "<<iCount<<endl;
  cout<<"Number of O occurences: "<<oCount<<endl;
  cout<<"Number of U occurences: "<<uCount<<endl;
  return;
}

void vCount(string useFile){
  string userString;
  fstream txtFile;

  unsigned vowelCount,aCount,eCount,iCount,oCount,uCount;
  vowelCount = aCount = eCount = iCount  = oCount = uCount = 0;

  txtFile.open(const_cast<char*>(useFile.c_str()));
  if( !(txtFile.is_open()) ){
    cout << "File failed to open. \n";
    return;
  }

  while(getline(txtFile, userString)){  
  // Count the number of total vowels and how many of each
  for(int i=0; i<userString.size(); ++i){
      switch(userString.at(i)){
        case 'a':
	  vowelCount++;
	  aCount++;
	  break;
        case 'e':
	  vowelCount++;
	  eCount++;
	  break;
        case 'i':
	  vowelCount++;
	  iCount++;
	  break;
        case 'o':
	  vowelCount++;
	  oCount++;
	  break;
        case 'u':
	  vowelCount++;
	  uCount++;
	  break;
        case 'A':
	  vowelCount++;
	  aCount++;
	  break;
        case 'E':
	  vowelCount++;
	  eCount++;
	  break;
        case 'I':
	  vowelCount++;
	  iCount++;
	  break;
        case 'O':
	  vowelCount++;
	  oCount++;
	  break;
        case 'U':
	  vowelCount++;
	  uCount++;
	  break;
      };
  }
  }

  txtFile.close();
  if(txtFile.is_open()){
    cout << "ERROR: txtFile still open \n";
    return;
  }

  cout<<"Number of vowels: "<<vowelCount<<endl;
  cout<<"Number of A occurences: "<<aCount<<endl;
  cout<<"Number of E occurences: "<<eCount<<endl;
  cout<<"Number of I occurences: "<<iCount<<endl;
  cout<<"Number of O occurences: "<<oCount<<endl;
  cout<<"Number of U occurences: "<<uCount<<endl;
  return;
}
