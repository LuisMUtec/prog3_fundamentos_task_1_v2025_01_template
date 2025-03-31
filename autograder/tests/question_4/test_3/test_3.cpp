//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "logger.h"
using namespace std;
namespace fs = std::filesystem;

static void test_3() {
    if (fs::exists("logger_test_3.txt")) fs::remove("logger_test_3.txt");
    file::operations::logger flogger("logger_test_3.txt");
    flogger.write("First");
    flogger.write("Second");
    std::ifstream infile("logger_test_3.txt");
    std::string line;
    int count = 0;
    while (std::getline(infile, line)) {
        if (line.find("First") != std::string::npos ||
            line.find("Second") != std::string::npos)
            ++count;
    }
    assert(count >= 2);
    infile.close();
}

TEST_CASE("Question #4.3") {
    execute_test("question_4_test_3.in", test_3);
}