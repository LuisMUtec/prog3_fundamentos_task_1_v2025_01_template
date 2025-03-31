//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "logger.h"
using namespace std;
namespace fs = std::filesystem;

static void test_2() {
    if (fs::exists("logger_test_2.txt")) fs::remove("logger_test_2.txt");
    file::operations::logger flogger("logger_test_2.txt");
    flogger << "Another message";
    std::ifstream infile("logger_test_2.txt");
    std::string line;
    std::getline(infile, line);
    CHECK(line.find("Another message") != std::string::npos);
    infile.close();
}

TEST_CASE("Question #4.2") {
    execute_test("question_4_test_2.in", test_2);
}