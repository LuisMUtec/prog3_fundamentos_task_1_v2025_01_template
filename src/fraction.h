//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_FRACTION_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_FRACTION_H

namespace math :: operations {
    class fraction {
        double numerador;
        double denominador;
        public:
        fraction(){};
        double get_numerator() const {return numerador;}
        double get_denominator() const {return denominador;}
        fraction(double numerador, double denominador);
        friend fraction operator+(const fraction &f1, const fraction &f2);
        friend fraction operator-(const fraction &f1, const fraction &f2);
        friend fraction operator*(const fraction &f1, const fraction &f2);
        friend fraction operator/(const fraction &f1, const fraction &f2);
        friend bool operator==(const fraction &f1, const fraction &f2);
        void simplificar();
        int gcdnd() const;

    };


}


#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_FRACTION_H
