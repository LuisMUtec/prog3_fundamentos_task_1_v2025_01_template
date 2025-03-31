//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "product.h"
using namespace std;

static void test_2() {
    const company::product prod1("widget", 19.99, 0.8);
    const company::product prod2("widget", 19.99, 0.8);
    const company::product prod3("widget", 19.99, 1.0);
    CHECK(prod1 == prod2);
    CHECK(!(prod1 == prod3));

}

TEST_CASE("Question #6.2") {
    execute_test("question_6_test_2.in", test_2);
}