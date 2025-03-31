//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "system_log.h"
using namespace std;
namespace fs = std::filesystem;

static void test_3() {
    if (fs::exists("perf_log_3.csv")) fs::remove("perf_log_3.csv");
    performance::monitoring::system_log pm("perf_log_3.csv");
    pm.start("start_log");
    // Simular tarea
    pm.stop("stop_log");
    std::ifstream infile("perf_log_3.csv");
    std::string line;
    std::getline(infile, line);
    // Verificar que el formato incluya comas
    CHECK(line == "start_log,stop_log");
    infile.close();
}

TEST_CASE("Question #5.3") {
    execute_test("question_5_test_3.in", test_3);
}