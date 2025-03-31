//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "bag.h"
using namespace std;

static void test_1() {
    structures::bag b;
    b.add(10);
    b.add(20);
    CHECK(b.size() == 2);
}

TEST_CASE("Question #8.1") {
    execute_test("question_8_test_1.in", test_1);
}