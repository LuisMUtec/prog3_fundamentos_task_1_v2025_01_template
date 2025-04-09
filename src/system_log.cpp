//
// Created by rudri on 10/11/2020.
//

#include "system_log.h"
#include <stdexcept>

namespace performance {
    namespace monitoring {

        system_log::system_log(const std::string& file_path) : is_task_running(false) {
            // Abrir el archivo en modo "append" para conservar registros anteriores
            output_file.open(file_path, std::ios::out | std::ios::app);
            if (!output_file.is_open()) {
                throw std::runtime_error("No se pudo abrir el archivo de log: " + file_path);
            }
        }

        system_log::~system_log() {
            if (output_file.is_open()) {
                output_file.close();
            }
        }

        void system_log::start(const std::string& message) {
            // Se guarda el mensaje y se registra el instante de inicio de la tarea.
            current_start_message = message;
            start_time = std::chrono::high_resolution_clock::now();
            is_task_running = true;
        }

        void system_log::stop(const std::string& message) {
            if (!is_task_running) {
                throw std::logic_error("Se llamó a stop sin haber iniciado previamente una tarea.");
            }

            // Se captura el instante de finalización de la tarea.
            auto stop_time = std::chrono::high_resolution_clock::now();

            // (Opcional) Se puede calcular la duración de la tarea:
            // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_time - start_time).count();

            // Se escribe en el archivo el mensaje de inicio y el mensaje de fin separados por una coma.
            output_file << current_start_message << "," << message << "\n";
            output_file.flush();

            is_task_running = false;
        }

    } // namespace monitoring
} // namespace performance





