//
// Created by Alex Beccaro on 11/12/17.
//

#include <vector>
#include "problem2.hpp"
#include "series/fibonacci.hpp"

using series::fibonacci;
using std::vector;

namespace problems {
    /**
     * Specifies values, solves problem and outputs solution and calculation time.
     * @return The exit code
     */
    uint problem2::solve(uint ub) {
        fibonacci<uint> fib;

        uint sum = 0;
        for (const auto &f : fib) {
            if (f > ub)
                break;
            if (f % 2 == 0)
                sum += f;
        }

        return sum;
    }
}