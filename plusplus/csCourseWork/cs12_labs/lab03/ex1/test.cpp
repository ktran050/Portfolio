//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 2 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 13th, 2015
///
/// @par Enrollment Notes 
///     Lecture Section: 002
/// @par
///     Lab Section: 023
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>

using namespace std;

const int M = 2;
const int N = 3;

void matrixAdd(const int a[][N], const int b[][N], int sum[][N]);

int main(){
    int a[M][N];
    int b[M][N];
    int sum[M][N];
    
    //take in matrix a
    cout << "Enter Matrix A: ";
    for(int c = 0; c < M; ++c){
        for(int d = 0; d < N; ++d){
            cin >> a[c][d];
        }
    }
    
    // take in matrix b
    cout << "Enter Matrix B: ";
    for(int c = 0; c < M; ++c){
        for(int d = 0; d < N; ++d){
            cin >> b[c][d];
        }
    }
    
    //call function matrixAdd
    matrixAdd(a, b, sum);
    
    //output the sum array
    cout << "Matrix Sum: ";
    for(int c = 0; c < M; ++c){
        for(int d = 0; d < N; ++d){
            cout << sum[c][d] << " ";
        }
    }
    cout << endl;
    
    //TESTS
    // cout << "Matrix A: ";
    // for(int c = 0; c < M; ++c){
    //     for(int d = 0; d < N; ++d){
    //         cout << a[c][d] << " ";
    //     }
    // }
    // cout << endl;
    // cout << "Matrix B: ";
    // for(int c = 0; c < M; ++c){
    //     for(int d = 0; d < N; ++d){
    //         cout << b[c][d] << " ";
    //     }
    // }
    // cout << endl;
    
    
    return 0;
}


void matrixAdd(const int a[M][N], const int b[M][N], int sum[M][N]){
    for(int c = 0; c < M; ++c){
        for(int d = 0; d < N; ++d){
            sum[c][d] = a[c][d] + b[c][d];
        }
    }
}