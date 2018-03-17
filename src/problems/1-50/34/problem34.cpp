//
// Created by Alex Beccaro on 19/12/17.
//

#include "problem34.hpp"
#include <generics.hpp>

using generics::factorial;
using generics::digits;

namespace problems {
    uint problem34::solve() {
        const uint UPPER_BOUND = 1499999;

        uint result = 0;
        std::vector<uint> factorials(10);

        for (uint i = 0; i < 10; i++)
            factorials[i] = factorial(i);

        for (uint i = 10; i < UPPER_BOUND; i++) {
            uint sum = 0;
            std::vector<uint> digs = digits(i);

            for (const auto &digit : digs)
                sum += factorials[digit];

            if (sum == i)
                result += i;
        }

        return result;
    }
}