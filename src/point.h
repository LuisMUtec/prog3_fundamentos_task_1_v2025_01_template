//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_POINT_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_POINT_H

namespace geometry {
    class point {
        int x;
        int y;
        public:
        point (int _x, int _y) : x(_x), y(_y) {}
        int get_x() const {return x;}
        int get_y() const {return y;}
        friend point operator+(const point& lhs, const point& rhs);
        friend point operator-(const point& lhs, const point& rhs);
        friend bool operator==(const point& lhs, const point& rhs);
        friend std :: ostream& operator<<(std :: ostream& os, const point& rhs);
    };
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_POINT_H
