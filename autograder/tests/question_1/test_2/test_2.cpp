//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "vector_3d.h"
using namespace std;

static void test_2() {
    const geometry::vector_3d v1 (1 , 2, 3) ;
    const geometry::vector_3d v2 (4 , -2, 0) ;
    const geometry::vector_3d sum = v1 + v2 ;
    CHECK((sum.get_x() == 5 && sum.get_y () == 0 && sum.get_z () == 3));
}

TEST_CASE("Question #1.2") {
    execute_test("question_1_test_2.in", test_2);
}