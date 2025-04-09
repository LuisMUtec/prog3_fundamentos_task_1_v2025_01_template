#include <iostream>
#include <cassert>
#include "polynomial.h"
#include "tools/catch/catch.hpp"

void test_polynomial_initialization() {
    double coeffs[] = {2, 3, 4}; // Representa 2 + 3x + 4x^2
    math::operations::polynomial poly(2, coeffs);
    assert(poly.get_coefficient(0) == 2);
    assert(poly.get_coefficient(1) == 3);
    assert(poly.get_coefficient(2) == 4);
}

void test_polynomial_addition() {
    double coeffs1[] = {1, 2}; // Representa 1 + 2x
    double coeffs2[] = {3, 4}; // Representa 3 + 4x
    math::operations::polynomial poly1(1, coeffs1);
    math::operations::polynomial poly2(1, coeffs2);
    math::operations::polynomial sum = poly1 + poly2;
    assert(sum.get_coefficient(0) == 4);
    assert(sum.get_coefficient(1) == 6);
}

void test_polynomial_evaluation() {
    double cs1[] = {1, 2, 1}; // 1 + 2x + x^2
    const math::operations::polynomial p1(2, cs1);
    const double r1 = math::operations::evaluate(p1, 3); // 1 + 6 + 9 = 16
    CHECK(r1 == 16);
    double cs2[] = {999}; // 999
    const math::operations::polynomial p2(0, cs2);
    const double r2 = math::operations::evaluate(p2, 3); // 999 (no se afecta x^0)
    CHECK(r2 == 999);
}

void test_polynomial_producto() {
    double cs1[] = {2, 3, 4}; // Representa 2 + 3x + 4x^2
    const math::operations::polynomial p1(2, cs1);
    CHECK(p1.get_coefficient(0) == 2);
    CHECK(p1.get_coefficient(1) == 3);
    CHECK(p1.get_coefficient(2) == 4);
    double cs2[] = {4, 5, 2}; // Representa 4 + 5x + 2x^2
    const math::operations::polynomial p2(2, cs2);
    const auto p3 = p1 * p2;
    std::cout << p3 << std::endl;   // 8 22x^1 35x^2 26x^3 8x^4
    double cs3[] = {10, 2}; // Representa 10 + 2x
    const math::operations::polynomial p4(1, cs3);
    const auto p5 = p1 * p4;
    std::cout << p5 << std::endl;   // 20 34x^1 46x^2 8x^3
}

int main() {

    test_polynomial_producto();

    std :: cout << "Todos los tests pasaron correctamente." << std :: endl;

    return 0;
}
