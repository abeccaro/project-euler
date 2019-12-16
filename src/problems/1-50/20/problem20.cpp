//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem20.hpp"
#include <generics.hpp>

using std::vector;
using boost::multiprecision::uint1024_t;
using generics::digits;
using generics::factorial;

namespace problems {
    uint32_t problem20::solve(uint32_t n) {
        vector<uint32_t> dig = digits(factorial<uint1024_t>(n));

        uint32_t sum = 0;
        for (const auto &d : dig)
            sum += d;
        return sum;
    }
}