//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include "product.h"
namespace company {
    product :: product(const std :: string name, const double price, const double weight) : name(name), price(price), weight(weight) {}

    bool operator ==(const product &p1,const product &p2) {
        return p1.price == p2.price && p1.weight == p2.weight;
    }

    bool operator <(const product &p1,const product &p2) {
        if (p1.price == p2.price) return p1.weight < p2.weight;
        return p1.price < p2.price;
    }

}
