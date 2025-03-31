//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "fraction.h"
using namespace std;

static void test_3() {
    const math::operations::fraction f1(3, 9);
    const math::operations::fraction expected(1, 3);
    CHECK(f1 == expected);
}

TEST_CASE("Question #7.3") {
    execute_test("question_7_test_3.in", test_3);
}