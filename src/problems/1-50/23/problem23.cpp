//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem23.hpp"
#include <vector>
#include <generics.hpp>

using generics::divisors;

namespace problems {
    uint problem23::solve(uint ub) {
        // get abundants
        std::vector<uint> abundants;
        for (uint i = 1; i < ub; i++) {
            std::vector<uint> divs = divisors(i);
            uint sum = 0;
            for (const auto &div : divs)
                sum += div;
            sum -= i;
            if (sum > i)
                abundants.push_back(i);
        }

        // mark all the numbers obtained by summing 2 abundants
        std::vector<bool> as_sum_of_abundants(ub);
        for (int i = 0; i < abundants.size(); i++)
            for (int j = i; j < abundants.size(); j++) {
                uint sum = abundants[i] + abundants[j];
                if (sum < as_sum_of_abundants.size())
                    as_sum_of_abundants[sum] = true;
            }

        // calculate sum of non marked numbers
        uint result = 0;
        for (int i = 1; i < as_sum_of_abundants.size(); i++)
            if (!as_sum_of_abundants[i])
                result += i;
        return result;
    }
}