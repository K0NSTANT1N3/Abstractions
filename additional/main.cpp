//
// Created by konstantine on 3/21/24.
//

#include <iostream>
#include "linear-algebra/MatrixOnMatrix.h"
#include "linear-algebra/MatrixOnVector.h"

using namespace std;


int main() {
    MatrixOnVector mov;
    MatrixOnMatrix mom;

    vector<vector<double>> matrix1 = {{0.2, 0.3, 0.4},
                                      {0.1, 0.4, 0.5},
                                      {0.7, 0.3, 0.1}};

    vector<double> vec = {0, 1, 0};

    for (int i = 0; i < 40; i++) {
        matrix1 = mom.matrixExponentiation(matrix1, 40);


    }

    vec = mov.matrixOnVectorMultiplication(matrix1, vec);


    for (int n = 0; n < vec.size(); n++) {
        cout << vec[n] << ' ';
    }
    cout << endl;
    cout << "hello world";
}