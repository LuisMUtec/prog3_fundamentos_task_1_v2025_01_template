//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "fraction.h"

#include <numeric>
using namespace std;

namespace math :: operations {
    fraction :: fraction(double n, double d) : numerador(n), denominador(d) {}
    fraction operator+(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.denominador + f2.numerador * f1.denominador;
        result.denominador = f1.denominador * f2.denominador;
        result.simplificar();
        return result;
    };
    fraction operator-(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.denominador - f2.numerador * f1.denominador;
        result.denominador = f1.denominador * f2.denominador;
        result.simplificar();
        return result;
    };
    fraction operator*(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.numerador;
        result.denominador = f1.denominador * f2.denominador;
        result.simplificar();
        return result;
    };
    fraction operator/(const fraction &f1, const fraction &f2) {
        fraction result;
        result.numerador = f1.numerador * f2.denominador;
        result.denominador = f1.denominador * f2.numerador;
        result.simplificar();
        return result;
    };
    bool operator==(const fraction &f1, const fraction &f2) {
        return f1.numerador / f1.denominador == f2.numerador / f2.denominador;
    };

    void fraction :: simplificar() {
        int g = gcdnd();
        if (g != 1) {
            numerador /= g;
            denominador /= g;
        }
    }

    int fraction :: gcdnd() const {
        return gcd((int)numerador, (int)denominador);
    }

    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

}