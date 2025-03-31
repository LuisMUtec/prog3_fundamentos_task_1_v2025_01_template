//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "logger.h"
using namespace std;
namespace fs = std::filesystem;

static void test_4() {
    if (fs::exists("logger_test_4.txt")) fs::remove("logger_test_4.txt");
    {
        file::operations::logger flogger("logger_test_4.txt");
        flogger << "First";
    }
    {
        file::operations::logger flogger("logger_test_4.txt");
        flogger << "Second";
    }
    {
        file::operations::logger flogger("logger_test_4.txt");
        flogger.write("Third");
    }
    {
        file::operations::logger flogger("logger_test_4.txt");
        flogger.write("Fourth");
    }

    std::ifstream infile("logger_test_4.txt");
    std::string line;
    std::string result;
    int count = 0;
    while (std::getline(infile, line)) {
        ++count;
        std::cout << line << std::endl;
    }
    CHECK(count == 4);
    infile.close();
}

TEST_CASE("Question #4.4") {
    execute_test("question_4_test_4.in", test_4);
}