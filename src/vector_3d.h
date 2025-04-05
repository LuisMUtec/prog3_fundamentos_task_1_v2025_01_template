//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_VECTOR_3D_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_VECTOR_3D_H

#include<iostream>
using namespace std;

namespace geometry {
    class vector_3d {
        float x,y,z;
    public:
        vector_3d(){};
        vector_3d(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};

        float get_x() const {
            return x;
        }

        float get_y() const {
            return y;
        }

        float get_z() const {
            return z;
        }

        vector_3d operator+(const vector_3d& v2) const;
        vector_3d operator-(const vector_3d& v2) const;
        vector_3d& operator=(const vector_3d& v2);
        friend float dot_product(const vector_3d& v1, const vector_3d& v2);
    };
}





#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_VECTOR_3D_H
