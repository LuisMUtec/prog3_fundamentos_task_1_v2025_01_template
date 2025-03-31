//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "polynomial.h"
using namespace std;

static void test_4() {
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

TEST_CASE("Question #2.4") {
    execute_test("question_2_test_4.in", test_4);
}