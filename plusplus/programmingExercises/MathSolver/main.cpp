#include <iostream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>

using namespace std;

void userPrompt(vector<string> &uInput){      // Prompt user input and store it in a vector of strings
    string curr_input="";
    cout<<"Input equations. Begin a new one by pressing [Enter]. \n";
    cout<<"End by entering \"q\" as an equation. \n";
    
    do{
        cin>>curr_input;
        uInput.push_back(curr_input);
    }while(curr_input != "q");
    // if(!uInput.empty()){uInput.pop_back();}
    uInput.pop_back();
    return;
}

bool isValid(string sS){
    bool varSeen = false;
    bool equalSeen = false;
    unsigned errNum = 0;
    
    for(unsigned i=0;i<sS.size();i++){
        if(sS.at(i)=='='){
            if(equalSeen==false){ equalSeen=true;}  // if no equal sign seen yet, mark it
            else{
                errNum=1;
            }
        }
        if( (sS.at(i)>'a' && sS.at(i)<'z') || (sS.at(i)>'A'&&sS.at(i)<'Z') ){ // variable candiate spotted
            if(varSeen==false){ varSeen=true;}    // if no variable has been set then mark it
            else{
                errNum=2;
            }
        }
    }
    if(varSeen==false){
        errNum=3;
    }
    else if(equalSeen==false){
        errNum=4;
    }
    
    switch(errNum){
        case 1:
            cout<<"~Error 1: Multiple Equal Signs";
            return false;
            break;
        case 2:
            cout<<"~Error 2: Multiple Variables";
            return false;
            break;
        case 3:
            cout<<"~Error 3: No Equal Sign";
            return false;
            break;
        case 4:
            cout<<"~Error 4: No Variable";
            return false;
            break;
        default:
            break;
    }
}

bool solver(string sS){
    typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
    boost::char_separator<char> sep;
    tokenizer tok(sS,sep);
    for(tokenizer::iterator beg=tok.begin(); beg!=tok.end();beg++){
        cout << *beg << endl;
    }
    return true;
}

void testInput(const vector<string>& vV){
    cout<<"~~~~~~~~~~~~Begin testInput~~~~~~~~~~~~~~~ \n";
    for(unsigned i=0; i<vV.size(); ++i){
        cout<<vV.at(i)<<endl;
    }
    cout<<"@@@@@@@@@@@@End testInput@@@@@@@@@@@@@@@@@ \n";
    return;
}

int main(){
    vector<string> equationStorage;
    
    userPrompt(equationStorage);
    
    // testInput(equationStorage);
    

    for(unsigned i=0;i<equationStorage.size();++i){
        cout<<"Equation "<<i+1<<": ";
        if(isValid(equationStorage.at(i))){
            solver(equationStorage.at(i));
        }
        cout << endl;
    }
    
    return 0;
}