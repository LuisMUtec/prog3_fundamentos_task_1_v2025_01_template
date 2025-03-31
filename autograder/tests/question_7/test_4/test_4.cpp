//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "fraction.h"
using namespace std;

static void test_4() {
    const math::operations::fraction f1(3, 2);
    const math::operations::fraction f2(1, 2);
    const math::operations::fraction sum = f1 + f2;
    CHECK((sum.get_numerator() == 2 && sum.get_denominator() == 1));
}

TEST_CASE("Question #7.4") {
    execute_test("question_7_test_4.in", test_4);
}