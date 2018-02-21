// URL: http://www.dreamincode.net/forums/topic/78802-martyr2s-mega-project-ideas-list/
// Date/Time:   6/30/2016 12:18PM
#include <iostream>
#include <string>

int main(){
    std::string userString, reversedString;
    std::cout<<"Please input a string: ";
    std::cin>>userString;
    
    for(int x=0; x<userString.size(); ++x){
        reversedString+=userString.at(userString.size()-1-x);
    }
    std::cout<<"Resultant string: "<<reversedString<<std::endl;
    return 0;
}