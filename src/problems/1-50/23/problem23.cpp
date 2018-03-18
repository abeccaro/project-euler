//
// Created by Alex Beccaro on 17/12/17.
//

#include "problem23.hpp"
#include <vector>
#include <generics.hpp>

using std::vector;
using generics::divisors;

namespace problems {
    uint32_t problem23::solve(uint32_t ub) {
        // get abundants
        vector<uint32_t> abundants;
        for (uint32_t i = 1; i < ub; i++) {
            vector<uint32_t> divs = divisors(i);
            uint32_t sum = 0;
            for (const auto &div : divs)
                sum += div;
            sum -= i;
            if (sum > i)
                abundants.push_back(i);
        }

        // mark all the numbers obtained by summing 2 abundants
        vector<bool> as_sum_of_abundants(ub);
        for (int i = 0; i < abundants.size(); i++)
            for (int j = i; j < abundants.size(); j++) {
                uint32_t sum = abundants[i] + abundants[j];
                if (sum < as_sum_of_abundants.size())
                    as_sum_of_abundants[sum] = true;
            }

        // calculate sum of non marked numbers
        uint32_t result = 0;
        for (int i = 1; i < as_sum_of_abundants.size(); i++)
            if (!as_sum_of_abundants[i])
                result += i;
        return result;
    }
}