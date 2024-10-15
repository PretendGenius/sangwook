#include <iostream>
#include "ArrayOfDA.h"

using namespace std;

ArrayOfDA::ArrayOfDA(int num_rows, int num_cols) {
    arrays_ = new float* [num_rows];

    for (int r = 0; r < num_rows; r++){
        arrays_[r] = new float [num_cols];
    }

    num_rows_ = num_rows;
    num_cols_ = num_cols;

    for (int r = 0; r < num_rows_; r++) {
        float* row = arrays_[r];

        for (int c = 0; c < num_cols_; c++) {
            row[c] = 0.0f;
        }
    }
}

ArrayOfDA::ArrayOfDA(const ArrayOfDA& b) {
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
    arrays_ = new float* [num_rows_];

    for (int r = 0; r < num_rows_; r++) {
        arrays_[r] = new float [num_cols_];
    }

    for (int r = 0; r < num_rows_; r++) {
        memcpy(arrays_[r], b.arrays_[r], sizeof(float) * num_cols_);
    }
}

ArrayOfDA::~ArrayOfDA() {
    if(arrays_) {
        for (int r = 0; r < num_rows_; r++) {
            delete[] arrays_[r];
        }
        delete[] arrays_;
    }
}

void ArrayOfDA::setValue(int row, int col, float value) {
    arrays_[row][col] = value;
}

float ArrayOfDA::getValue(int row, int col) const {
    return arrays_[row][col];
}

ArrayOfDA ArrayOfDA::transpose() {
    ArrayOfDA temp(num_cols_, num_rows_);

    for (int r = 0; r < num_rows_; r++){
        for (int c = 0; c < num_cols_; c++) {
            temp.setValue(c, r, getValue(r, c));
        }
    }
    
    return temp;
}
