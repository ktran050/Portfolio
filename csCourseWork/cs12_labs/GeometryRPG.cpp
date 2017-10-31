#include <iostream>
#include <string>
#include <fstream>
#include <vector>



int main()
{	
	

	std::ifstream ipList;
	std::string rawInput;
	std::string::iterator end = rawInput.end();
	std::string temp;
	std::vector<std::string> list;

	ipList.open("raw.txt");
	// Open file
	
	if(!ipList.is_open() ){
		std::cout << "ERROR: File not opened" << std::endl;
		return 0;
	}
	// Output error if file can't open
	
	while( getline(ipList, rawInput) ){
	// as long as there is input grab a line and put it in rawInput
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		std::cout << rawInput << std::endl;
		for(std::string::iterator it =  rawInput.begin(); it != end; ++it){
		// travel through the rawInput
			
			if( (*it == '[') && ( it+1 != end ) && (*it+1 != ']') ){
			// RED FLAG: does *(it++) evaluate at it++ or increment it then evaluate
			// if the char we're currently on is [ and the line continues on and the next character
			/// isn't ]
			
				it++;
				for(std::string::iterator ot = it; ot != end; ++ot){
					if(*ot != ']' ){
						temp += *ot;
					}
					else{
						list.push_back(temp);
						std::cout << temp << std::endl;
						it = ot+1;
						ot = end;
					}
				}
				// Add chars to temp until ]
				// if ] then push the temp word into the vector
			}
		}
	}
	
	
	ipList.close();
	// Make sure file is closed
	
	for(int i = 0; i < list.size()-1; i++){
		std::cout << list[i] << std::endl;
	}
	// output the vector

	return 0;
}
// receive raw input from a text file
// parse the text
// spit out IPs in the same file
