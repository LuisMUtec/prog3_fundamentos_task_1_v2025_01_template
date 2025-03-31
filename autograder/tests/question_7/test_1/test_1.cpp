//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "fraction.h"
using namespace std;

static void test_1() {
    const math::operations::fraction f1(2, 4);
    const math::operations::fraction f2(1, 2);
    CHECK(f1 == f2);
}

TEST_CASE("Question #7.1") {
    execute_test("question_7_test_1.in", test_1);
}