//
// Created by konstantine on 3/21/24.
//

#ifndef ABSTRACTIONS_MATRIXONMATRIX_H
#define ABSTRACTIONS_MATRIXONMATRIX_H

#include <vector>

using namespace std;

class MatrixOnMatrix {
public:
    vector<vector<double>>
    matrixMultiplication(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2);

    vector<vector<double>> matrixExponentiation(vector<vector<double>> &matrix, int power);

    vector<vector<double>> LFactorization(vector<vector<double>> &matrix);
private:

};

#endif //ABSTRACTIONS_MATRIXONMATRIX_H