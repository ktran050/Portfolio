#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_set>
#include <ctime>
#include <algorithm>

using namespace std;

void setInsert(unsigned n, vector<string> v, set<string> &s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.insert(v.at(i));
    }
}

void uSetInsert(unsigned n, vector<string> v, unordered_set<string> &s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.insert(v.at(i));
    }
}

void setFind(unsigned n, vector<string> v, set<string> s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.find(v.at(i));
    }
}

void uSetFind(unsigned n, vector<string> v, unordered_set<string> s)
{
    for(unsigned i = 0; i < n; i++)
    {
        s.find(v.at(i));
    }
}

int main()
{
    string tempWord;        // string to hold words while taking em from file
    vector<string> words;   // vector to hold the words
    
    
    // open the file stream
    ifstream inFS("words.txt");
    
    // if the file stream isn't open
    if(!inFS.is_open())
    {
        cout << "File didn't open" << endl;
    }
    
    // take the words in
    while(inFS >> tempWord)
    {
        words.push_back(tempWord);
    }
    
    // close the stream
    inFS.close();
    
    // output info to file
    ofstream outFS("data.txt");
    
    // check if its open
    if(!outFS.is_open())
    {
        cout << "File couldn't open" << endl;
    }
    
    // all cases of n(5000-50000)
    for(unsigned n = 5000; n <= 50000; n += 5000)
    {
        
        float avgIT = 0.0;
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            set<string> s;
            clock_t t;
            t = clock();
            setInsert(n, words, s);
            t = clock() - t;
            avgIT += t;
        }
        avgIT = avgIT / 10;
        avgIT = ((float)avgIT)/CLOCKS_PER_SEC;
        
        float avgFT = 0.0;
        set<string> s;
        setInsert(50000, words, s);
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            clock_t t;
            t = clock();
            setFind(n, words, s);
            t = clock() - t;
            avgFT += t;
        }
        avgFT = avgFT / 10;
        avgFT = ((float)avgFT)/CLOCKS_PER_SEC;
        
        float avgHashIT = 0.0;
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle(words.begin(), words.end());
            unordered_set<string> us;
            clock_t t;
            t = clock();
            uSetInsert(n, words, us);
            t = clock() - t;
            avgHashIT += t;
        }
        avgHashIT = avgHashIT / 10;
        avgHashIT = ((float)avgHashIT)/CLOCKS_PER_SEC;
        
        float avgHashFT = 0.0;
        unordered_set<string> us;
        uSetInsert(50000, words, us);
        for(unsigned i = 0; i < 10; i++)
        {
            random_shuffle( words.begin(), words.end() );
            clock_t t;
            t = clock();
            
            uSetFind(n, words, us);
            t = clock() - t;
            avgHashFT += t;
        }
        avgHashFT = avgHashFT / 10;
        avgHashFT = ((float)avgHashFT)/CLOCKS_PER_SEC;
        
        outFS << n << " " << avgIT << " " << avgHashIT << " " << avgFT << " " 
        << avgHashFT << "\n";
    }
    
    return 0;
}