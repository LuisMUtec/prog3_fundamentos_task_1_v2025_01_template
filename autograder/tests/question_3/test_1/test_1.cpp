//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "point.h"
using namespace std;

static void test_1() {
    const geometry::point p1(3 , 4) ;
    CHECK((p1.get_x() == 3 && p1.get_y() == 4));
}

TEST_CASE("Question #3.1") {
    execute_test("question_3_test_1.in", test_1);
}