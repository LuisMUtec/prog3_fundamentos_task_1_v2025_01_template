//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "vector_3d.h"
using namespace std;

static void test_1() {
    geometry::vector_3d v(1, 2, 3);
    CHECK((v.get_x() == 1 && v.get_y() == 2 && v.get_z() == 3));
}

TEST_CASE("Question #1.1") {
    execute_test("question_1_test_1.in", test_1);
}