//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "polynomial.h"
using namespace std;

static void test_3() {
    double cs1[] = {1, 2, 1}; // 1 + 2x + x^2
    const math::operations::polynomial p1(2, cs1);
    const double r1 = math::operations::evaluate(p1, 3); // 1 + 6 + 9 = 16
    CHECK(r1 == 16);
    double cs2[] = {999}; // 1 + 2x + x^2
    const math::operations::polynomial p2(0, cs2);
    const double r2 = math::operations::evaluate(p2, 3); // 1 + 6 + 9 = 16
    CHECK(r2 == 999);
}

TEST_CASE("Question #2.3") {
    execute_test("question_2_test_3.in", test_3);
}