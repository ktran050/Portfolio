#ifndef __User__
#define __User__

#include <string>

using namespace std;

class User{
    private:
        string username;
        string password;
    public:
        User();
        //creates a default user with empty name and password
        
        User(const string& uname, const string& pass);
        //creates a user with given username and password
        
        string get_username() const;
        //returns the current username
        
        bool check(const string& uname, const string& pass) const;
        //returns true if user info is correct
        //has to return false for empty unames and default user
        
        // void set_password(const string &newpass);
        // //sets a new password not used yet
};

#endif