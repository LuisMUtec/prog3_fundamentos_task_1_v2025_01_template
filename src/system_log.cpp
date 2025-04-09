//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "system_log.h"
using namespace std;

#include "system_log.h"
#include <fstream>
#include <iostream>


namespace performance::monitoring {

        system_log::system_log(const std::string& output_path)
            : output_file_path(output_path) {}

        void system_log::start(const std::string& task_name) {
            std::lock_guard<std::mutex> lock(mutex_);
            auto now = std::chrono::high_resolution_clock::now();
            task_start_times[task_name] = now;
            log_to_file(task_name, "start", now);
        }

        void system_log::stop(const std::string& task_name) {
            std::lock_guard<std::mutex> lock(mutex_);
            auto now = std::chrono::high_resolution_clock::now();

            auto it = task_start_times.find(task_name);
            if (it != task_start_times.end()) {
                log_to_file(task_name, "stop", now);
                task_start_times.erase(it);
            } else {
                std::cerr << "Tarea '" << task_name << "' no fue iniciada.\n";
            }
        }

        void system_log::log_to_file(const std::string& task_name, const std::string& event,
                                     const std::chrono::high_resolution_clock::time_point& time_point) {
            std::ofstream file(output_file_path, std::ios::app);
            if (file.is_open()) {
                auto timestamp = std::chrono::duration_cast<std::chrono::microseconds>(
                                     time_point.time_since_epoch())
                                     .count();
                file << task_name << "," << event << "," << timestamp << "\n";
            } else {
                std::cerr << "No se pudo abrir el archivo: " << output_file_path << "\n";
            }
        }

    } // namespace performance::monitoring



