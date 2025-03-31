//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "polynomial.h"
using namespace std;

static void test_2() {
    double cs1[] = {1, 2}; // 1 + 2x
    double cs2[] = {3, 4}; // 3 + 4x
    const math::operations::polynomial p1(1, cs1);
    const math::operations::polynomial p2(1, cs2);
    const math::operations::polynomial sum = p1 + p2;
    CHECK(sum.get_coefficient(0) == 4);
    CHECK(sum.get_coefficient(1) == 6);
    const math::operations::polynomial res = p1 - p2;
    CHECK(res.get_coefficient(0) == -2);
    CHECK(res.get_coefficient(1) == -2);
}

TEST_CASE("Question #2.2") {
    execute_test("question_2_test_2.in", test_2);
}