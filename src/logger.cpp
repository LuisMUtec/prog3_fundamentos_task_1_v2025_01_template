//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "logger.h"

namespace file :: operations {
    logger::logger(const std::string &filename) {
        out.open(filename);
        if (!out) throw std::runtime_error("No se pudo abrir el archivo " + filename);
    }

    logger::~logger() {
        if (out.is_open()) out.close();
    }

    logger& logger::operator<< (const std :: string& str) {
        if (out.is_open()) out << str;
        return *this;
    }

    void logger :: write(const std :: string& str) {
        if (out.is_open()) out << str;
    }

}

using namespace std;

