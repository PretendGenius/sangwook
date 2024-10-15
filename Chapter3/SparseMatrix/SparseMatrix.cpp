#include <iostream>
#include "SparseMatrix.h"

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity) {
    num_rows_ = num_rows;
    num_cols_ = num_cols;
    capacity_ = capacity;
    num_terms_ = 0;
    terms_ = new MatrixTerm[capacity];
}

SparseMatrix::SparseMatrix(const SparseMatrix& b) {
    num_rows_ = b.num_rows_;
    num_cols_ = b.num_cols_;
    capacity_ = b.capacity_;
    num_terms_ = b.num_terms_;
    terms_ = new MatrixTerm[capacity_];

    memcpy(terms_, b.terms_, sizeof(MatrixTerm) * num_terms_);
}

SparseMatrix::~SparseMatrix() {
    if(terms_) {
        delete[] terms_;
    }
}

void SparseMatrix::setValue(int row, int col, float value) {
    if(value == 0.0f) return;
    int key = col + num_cols_ * row;
    int i = 0;
    for (; i < num_terms_; i++){
        int key_i = terms_[i].col + num_cols_ * terms_[i].row;
        if (key_i == key) {
            terms_[i].row = row;
            terms_[i].col = col;
            terms_[i].value = value;
            return;
        } else if (key_i > key) {
            break;
        }
    }

    num_terms_++;
    for (int j = num_terms_ - 1; j > i; j--) {
        terms_[j] = terms_[j-1];
    }
    terms_[i].row = row;
    terms_[i].col = col;
    terms_[i].value = value;
}

float SparseMatrix::getValue(int row, int col) const {
    /*for(int i = 0; i < num_terms_; i++) {
        if(terms_[i].row == row && terms_[i].col == col) {
            return terms_[i].value;
        }
    }
    return 0.0f;*/
    int key = col + num_cols_ * row;
    for (int i = 0; i < num_terms_; i++){
        int key_i = terms_[i].col + terms_[i].row + num_cols_;
        if(key_i == key) {
            return terms_[i].value;
        } else if (key_i > key) {
            return 0.0f;
        }
    }
    return 0.0f;
}

SparseMatrix SparseMatrix::transpose() {
    SparseMatrix temp(num_cols_, num_rows_, capacity_);

    for (int r = 0; r < temp.num_rows_; r++) {
        for (int i = 0; i < num_terms_; i++) {
            if (terms_[i].col == r) {
                temp.terms_[temp.num_terms_].value = terms_[i].value;
                temp.terms_[temp.num_terms_].col = terms_[i].row;
                temp.terms_[temp.num_terms_].row = terms_[i].col;
                temp.num_terms_++;
            }
        }
    }

    return temp;
}

void SparseMatrix::printTerms() {
    for (int i = 0; i < num_terms_; i++){
        cout << "(" << terms_[i].row << ", "
        << terms_[i].col << ", "
        << terms_[i].value << ")"
        << endl;
    }
}

void SparseMatrix::print() {
    for (int r = 0; r < num_rows_; r++) {
        for (int c = 0; c < num_cols_; c++) {
            cout << getValue(r, c) << " ";
        }
        cout << endl;
    }
}

int main() {
    SparseMatrix m1(4, 6, 6);

    m1.setValue(2, 3, 5.0f);
    m1.setValue(0, 5, 2.0f);
    m1.setValue(1, 1, 1.0f);
    m1.setValue(0, 0, 1.0f);
    m1.setValue(0, 3, 7.0f);
    m1.setValue(1, 2, 3.0f);

    m1.printTerms();
    m1.print();

    cout << endl;

    SparseMatrix tr = m1.transpose();

    tr.printTerms();
    tr.print();

    return 0;
}