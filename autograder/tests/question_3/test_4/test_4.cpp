//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "point.h"
using namespace std;

static void test_4() {
    const geometry::point p1(3, 4);
    const geometry::point p2(3, 4);
    const auto p3 = p1 + p2;
    std::cout << p3 << std::endl;
}

TEST_CASE("Question #3.4") {
    execute_test("question_3_test_4.in", test_4);
}
