//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem16.hpp"
#include <generics.hpp>

using std::vector;
using boost::multiprecision::uint1024_t;
using generics::digits;

namespace problems {
    uint32_t problem16::solve(uint32_t exp) {
        vector<uint32_t> dig = digits(pow((uint1024_t) 2, exp));

        uint32_t sum = 0;
        for (const auto &n : dig)
            sum += n;
        return sum;
    }
}