//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "product.h"
using namespace std;

static void test_1() {
    const company::product prod("gadget", 29.99, 1.5);
    CHECK(prod.get_name() == "gadget");
    CHECK(prod.get_price() == 29.99);
    CHECK(prod.get_weight() == 1.5);

}

TEST_CASE("Question #6.1") {
    execute_test("question_6_test_1.in", test_1);
}