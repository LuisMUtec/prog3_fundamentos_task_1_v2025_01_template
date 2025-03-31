//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "system_log.h"
using namespace std;
namespace fs = std::filesystem;

static void test_1() {
    if (fs::exists("perf_log_1.csv")) fs::remove("perf_log_1.csv");
    performance::monitoring::system_log pm("perf_log_1.csv");
    pm.start("task1:start");
    // Simular una tarea (por ejemplo, un retardo)
    pm.stop("task1:stop");
    std::ifstream infile("perf_log_1.csv");
    std::string line;
    std::getline(infile, line);
    CHECK(line == "task1:start,task1:stop");
    infile.close();
}

TEST_CASE("Question #5.1") {
    execute_test("question_5_test_1.in", test_1);
}