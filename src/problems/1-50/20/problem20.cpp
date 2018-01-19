//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem20.hpp"
#include <generics.hpp>

using generics::digits;
using generics::factorial;

namespace problems {
    uint problem20::solve(uint n) {
        vector<uint> dig = digits(factorial<uint1024_t>(n));

        uint sum = 0;
        for (const auto &d : dig)
            sum += d;
        return sum;
    }
}