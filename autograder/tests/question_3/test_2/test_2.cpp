//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "point.h"
using namespace std;

static void test_2() {
    const geometry::point p1(3, 4);
    const geometry::point p2(1, 2);
    const geometry::point p3 = p1 + p2;
    assert(p3.get_x() == 4 && p3.get_y() == 6);
}

TEST_CASE("Question #3.2") {
    execute_test("question_3_test_2.in", test_2);
}