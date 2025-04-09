//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "polynomial.h"

#include <cmath>
#include <math.h>
using namespace std;

namespace math::operations {
    std::ostream& operator<<(std :: ostream &os, const polynomial &p) {
        os << p.coefficients[0] << " ";
        for (int i = 1; i <= p.degree; i++) {
            os << p.coefficients[i] << "x^" << i << " ";
        }
        return os;
    }

    double evaluate(const polynomial& p,const int n) {
        int resultado = 0;
        for (int i = 0; i <= p.degree; i++) {
            resultado += p.coefficients[i] * pow(n,i);
        }
        return resultado;
    }

    polynomial operator+(const polynomial& lhs, const polynomial& rhs) {
        int d = lhs.degree > rhs.degree ? lhs.degree : rhs.degree;
        double* coefficients = new double[d+1]();
        for (int i = 0; i <= lhs.degree; i++) {
            coefficients[i] += lhs.coefficients[i];
        }

        for (int i = 0; i <= rhs.degree; i++) {
            coefficients[i] += rhs.coefficients[i];
        }
        return polynomial(d,coefficients);
    }

    polynomial operator-(const polynomial& lhs, const polynomial& rhs) {
        int d = lhs.degree > rhs.degree ? lhs.degree : rhs.degree;
        double* coefficients = new double[d+1]();
        for (int i = 0; i <= lhs.degree; i++) {
            coefficients[i] += lhs.coefficients[i];
        }

        for (int i = 0; i <= rhs.degree; i++) {
            coefficients[i] -= rhs.coefficients[i];
        }
        return polynomial(d,coefficients);

    }

    polynomial& polynomial :: operator=(const polynomial& rhs) {
        delete[] this->coefficients;
        coefficients = new double[rhs.degree+1]();
        this->degree = rhs.degree;
        for (int i = 0; i <= rhs.degree; i++) {
            this->coefficients[i] = rhs.coefficients[i];
        }
        return *this;
    }

}


