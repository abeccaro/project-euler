//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem16.hpp"
#include <generics.hpp>

using boost::multiprecision::uint1024_t;
using generics::digits;

namespace problems {
    uint problem16::solve(uint exp) {
        std::vector<unsigned int> dig = digits(pow((uint1024_t) 2, exp));

        uint sum = 0;
        for (const auto &n : dig)
            sum += n;
        return sum;
    }
}