#include <string>

using namespace std;

class Date{
    private:
    unsigned day;
    unsigned month;
    string monthName;
    unsigned year;
    bool isLeap(int) const;
    unsigned daysPerMonth(unsigned, unsigned) const;
    unsigned number(const string &) const;
    string number(unsigned) const;
    
    public:
    Date();
    Date(unsigned, unsigned, unsigned);
    Date(string, unsigned, unsigned);
    Date addDays(int) const;
    void printNumeric() const;
    void printAlpha() const;
};