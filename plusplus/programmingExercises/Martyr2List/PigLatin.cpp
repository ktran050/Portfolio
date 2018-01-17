// URL: http://www.dreamincode.net/forums/topic/78802-martyr2s-mega-project-ideas-list/
// Date/Time:   6/30/2016 12:25PM
// Words that start with consonants or consonant clusters will remove them
// and add them to the end (banana-ananabay)
// If they start with vowels concatenate a yay(eggyay)
#include <iostream>

int main(){
    std::string userString, pigString, tempString;
    
    std::cout<<"Please enter a string: ";
    std::cin>>userString;
    
    char currChar=userString.at(0);
    // if the word starts with a vowel concatenate yay
    if(currChar=='a' || currChar=='e' || currChar=='i' || currChar=='o' || currChar=='u'){
        pigString=userString+"yay";
    }
    // if the word is just one letter concatenate ay
    else if(userString.size()==1){
        pigString=userString+"ay";
    }
    // if the word starts with a consonant, figure out how many consonants in a row it has,
    // remove them and place them in the back
    else{
        for(int x=0; x<userString.size(); ++x){
            currChar=userString.at(x);
            if(currChar!='a' && currChar!='e' && currChar!='i' && currChar!='o' && currChar!='u'){
                tempString+=currChar;
            }
            else{
                x=userString.size();
            }
        }
        for(int x=tempString.size(); x<userString.size(); ++x){
            pigString+=userString.at(x);
        }
        pigString=pigString+tempString+"ay";
    }
    std::cout<<"Resulting string: "<<pigString<<std::endl;
    return 0;
}