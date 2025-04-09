//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "point.h"
using namespace std;
namespace geometry {
    point operator+(const point& lhs, const point& rhs) {
        return point(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    point operator-(const point& lhs, const point& rhs) {
        return point(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    bool operator==(const point& lhs, const point& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    std :: ostream& operator<<(std :: ostream& os, const point& rhs) {
        os << "(" << rhs.x << ", " << rhs.y << ")";
        return os;
    }


}
