//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "bag.h"
using namespace std;

static void test_2() {
    structures::bag b;
    b.add(5);
    b.add(15);
    int sum = 0;
    for (auto node = b.begin(); node != b.end(); node = node->next) {
        sum += node->data;
    }
    CHECK(sum == 20);
}

TEST_CASE("Question #8.2") {
    execute_test("question_8_test_2.in", test_2);
}