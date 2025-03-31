//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "vector_3d.h"
using namespace std;

static void test_4() {
    const geometry::vector_3d v1(1, 2, 3);
    const geometry::vector_3d v2(4, -2, 0);
    const geometry::vector_3d sub = v1 - v2;
    CHECK((sub.get_x() == -3 && sub.get_y () == 4 && sub.get_z () == 3));
}

TEST_CASE("Question #1.4") {
    execute_test("question_1_test_4.in", test_4);
}