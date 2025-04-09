//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H

#include <fstream>
#include <string>
#include <iostream>

namespace file :: operations {
    class logger {
        std :: ofstream out;
    public:
        logger(const std :: string& filename);

        ~logger();

        logger& operator<< (const std :: string& str);

        void write(const std :: string& str);

    };
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H
