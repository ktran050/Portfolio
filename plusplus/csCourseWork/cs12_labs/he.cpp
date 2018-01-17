#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
/*
// Purpose:
		This program takes all the IPs from a specified text file and saves it in
another specified text file. ** An IP being numbers or decimals between '[' and ']'
*/

void openInputFile(std::string filename, std::vector<std::string>& ipList){
	std::ifstream ifs;		// input file stream
	std::string rawInput;	// holds strings IPs are to be extracted from
	std::string temp;		// holds IPs as they're being built
	
	ifs.open( (filename+".txt").c_str() );		// open the file
	if( !ifs.is_open() ){						// check if it's open
		std::cout << "Error: File could not be accessed" << std::endl;
	}
	while( getline(ifs, rawInput) ){			// as long as you can getline
		if(rawInput.length() != 0){				// as long as the line isn't empty
		
			for(int i = 0; i < rawInput.length()-1; i++){		// loop through the line we took in
				if((rawInput.at(i) == '[') && (i != rawInput.length()-1) && (rawInput.at(i+1) != ']')){
				// if we find a '[' that isn't at the end of a line and isn't followed by a ']'
		
					i++;			// increment i to look at the next char
					temp.clear();	// clear the temp string
					for(int o = i; o != rawInput.length(); ++o){	// loop through the rest of the line
						if(rawInput.at(o) == ']'){			// if we find the closing bracket
							if( !(std::find(ipList.begin(), ipList.end(), temp) != ipList.end())){
								// if the IP isn't already in the list
								ipList.push_back(temp);
								// push the string into the list of IPs
							}
							i = o+1; 			// continue looking for IPs
							o = rawInput.size()-1; // change o in order to break out of the loop
						}
						else{
							if((rawInput.at(o) == '.') || ((rawInput.at(o) >= '0') && (rawInput.at(o) <= '9'))){
								// if the input is a decimal or a number
								temp+=rawInput.at(o); 	// add it into our temp string
							}
							else{		// the input was invalid
									i = o+1;	// continue checking for other IPs
									o = rawInput.size()-1;	// break out of the loop
									temp.clear();		// the string we've been taking is invalid
							}
						}
					}
				}
			}
		}
	}
	ifs.close();
}

void openOutputFile(std::string filename, std::vector<std::string>& ipList){
	std::ofstream ofs;		// output file stream
	if(ipList.size() != 0){		// if the vector isn't empty
		ofs.open((filename+".txt").c_str());	// open the file
		if(!ofs.is_open()){		// check if it's open
			std::cout << "Error: File could not be accessed" << std::endl;
		}
		for(int i=0; i<ipList.size(); ++i){	// check each element in the vector
			ofs << ipList.at(i) << std::endl;	// output each element to the file
		}
		ofs.close();
	}
}

int main(int argc, char** argv){
	std::vector<std::string> ipList;
	openInputFile(argv[1], ipList);
	openOutputFile(argv[2], ipList);
	return 0;
}