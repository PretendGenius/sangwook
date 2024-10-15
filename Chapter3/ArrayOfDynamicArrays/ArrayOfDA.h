#pragma once

class ArrayOfDA {
    public:
    ArrayOfDA(int num_rows, int num_cols);
    ArrayOfDA(const ArrayOfDA& b);
    ~ArrayOfDA();

    void setValue(int row, int col, float value);
    float getValue(int row, int col) const;
    ArrayOfDA add(const ArrayOfDA& b);
    ArrayOfDA transpose();
    void print();

    private:
    float** arrays_ = nullptr;
    int num_rows_ = 0;
    int num_cols_ = 0;
};