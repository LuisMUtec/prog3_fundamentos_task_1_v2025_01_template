//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_PRODUCT_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_PRODUCT_H

namespace company {
    class product {
        std :: string name;
        double price;
        double weight;
        public:

        //getters
        std :: string get_name() const {
            return name;
        }
        double get_price() const {
            return price;
        }

        double get_weight() const {
            return weight;
        }
        product(const std :: string name, const double price, const double weight);
        friend bool operator ==(const product &p1, const product &p2);
        friend bool operator<(const product &p1, const product &p2);
        friend bool compare_by_value(const product &p1, const product &p2);
    };

    inline bool compare_by_value(const product &p1,const product &p2) {
        return p1.price / p1.weight == p2.price / p2.weight;
    }
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_PRODUCT_H
