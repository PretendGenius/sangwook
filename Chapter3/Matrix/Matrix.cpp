#include "Matrix.h"

#include <iostream>

using namespace std;

Matrix::Matrix(int num_rows, int num_cols){
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    values_ = new float[num_rows_*num_cols_];
}

Matrix::Matrix(const Matrix& b){
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
    values_ = new float[num_rows_*num_cols_];

    for(int i = 0; i < num_rows_ * num_cols_; i++){
        values_[i] = b.values_[i];
    }
}

Matrix::~Matrix(){
    if(values_) {
        delete[] values_;
    }
}

void Matrix::setValue(int row, int col, float value){
    values_[row*(num_cols_) + col] = value;
}

float Matrix::getValue(int row, int col) const{
    return values_[row*(num_cols_) + col];
}

Matrix Matrix::transpose(){
    Matrix temp(num_cols_, num_rows_);

    for(int i = 0; i < num_rows_; i++){
        for(int j = 0; j < num_cols_; j++){
            temp.values_[j*(num_rows_) + i] = values_[i*(num_cols_) + j];
        }
    }

    return temp;
}

Matrix Matrix::add(const Matrix& b){
    int new_num_rows = num_rows_ > b.num_rows_ ? num_rows_ : b.num_rows_;
    int new_num_cols = num_cols_ > b.num_cols_ ? num_cols_ : b.num_cols_;
    Matrix temp(new_num_rows, new_num_cols);

    for(int i = 0; i < new_num_rows; i++){
        for(int j = 0; j < new_num_cols; j++){
            float sum = 0.0f;
            if(b.num_rows_ > i && b.num_cols_ > j){
                sum += b.getValue(i, j);
            }
            if(num_rows_ > i && num_cols_ > j){
                sum += getValue(i, j);
            }
            temp.setValue(i, j, sum);
        }
    }

    return temp;
}

void Matrix::print(){
    for(int i = 0; i < num_rows_; i++){
        for (int j = 0; j < num_cols_; j++){
            cout << getValue(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix m1(3, 4);
    m1.setValue(0, 0, 1.0f);
    m1.setValue(0, 1, 2.0f);
    m1.setValue(0, 2, 3.0f);
    m1.setValue(1, 0, 0.0f);
    m1.setValue(1, 1, 4.0f);
    m1.setValue(1, 2, 5.0f);
    m1.setValue(2, 3, 7.0f);

    m1.print();

    cout << endl;

    Matrix add = m1.add(m1);
    add.print();

    cout << endl;

    Matrix tr = m1.transpose();
    tr.print();

    return 0;
}