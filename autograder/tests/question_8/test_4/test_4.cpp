//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "bag.h"
using namespace std;

static void test_4() {
    structures::bag b;
    b.add(1);
    b.add(2);
    b.add(3);
    // Debido a que se insertan al inicio, se espera que el orden de los elementos sea 3, 2, 1.
    constexpr int expected[] = {3, 2, 1};
    int i = 0;
    for (auto node = b.begin(); node != b.end(); node = node->next) {
        assert(node->data == expected[i]);
        ++i;
    }
    // Verificamos que se recorrió exactamente 3 elementos.
    assert(i == 3);
}

TEST_CASE("Question #8.4") {
    execute_test("question_8_test_4.in", test_4);
}