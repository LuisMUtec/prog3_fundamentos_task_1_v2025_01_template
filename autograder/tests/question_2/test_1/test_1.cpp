//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "polynomial.h"
using namespace std;

static void test_1() {
    double cs1[] = {2 , 3, 4}; // Representa 2 + 3x + 4x ^2
    math::operations::polynomial p1(2, cs1);
    CHECK (p1.get_coefficient (0) == 2) ;
    CHECK (p1.get_coefficient (1) == 3) ;
    CHECK (p1.get_coefficient (2) == 4) ;

    math::operations::polynomial p3 = p1;
    p3.get_coefficient(0) = 4;
    CHECK (p1.get_coefficient (0) == 2) ;
    CHECK (p1.get_coefficient (1) == 3) ;
    CHECK (p1.get_coefficient (2) == 4) ;
    CHECK (p3.get_coefficient (0) == 4) ;
    CHECK (p3.get_coefficient (1) == 3) ;
    CHECK (p3.get_coefficient (2) == 4) ;

    double cs2[] = {4 , 5}; // Representa 4 + 5x
    math::operations::polynomial p2 (1 , cs2);
    p3 = p2;
    p3.get_coefficient(1) = 6;
    CHECK (p2.get_coefficient (0) == 4) ;
    CHECK (p2.get_coefficient (1) == 5) ;
    CHECK (p3.get_coefficient (0) == 4) ;
    CHECK (p3.get_coefficient (1) == 6) ;

    p1 = std::move(p2);
    CHECK (p2.get_degree() == -1);
    CHECK (p1.get_coefficient (0) == 4) ;
    CHECK (p1.get_coefficient (1) == 5) ;
}

TEST_CASE("Question #2.1") {
    execute_test("question_2_test_1.in", test_1);
}