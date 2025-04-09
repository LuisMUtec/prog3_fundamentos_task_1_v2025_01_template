//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "fraction.h"
using namespace std;

namespace math :: operations {
    fraction :: fraction(double n, double d) : numerador(n), denominador(d) {}
    fraction operator+(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
        result.denominador = f1.denominador * f2.denominador;
        return result;
    };
    fraction operator-(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
        result.denominador = f1.denominador * f2.denominador;
        return result;
    };
    fraction operator*(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.numerador;
        result.denominador = f1.denominador * f2.denominador;
        return result;
    };
    fraction operator/(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.denominador;
        result.denominador = f1.denominador * f2.numerador;
        return result;
    };
    bool operator==(const fraction &f1, const fraction &f2) {
        return f1.numerador / f1.denominador == f2.numerador / f2.denominador;
    };
}