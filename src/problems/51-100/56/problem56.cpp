//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem56.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using boost::multiprecision::uint1024_t;
using generics::digits;

namespace problems {
    uint32_t problem56::solve(uint32_t base_ub, uint32_t exp_ub) {
        uint32_t result = 0;

        for (uint32_t a = 1; a < base_ub; a++) {
            uint1024_t n = 1;
            for (uint32_t b = 1; b < exp_ub; b++) {
                n *= a;
                auto digs = digits(n);

                uint32_t sum = 0;
                for (const auto &d : digs)
                    sum += d;

                if (sum > result)
                    result = sum;
            }
        }

        return result;
    }
}