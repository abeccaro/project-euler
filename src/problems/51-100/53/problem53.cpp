//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem53.hpp"
#include <generics.hpp>

using generics::binomial_coefficient;
using boost::multiprecision::cpp_int;

using numtype = cpp_int;

namespace problems {
    uint problem53::solve(uint max_n) {
        const numtype THRESHOLD = 1000000;

        uint result = 0;

        for (numtype n = 1; n <= max_n; n++)
            for (numtype r = 1; r <= n; r++)
                if (binomial_coefficient(n, r) > THRESHOLD)
                    result++;

        return result;
    }
}