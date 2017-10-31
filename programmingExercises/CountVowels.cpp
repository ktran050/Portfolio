// URL: http://www.dreamincode.net/forums/topic/78802-martyr2s-mega-project-ideas-list/
// Date/Time:   6/30/2016 12:25PM
// Objective: Count the number of vowels in a user-given string
#include <iostream>

int main(){
    std::string userString;
    int vowelCount;
    std::cout<<"Please input a string: ";
    std::cin>>userString;
    
    for(int i=0; i<userString.size(); ++i){
        if(userString.at(i)=='a' || userString.at(i)=='e')
            ++vowelCount;
        else if(userString.at(i)=='i' || userString.at(i)=='o' || userString.at(i)=='u')
            ++vowelCount;
    }
    std::cout<<"Number of vowels: "<<vowelCount<<std::endl;
    return 0;
}