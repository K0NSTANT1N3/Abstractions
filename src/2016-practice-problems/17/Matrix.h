#ifndef MATRIX_CLASS_H_
#define MATRIX_CLASS_H_

class Matrix {
private:
    int w, h;
    double *data;
public:
    Matrix(int width, int height);

    Matrix(const Matrix &other);

    ~Matrix();

    double getAt(int row, int col);

    void setAt(int row, int col, double val);

    void addAt(int row, int col, double val);

    Matrix add(Matrix &other);

    Matrix times(Matrix &other);
};

#endif