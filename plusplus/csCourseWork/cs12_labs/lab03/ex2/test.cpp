//  =============== BEGIN ASSESSMENT HEADER ================
/// @file main.cpp 
/// @brief Lab 3 for CS 12 Winter 2015
///
/// @author Kevin Tran [ktran050@ucr.edu]
/// @date January 20th, 2015
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

//Global const; may change; R and S may be the same
const int Q = 2;
const int R = 3;
const int S = 3;

//declare the function
void matrixMult(const int a[][R], const int b[][S], int product[][S]);

//main to test stuff
int main(){
    int a[Q][R] = {0};
    int b[R][S] = {0};
    int product[Q][S] = {0};

    
    // Test if a and b are populated with 0s
    // cout << "Matrix A: " << endl;;
    // for(int q = 0; q < Q; ++q){
    //     for(int c = 0; c < R; ++c){
    //         cout << a[q][c] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    // cout << "Matrix B: " << endl;;
    // for(int q = 0; q < R; ++q){
    //     for(int c = 0; c < S; ++c){
    //         cout << b[q][c] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
    //take in matrix a
    cout << "Enter Matrix A(size 2x3): ";
    for(int q = 0; q < Q; ++q){
        for(int c = 0; c < R; ++c){
            cin >> a[q][c];
        }
    }
    
    //take in matrix b
    cout << "Enter Matrix B(size 3x3): ";
    for(int q = 0; q < R; ++q){
        for(int c = 0; c < S; ++c){
            cin >> b[q][c];
        }
    }
    
    //call matrixMult
    matrixMult(a, b, product);
    
    //output the product of a and b
    cout << "Res: " << endl;
    for(int q = 0; q < Q; ++q){
        for(int c = 0; c < S; ++ c){
            cout << product[q][c] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

//the actual function
void matrixMult(const int a[][R], const int b[][S], int product[][S]){
    for(int q = 0; q < Q; ++q){
        for(int c = 0; c < S; ++c){
            for(int d = 0; d < R; ++d){
                product[q][c] += a[q][d] * b[d][c];
                cout << "product[q][c]: " << product[q][c] << endl;
            }
        }
    }
}