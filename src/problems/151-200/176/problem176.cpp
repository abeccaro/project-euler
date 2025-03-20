//
// Created by Alex Beccaro on 19/03/2025.
//

#include "problem176.hpp"
#include "generics.hpp"
#include "series/primes.hpp"
#include "ranges"

using generics::int_pow;
using primes::prime_factors_multeplicity;
using std::ranges::reverse_view;

namespace problems {
    uint64_t problem176::solve(uint64_t n) {
        series::primes<uint64_t> ps;

        auto factors = prime_factors_multeplicity<uint64_t>(2 * n + 1);

        uint64_t l = 2;
        uint64_t p = 0;
        for (const auto& factor : reverse_view(factors)) {
            for (uint64_t i = 0; i < factor.second; i++) {
                l *= int_pow(ps[p++], (factor.first - 1) / 2);
            }
        }

        return l;
    }
}