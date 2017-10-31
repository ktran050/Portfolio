//  =============== BEGIN ASSESSMENT HEADER ================
/// @file lab5.cpp
/// @brief Lab 5
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date November 4, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <string>

using namespace std;

int main()
{

    int ex;
    cout << "Which exercise? ";
    cin >> ex;
    cout << endl;
    
    if (1 == ex)
    {
    
        string userWord;
        char tempChar;
        
        // Take input from user
        cout << "Enter a word:" << endl;
        cin >> userWord;
        
        // Use loop to find x or e
        for (int iInt = 0; iInt < userWord.size() ; ++iInt)
        {
            tempChar = userWord.at(iInt);
            if(tempChar == 'x')
            {
                iInt = userWord.size();
                // Cout "Your word, heel, contains the character"
                cout << "Your word, " << userWord
                << ", contains the character '" << tempChar << "'" << endl;
            }
        }
        for (int iInt = 0; iInt < userWord.size() ; ++iInt)
        {
            tempChar = userWord.at(iInt);
            if(tempChar == 'e')
            {
                iInt = userWord.size();
                // Cout "Your word, heel, contains the character"
                cout << "Your word, " << userWord
                << ", contains the character '" << tempChar << "'" << endl;
            }
        }
        
    }
    
    else if (2 == ex)
    {
    
        string userWord;
        char tempChar;
    
        cout << "Enter a word:" << endl;
        cin >> userWord;
        
        // Use loop to find x or e
        for (int iInt = 0; iInt < userWord.size() ; ++iInt)
        {
            tempChar = userWord.at(iInt);
            if(tempChar == 'e')
            {
                userWord.at(iInt) = '3';
            }
        }
        for (int iInt = 0; iInt < userWord.size() ; ++iInt)
        {
            tempChar = userWord.at(iInt);
            if(tempChar == 'x')
            {
                userWord.at(iInt) = '*';
            }
        }
        for (int iInt = 0; iInt < userWord.size() ; ++iInt)
        {
            tempChar = userWord.at(iInt);
            if(tempChar == 'i')
            {
                userWord.at(iInt) = '1';
            }
        }
        cout << "Your word transformed is " << userWord << endl;
    } 
    
    else
    {
        string userWord;
        int charPos, wordPos;
        
        
        cin >> userWord;
        
        charPos = userWord.find('.');
        if(charPos == string::npos)
        {
            cout << "The entry does not contain the character '.'" << endl;
        }
        else
        {
            cout << "The character '.' is located at index " << charPos << endl;
        }
        wordPos = userWord.find("stop");
        if(wordPos == string::npos)
        {
            cout << "The entry does not contain the word \"stop\" "<< endl;
        }
        else
        {
            cout << "The word \"stop\" starts at index " << wordPos << endl;
        }
    }
    
    return 0;

}