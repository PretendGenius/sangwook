#include "SparsePolynomial.h"

#include <iostream>
#include <math.h>

using namespace std;

void SparsePolynomial::newTerm(float coef, int exp){
    if (coef == 0.0f){
        return;
    }

    if (num_terms_ >= capacity_){
        capacity_ = capacity_ > 0 ? capacity_ * 2 : 1;
        Term* new_term = new Term[capacity_];

        memcpy(new_term, terms_, sizeof(Term) * num_terms_);

        if (terms_) delete[] terms_;
        terms_ = new_term;
    }

    terms_[num_terms_].coef = coef;
    terms_[num_terms_].exp = exp;

    num_terms_++;
}

float SparsePolynomial::eval(float x){
    float temp = 0.0f;
    for(int i = 0; i < num_terms_; i++){
        temp += terms_[i].coef * powf(x, terms_[i].exp);
    }

    return temp;
}

SparsePolynomial SparsePolynomial::add(const SparsePolynomial& poly){
    SparsePolynomial temp;
    int first = 0;
    int second = 0;

    while(first < num_terms_ || second < poly.num_terms_){
        if(first >= num_terms_){
            temp.newTerm(poly.terms_[second].coef, poly.terms_[second].exp);
            second++;
            continue;
        } else if(second >= num_terms_){
            temp.newTerm(terms_[first].coef, terms_[first].exp);
            first++;
            continue;
        }
        if(terms_[first].exp > poly.terms_[second].exp){
            temp.newTerm(poly.terms_[second].coef, poly.terms_[second].exp);
            second++;
        } else if(terms_[first].exp < poly.terms_[second].exp){
            temp.newTerm(terms_[first].coef, terms_[first].exp);
            first++;
        } else {
            temp.newTerm(terms_[first].coef + poly.terms_[second].coef, terms_[first].exp);
            first++;
            second++;
        }
    }

    return temp;
}

void SparsePolynomial::print(){
    bool is_first = true;
    
    for (int i = 0; i < num_terms_; i++) {
        if (!is_first){
            cout << " + ";
        }
        cout << terms_[i].coef;
        if (terms_[i].exp != 0){
            cout << "*" << "x^" << terms_[i].exp;
        }
        is_first = false;
    }

    cout << endl;
}

int main() {
    {
        SparsePolynomial p1;

        p1.newTerm(1.0f, 0);
        p1.newTerm(1.5f, 1);
        p1.newTerm(2.0f, 2);

        p1.print();

        SparsePolynomial p2;

        p2.newTerm(1.0f, 1);
        p2.newTerm(3.0f, 2);
        p2.newTerm(5.0f, 7);
        p2.newTerm(2.0f, 11);

        p2.print();

        cout << endl;

        SparsePolynomial psum = p1.add(p2);
        psum.print();

        cout << endl;
    }

    return 0;
}

