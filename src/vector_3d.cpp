//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "vector_3d.h"
using namespace std;

namespace geometry {
    vector_3d vector_3d :: operator+(const vector_3d& v2) const {
        return {this->x + v2.x, this->y+v2.y, this->z+v2.z};
    }

    vector_3d vector_3d :: operator-(const vector_3d& v2) const {
        return {this->x - v2.x, this->y-v2.y, this->z-v2.z};
    }

    vector_3d& vector_3d :: operator=(const vector_3d& v2) {
        this->x = v2.x;
        this->y = v2.y;
        this->z = v2.z;
        return *this;
    }

    float dot_product(const vector_3d& v1, const vector_3d& v2){
        return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
    }
}