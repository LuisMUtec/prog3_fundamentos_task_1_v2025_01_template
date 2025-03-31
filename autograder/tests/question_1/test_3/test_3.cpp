//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "vector_3d.h"
using namespace std;

static void test_3() {
    const geometry::vector_3d v1(1, 2, 3);
    const geometry::vector_3d v2(4, -2, 0);
    const double dot = geometry::dot_product(v1, v2); // 1*4 + 2*(-2) + 3*0 = 0
    CHECK(dot == 0);
}

TEST_CASE("Question #1.3") {
    execute_test("question_1_test_3.in", test_3);
}