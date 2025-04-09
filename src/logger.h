//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H


#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>


    namespace file::operations {

        class logger {
        public:
            // Constructor que abre el archivo en modo append.
            explicit logger(const std::string &file_name) {
                log_file.open(file_name, std::ios::out | std::ios::app);
                if (!log_file.is_open()) {
                    throw std::runtime_error("No se pudo abrir el archivo: " + file_name);
                }
            }

            // Destructor que cierra el archivo.
            ~logger() {
                if (log_file.is_open()) {
                    log_file.close();
                }
            }

            // Escribe un mensaje en el log y añade un salto de línea.
            void write(const std::string &message) {
                log_file << message << "\n";
                log_file.flush();
            }

            // Sobrecarga del operador << para insertar mensajes en el log.
            // Se utiliza una función plantilla que admite cualquier tipo que se pueda convertir a cadena.
            template <typename T>
            logger &operator<<(const T &value) {
                std::ostringstream oss;
                oss << value;
                write(oss.str());
                return *this;
            }

        private:
            std::ofstream log_file;  // Archivo de salida para almacenar los logs.
        };

    } // namespace file::operations


#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H
