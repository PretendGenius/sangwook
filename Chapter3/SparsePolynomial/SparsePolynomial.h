#pragma once

struct Term{
    float coef;
    int exp;
};

class SparsePolynomial{
    public:
    SparsePolynomial(){

    }
    ~SparsePolynomial(){
        if(terms_) delete[] terms_;
    }

    void newTerm(float coef, int exp);
    float eval(float x);
    SparsePolynomial add(const SparsePolynomial& poly);
    void print();

    private:
    Term* terms_ = nullptr;
    int capacity_ = 0;
    int num_terms_ = 0;
};