//
// Created by Alex Beccaro on 28/12/18.
//

#include "problem113.hpp"
#include <vector>
#include <generics.hpp>


using std::vector;
using boost::multiprecision::uint128_t;

using generics::binomial_coefficient;


namespace problems {

    uint64_t problem113::solve(uint32_t ub) {
        vector<uint64_t> a(11);
        uint64_t increasing = 0, decreasing = 0; // increasing + flats, decreasing + flats

        // getting coefficients
        for (uint32_t k = 1; k <= a.size(); k++)
            a[k - 1] = ub < k ? 0 : (uint64_t) binomial_coefficient<uint128_t>(ub - 1, k - 1);

        // calculating increasing
        for (uint32_t i = 1; i <= 10; i++)
            increasing += a[i-1] * binomial_coefficient<uint32_t>(10, i);

        // calculating decreasing
        for (uint32_t i = 1; i <= 11; i++)
            decreasing += a[i-1] * binomial_coefficient<uint32_t>(11, i);

        // duplicates (flats) and 0s
        uint64_t dups = 10 * ub + 2;

        return increasing + decreasing - dups;
    }
}