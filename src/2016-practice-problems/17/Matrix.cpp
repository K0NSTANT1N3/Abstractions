//
// Created by konstantine on 6/30/24.
//

#include "Matrix.h"

Matrix::Matrix(int width, int height) {
    this->w = width;
    this->h = height;
    this->data = new double[width * height];
    for (int i = 0; i < this->w * this->h; i++)
        this->data[i] = 0.0;
}

Matrix::Matrix(const Matrix &other) {
    this->w = other.w;
    this->h = other.h;
    this->data = new double[this->w * this->h];
    for (int i = 0; i < this->w * this->h; i++)
        this->data[i] = other.data[i];
}

Matrix::~Matrix() {
    delete[] this->data;
}

double Matrix::getAt(int row, int col) {
    return this->data[row * this->w + col];
}

void Matrix::setAt(int row, int col, double val) {
    this->data[row * this->w + col] = val;
}

void Matrix::addAt(int row, int col, double val) {
    this->data[row * this->w + col] += val;
}

Matrix Matrix::add(Matrix &other) {
    Matrix sum(this->w, this->h);
    for (int i = 0; i < this->w * this->h; i++) {
        sum.data[i] = this->data[i] + other.data[i];
    }
}

Matrix Matrix::times(Matrix &other) {
    Matrix result(other.w, this->h);
    for (int i = 0; i < this->h; i++) {
        for (int j = 0; j < other.w; j++) {
            for (int k = 0; k < this->w; k++) {
                result.addAt(i, j, this->getAt(i, k) + other.getAt(k, j));
            }
        }
    }
    return result;
}




