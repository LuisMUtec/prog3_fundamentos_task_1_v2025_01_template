//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_POLYNOMIAL_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_POLYNOMIAL_H

    namespace math::operations {
        class polynomial {

            int degree;
            double* coefficients;

        public:

            polynomial();

            polynomial(int deg, double* coef) {
                this->degree = deg;
                coefficients = new double[deg+1];
                for (int i = 0; i <= degree; i++) {
                    this->coefficients[i] = coef[i];
                }
            };
            polynomial(const polynomial& p) {
                this->degree = p.degree;
                this->coefficients = new double[degree+1];
                for (int i = 0; i <= degree; i++) {
                    this->coefficients[i] = p.coefficients[i];
                }
            };

            polynomial(polynomial&& p) noexcept {
                std :: swap(degree,p.degree);
                std :: swap(coefficients,p.coefficients);
            };

            friend polynomial operator+(const polynomial& lhs, const polynomial& rhs);
            friend polynomial operator-(const polynomial& lhs, const polynomial& rhs);
            polynomial& operator=(const polynomial& rhs);

            polynomial operator*(const polynomial& p2) const {
                polynomial new_polynomial = polynomial(this->degree + p2.degree, new double[this->degree + p2.degree + 1]());
                for (int i = 0; i <= this->degree; i++) {
                    for (int j = 0; j <= p2.degree; j++) {
                        new_polynomial.coefficients[i+j] += this->coefficients[i] * p2.coefficients[j];
                    }
                }
                return new_polynomial;
            }

            friend std :: ostream& operator<<(std::ostream& os, const polynomial& p);
            friend double evaluate(const polynomial& p,const int n);

            double get_coefficient(const int i) const {
                return coefficients[i];
            }

            double& get_coefficient(const int i) {
                return coefficients[i];
            }

            int get_degree() {return degree;}

        };

        double evaluate(const polynomial& p,const int n);

    }

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_POLYNOMIAL_H
