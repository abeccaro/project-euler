//
// Created by Alex Beccaro on 19/12/17.
//

#include "problem34.hpp"
#include "generics.hpp"

using std::vector;
using generics::factorial;
using generics::digits;

namespace problems {
    uint32_t problem34::solve() {
        const uint32_t ub = 1499999;

        uint32_t result = 0;
        vector<uint32_t> factorials(10);

        for (uint32_t i = 0; i < 10; i++)
            factorials[i] = factorial(i);

        for (uint32_t i = 10; i < ub; i++) {
            uint32_t sum = 0;
            vector<uint32_t> digs = digits(i);

            for (const auto &digit : digs)
                sum += factorials[digit];

            if (sum == i)
                result += i;
        }

        return result;
    }
}