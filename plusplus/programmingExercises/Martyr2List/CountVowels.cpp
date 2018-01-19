// URL: http://www.dreamincode.net/forums/topic/78802-martyr2s-mega-project-ideas-list/
// Date/Time:   6/30/2016 12:25PM
// Objective: Count the number of vowels in a user-given string
#include <iostream>

int main(){
    std::string userString, currChar;
    int aCount =0;
    std::cout<<"Please input a string: ";
    std::cin>>userString;
    
    for(int i=0; i<userString.size(); ++i){
        if(userString.at(i)=='a')
            ++aCount;
        else if(userString.at(i)=='e')
            ++eCount;
        else if(userString.at(i)=='i')
            ++iCount;
        else if(userString.at(i)=='o')
            ++oCount;
        else if(userString.at(i)=='u')
            ++uCount;
    }
    std::cout<<"Number of As: "<<aCount<<std::endl;
    std::cout<<"Number of Es: "<<eCount<<std::endl;
    std::cout<<"Number of Is: "<<iCount<<std::endl;
    std::cout<<"Number of Os: "<<oCount<<std::endl;
    std::cout<<"Number of Us: "<<uCount<<std::endl;
    return 0;
}