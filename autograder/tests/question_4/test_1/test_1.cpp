//
// Created by rudri on 9/12/2020.
//
#include <filesystem>
#include "catch.hpp"
#include "redirect_io.h"
#include "logger.h"
using namespace std;
namespace fs = std::filesystem;

static void test_1() {
  if (fs::exists("logger_test_1.txt")) fs::remove("logger_test_1.txt");
  file::operations::logger flogger("logger_test_1.txt");
  flogger.write("Test message");
  std::ifstream infile("logger_test_1.txt");
  std::string line;
  std::getline(infile, line);
  CHECK(line.find("Test message") != std::string::npos);
  infile.close();
}

TEST_CASE("Question #4.1") {
  execute_test("question_4_test_1.in", test_1);
}