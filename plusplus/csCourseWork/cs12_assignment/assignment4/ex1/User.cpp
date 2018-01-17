#include "User.h"
#include <string>

using namespace std;

User::User(){
    
}

User::User(const string& uname, const string& pass){
    username = uname;
    password = pass;
}

string User::get_username() const{
    return username;
}

bool User::check(const string &uname, const string &pass) const{
    bool userInfo = 0;
    
    if((uname.empty())||(pass.empty())){
        userInfo = 0;
    }
    
    if((username == uname) && (password == pass)){
        userInfo = 1;
    }
    
    return userInfo;
}

// void set_password(const string &newpass){
    
// }