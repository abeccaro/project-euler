//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem30.hpp"
#include <cmath>
#include <generics.hpp>

using generics::digits;

namespace problems {
    uint problem30::solve(uint exponent) {
        uint upper_bound_exp = 1;
        while (upper_bound_exp * pow(9, exponent) > pow(10, upper_bound_exp))
            upper_bound_exp++;
        auto upper_bound = (uint) pow(9, upper_bound_exp);

        uint result = 0;
        for (uint i = 10; i < upper_bound; i++) {
            vector<uint> digs = digits(i);
            uint sum = 0;

            for (const auto &d : digs)
                sum += (uint) pow(d, exponent);

            if (sum == i)
                result += i;
        }
        return result;
    }
}