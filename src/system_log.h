//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_SYSTEM_LOG_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_SYSTEM_LOG_H

#include <chrono>
#include <fstream>
#include <string>
#include <stdexcept>

namespace performance {
    namespace monitoring {

        class system_log {
        public:
            // Constructor que recibe la ruta del archivo de salida.
            explicit system_log(const std::string& file_path);

            // Destructor.
            ~system_log();

            // Inicia la medición asociada a una tarea, registrando el mensaje de inicio.
            void start(const std::string& message);

            // Detiene la medición asociada a la tarea actual y registra el mensaje de fin.
            void stop(const std::string& message);

        private:
            std::ofstream output_file;  // Archivo de salida para almacenar el log.
            std::string current_start_message;  // Almacena el mensaje de inicio de la tarea.
            std::chrono::time_point<std::chrono::high_resolution_clock> start_time;  // Instante en el que se inició la tarea.
            bool is_task_running;  // Bandera para indicar si hay una tarea en ejecución.
        };

    } // namespace monitoring
} // namespace performance


#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_SYSTEM_LOG_H
