#pragma once

class Matrix{
    public:
    Matrix(int num_rows, int num_cols);
    Matrix(const Matrix& b);
    ~Matrix();

    void setValue(int row, int col, float value);
    float getValue(int row, int col) const;
    Matrix add(const Matrix& b);
    Matrix transpose();
    void print();

    private:
    float* values_ = nullptr;
    int num_rows_ = 0;
    int num_cols_ = 0;
};