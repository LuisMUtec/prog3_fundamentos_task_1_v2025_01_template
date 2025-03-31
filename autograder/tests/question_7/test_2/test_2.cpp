//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "fraction.h"
using namespace std;

static void test_2() {
    const math::operations::fraction f1(1, 2);
    const math::operations::fraction f2(1, 2);
    const math::operations::fraction sum = f1 + f2;
    CHECK((sum.get_numerator() == 1 && sum.get_denominator() == 1));
}

TEST_CASE("Question #7.2") {
    execute_test("question_7_test_2.in", test_2);
}