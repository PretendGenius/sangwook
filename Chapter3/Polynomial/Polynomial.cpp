#include "Polynomial.h"

#include <iostream>
#include <math.h>

using namespace std;

Polynomial::Polynomial(int max_degree){
    capacity_ = max_degree + 1;

    coeffs_ = new float[capacity_];

    for (int i = 0; i < capacity_; i++){
        coeffs_[i] = 0.0f;
    }
}

Polynomial::Polynomial(const Polynomial& poly){
    this->capacity_ = poly.capacity_;
    coeffs_ = new float[capacity_];
    for (int i = 0; i < capacity_; i++){
        coeffs_[i] = poly.coeffs_[i];
    }
}

Polynomial::~Polynomial(){
    if(coeffs_) delete[] coeffs_;
}

int Polynomial::maxDegree(){
    int maxDegree = 0;

    for(int i = 0; i < capacity_; i++){
        if(coeffs_[i] > 0.0f){
            maxDegree = i;
        }
    }
    return maxDegree;
}

void Polynomial::newTerm(const float coef, const int exp){
    coeffs_[exp] = coef;
}

Polynomial Polynomial::add(const Polynomial& poly){
    Polynomial temp;

    for(int i = 0; i < temp.capacity_; i++) {
        temp.newTerm(coeffs_[i] + poly.coeffs_[i], i);
    }

    return temp;
}

Polynomial Polynomial::mult(const Polynomial& poly){
    Polynomial temp;

    for(int i = 0; i <= maxDegree(); i++){
        if(coeffs_[i] != 0.0f){
            for(int j = 0; j < poly.capacity_; j++){
                temp.coeffs_[i + j] += coeffs_[i] * poly.coeffs_[j];
            }
        }  
    }

    return temp;
}

float Polynomial::eval(float x){
    float sum = 0;

    for(int i = 0; i <= maxDegree(); i++){
        sum += coeffs_[i] * powf(x, i);
    }

    return sum;
}

void Polynomial::print(){
    for(int i = 0; i <= maxDegree(); i++){
        if(coeffs_[i] > 0){
            cout << " + " << coeffs_[i] << "x^" << i;
        } else if(coeffs_[i] < 0){
            cout << coeffs_[i] << "x^" << i;
        }
    }
    cout << endl;
}

int main(){
    Polynomial p1;

    p1.newTerm(1.0f, 0);
    p1.newTerm(1.5f, 1);
    p1.newTerm(2.0f, 2);

    p1.print();

    cout << p1.eval(0.0f) << endl;
    cout << p1.eval(1.0f) << endl;
    cout << p1.eval(2.0f) << endl;

    cout << endl;

    Polynomial p2;

    p2.newTerm(1, 1);
    p2.newTerm(3, 2);

    p2.print();

    cout << endl;

    cout << "Add()" << endl;

    Polynomial psum = p1.add(p2);
    psum.print();

    cout << endl;

    cout << "Mult()" << endl;

    p1.print();
    p2.print();

    Polynomial pmul = p1.mult(p2);
    pmul.print();

    return 0;
}
