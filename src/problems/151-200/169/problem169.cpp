//
// Created by Alex Beccaro on 08/05/2023.
//

#include "problem169.hpp"


using boost::multiprecision::uint128_t;
using std::unordered_map;

namespace problems {
    unordered_map<uint128_t, uint64_t> problem169::mem;

    /* f(n) follows the following recurrence:
     *
     * f(n) = f((n-1)/2)                if n is odd
     * f(n) = f(n/2) + f((n-2)/2)       if n is even
     */
    uint64_t problem169::f(const uint128_t& n) {
        if (n == 0)
            return 1;

        if (mem.contains(n))
            return mem[n];

        mem[n] = n % 2 == 0 ? f(n / 2) + f((n - 2) / 2) : f((n - 1) / 2);
        return mem[n];
    }

    uint64_t problem169::solve(const uint128_t& n) {
        mem = {};
        return f(n);
    }
}