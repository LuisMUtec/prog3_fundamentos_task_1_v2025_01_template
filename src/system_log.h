//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_SYSTEM_LOG_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_SYSTEM_LOG_H

#include <string>
#include <chrono>
#include <unordered_map>
#include <mutex>

namespace performance :: monitoring {

        class system_log {
        public:
            explicit system_log(const std::string& output_path);

            void start(const std::string& task_name);
            void stop(const std::string& task_name);

        private:
            std::string output_file_path;
            std::unordered_map<std::string, std::chrono::high_resolution_clock::time_point> task_start_times;
            std::mutex mutex_;

            void log_to_file(const std::string& task_name, const std::string& event,
                             const std::chrono::high_resolution_clock::time_point& time_point);
        };

}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_SYSTEM_LOG_H
