//
// Created by Alex Beccaro on 13/09/2022.
//

#include "problem157.hpp"
#include "generics.hpp"

using generics::int_pow;
using generics::combinations;
using generics::divisors;
using generics::divisors_count;
using generics::gcd;
using std::set;
using std::pair;

namespace problems {
    uint32_t problem157::solve(uint32_t n_max) {
        uint64_t result = 0;

        for (uint32_t n = 1; n <= n_max; n++) {
            uint32_t x = int_pow(10u, n);

            auto combs = combinations(divisors(x), 2);
            set<pair<uint32_t, uint32_t>> bases;
            for (auto& c : combs) {
                uint64_t g = gcd(c[0], c[1]);
                sort(c.begin(),  c.end());
                bases.insert({c[0] / g, c[1] / g});
            }
            bases.insert({1, 1});

            for (const auto& pair : bases) {
                uint64_t p = x / pair.first + x / pair.second;
                result += divisors_count(p);
            }
        }

        return result;
    }
}