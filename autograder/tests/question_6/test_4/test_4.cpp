//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "product.h"
using namespace std;

static void test_4() {
    const company::product prod1("item_a", 10.0, 2.0); // Ratio = 5.0
    const company::product prod2("item_b", 15.0, 15.0); // Ratio = 3.0
    const bool result = company::compare_by_value(prod2, prod1);
    CHECK(result == false);
}

TEST_CASE("Question #6.4") {
    execute_test("question_6_test_4.in", test_4);
}