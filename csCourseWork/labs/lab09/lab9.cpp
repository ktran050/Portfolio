//  =============== BEGIN ASSESSMENT HEADER ================
/// @file mathematics.cpp
/// @brief Lab 9
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date December 2nd, 2014
//  ================== END ASSESSMENT HEADER ===============
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

void fillVector(vector <double> &);
// Adds onto vector size
double average(const vector <double> &);
// Finds the average of the vector
double standardDeviation(vector <double> &v, double mean);
// Finds the standard deviation
 
int main()
{
    return 0;
}

void fillVector(vector <double> &v)
{
    double d;
    while (cin >> d)
    {
        v.push_back(d);
    }
}

double average(const vector <double> &v)
{
    double sum = 0.;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v.at(i);
    }

    return sum / v.size();
}

double standardDeviation(vector <double> &v)
{
    double result = 0;
    double mean = average(v);
    for(int i = 0; i < v.size(); ++i)
    {
        v.at(i) = v.at(i) - mean;
    }
    for(int i = 0; i < v.size(); ++i)
    {
        result += pow(v.at(i),2);
    }
    return sqrt(result/ v.size());
}

// Use fillVector
// Find the averages of fillVector
// Subtract average from vector
// Square the resulting vector
// Sum the vector