//
// Created by konstantine on 3/21/24.
//

#include "MatrixOnVector.h"

vector<double> MatrixOnVector::matrixOnVectorMultiplication(vector<vector<double>> &matrix, vector<double> &vector) {
    std::vector<double> res(matrix.size(), 0);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < vector.size(); j++) {
            res[i] += matrix[i][j] * vector[j];
        }
    }

    return res;
}
