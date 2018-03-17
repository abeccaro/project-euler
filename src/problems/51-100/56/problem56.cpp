//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem56.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <generics.hpp>

using boost::multiprecision::uint1024_t;
using generics::digits;

namespace problems {
    uint problem56::solve(uint base_ub, uint exp_ub) {
        uint result = 0;

        for (uint a = 1; a < base_ub; a++) {
            uint1024_t n = 1;
            for (uint b = 1; b < exp_ub; b++) {
                n *= a;
                auto digs = digits(n);

                uint sum = 0;
                for (const auto &d : digs)
                    sum += d;

                if (sum > result)
                    result = sum;
            }
        }

        return result;
    }
}