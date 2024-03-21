//
// Created by konstantine on 3/21/24.
//

#include "MatrixOnMatrix.h"

vector<vector<double>>
MatrixOnMatrix::matrixMultiplication(vector<vector<double>> &matrix1, vector<vector<double>> &matrix2) {
    vector<vector<double>> resMatrix(matrix1.size(), vector<double>(matrix2[0].size(), 0));

    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix2[0].size(); j++) {
            for (int k = 0; k < matrix1[0].size(); k++) {
                resMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return resMatrix;
}

vector<vector<double>> MatrixOnMatrix::matrixExponentiation(vector<vector<double>> &matrix, int power) {
    if (matrix.empty() || matrix[0].empty()) return {};
    vector<vector<double>> resMatrix(matrix.size(), vector<double>(matrix[0].size(), 0));

    if (power == 0) {
        for (int i = 0; i < matrix.size(); i++) {
            resMatrix[i][i] = 1;
        }
        return resMatrix;
    }

    if (power == 1) {
        return matrix;
    }

    resMatrix = matrixExponentiation(matrix, power / 2);
    resMatrix = matrixMultiplication(resMatrix, resMatrix);
    if (power % 2 == 1) {
        resMatrix = matrixMultiplication(resMatrix, matrix);
    }
    return resMatrix;
}