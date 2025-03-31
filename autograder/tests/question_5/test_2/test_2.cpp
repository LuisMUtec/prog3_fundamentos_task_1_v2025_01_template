//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "system_log.h"
using namespace std;
namespace fs = std::filesystem;

static void test_2() {
    if (fs::exists("perf_log_2.csv")) fs::remove("perf_log_2.csv");
    performance::monitoring::system_log pm("perf_log_2.csv");
    pm.start("task1:start");
    // Simular tarea 1
    pm.stop("task1:stop");
    pm.start("task2:start");
    // Simular tarea 2
    pm.stop("task2:stop");
    std::ifstream infile("perf_log_2.csv");
    int count = 0;
    std::string line;
    while (std::getline(infile, line)) {
        ++count;
        std::cout << line << std::endl;
    }
    CHECK(count == 2);
    infile.close();
}

TEST_CASE("Question #5.2") {
    execute_test("question_5_test_2.in", test_2);
}