//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "point.h"
using namespace std;

static void test_3() {
    const geometry::point p1(3, 4);
    const geometry::point p2(3, 4);
    CHECK(p1 == p2);
}

TEST_CASE("Question #3.3") {
    execute_test("question_3_test_3.in", test_3);
}