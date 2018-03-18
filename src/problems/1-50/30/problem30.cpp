//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem30.hpp"
#include <cmath>
#include <generics.hpp>

using std::vector;
using generics::digits;

namespace problems {
    uint32_t problem30::solve(uint32_t exponent) {
        uint32_t upper_bound_exp = 1;
        while (upper_bound_exp * pow(9, exponent) > pow(10, upper_bound_exp))
            upper_bound_exp++;
        auto upper_bound = (uint32_t) pow(9, upper_bound_exp);

        uint32_t result = 0;
        for (uint32_t i = 10; i < upper_bound; i++) {
            vector<uint32_t> digs = digits(i);
            uint32_t sum = 0;

            for (const auto &d : digs)
                sum += (uint32_t) pow(d, exponent);

            if (sum == i)
                result += i;
        }
        return result;
    }
}