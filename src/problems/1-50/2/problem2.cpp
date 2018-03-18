//
// Created by Alex Beccaro on 11/12/17.
//

#include "problem2.hpp"
#include "series/fibonacci.hpp"

using series::fibonacci;

namespace problems {
    uint32_t problem2::solve(uint32_t ub) {
        fibonacci<uint32_t> fib;

        uint32_t sum = 0;
        for (auto f = fib.begin(); *f <= ub; f++)
            if (*f % 2 == 0)
                sum += *f;

        return sum;
    }
}