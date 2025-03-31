//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "bag.h"
using namespace std;

static void test_3() {
    const structures::bag b;
    CHECK(b.size() == 0);
}

TEST_CASE("Question #8.3") {
    execute_test("question_8_test_3.in", test_3);
}