//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "system_log.h"
using namespace std;
namespace fs = std::filesystem;

static void test_4() {
    if (fs::exists("perf_log_4.csv")) fs::remove("perf_log_4.csv");
    {
        performance::monitoring::system_log pm("perf_log_4.csv");
        pm.start("start_log_1");
        // Simular tarea
        pm.stop("stop_log_1");
    }
    {
        performance::monitoring::system_log pm("perf_log_4.csv");
        pm.start("start_log_2");
        // Simular tarea
        pm.stop("stop_log_2");
        pm.start("start_log_3");
        // Simular tarea
        pm.stop("stop_log_3");
    }
    std::ifstream infile("perf_log_4.csv");
    int count = 0;
    std::string line;
    while (std::getline(infile, line)) {
        ++count;
        std::cout << line << std::endl;
    }
    CHECK(count == 3);
    infile.close();
}

TEST_CASE("Question #5.4") {
    execute_test("question_5_test_4.in", test_4);
}