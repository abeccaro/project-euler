//
// Created by Alex Beccaro on 22/01/2019.
//

#include "problem124.hpp"
#include "vector"
#include "primes.hpp"


using std::vector;
using std::sort;
using rad_pair = std::pair<uint32_t, uint32_t>;

using primes::prime_factors;



namespace problems {

    uint32_t problem124::solve(uint32_t n, uint32_t k) {
        vector<rad_pair> v(n);
        v[0] = {1, 1};

        for (uint32_t i = 2; i <= n; i++) {
            uint32_t rad = 1;

            for (const auto& p : prime_factors(i))
                rad *= p;

            v[i - 1] = {i, rad};
        }

        sort(v.begin(), v.end(), [](const rad_pair& p1, const rad_pair& p2) {
            if (p1.second == p2.second)
                return p1.first < p2.first;

            return p1.second < p2.second;
        });

        return v[k - 1].first;
    }

}