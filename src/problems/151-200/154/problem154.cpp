//
// Created by Alex Beccaro on 02/09/2022.
//

#include "problem154.hpp"
#include <cmath>

using std::vector;
using std::pair;


namespace problems {
    uint32_t problem154::prime_multiplicity(uint32_t n, uint32_t p) {
        uint32_t res = 0;
        while (n % p == 0) {
            n /= p;
            res++;
        }
        return res;
    }

    vector<pair<uint32_t, uint32_t>> problem154::factorial_multiplicity_2_5(uint32_t n) {
        vector<pair<uint32_t, uint32_t>> result;
        result.reserve(n + 1);

        result.emplace_back(0, 0);
        result.emplace_back(0, 0);

        for (uint32_t i = 2, two = 0, five = 0; i <= n; i++) {
            two += prime_multiplicity(i, 2);
            five += prime_multiplicity(i, 5);
            result.emplace_back(two, five);
        }

        return result;
    }

    uint32_t problem154::solve(uint32_t n, uint32_t exp) {
        uint32_t result = 0;

        auto v = factorial_multiplicity_2_5(n);

        for (uint32_t i = 0; i <= v.size() / 3; i++) {
            uint32_t remaining_two = v.back().first - v[i].first;
            uint32_t remaining_five = v.back().second - v[i].second;

            uint32_t j_end = ceil((n - i) / 2);
            for (uint32_t j = i; j <= j_end; j++) {
                uint32_t k = n - i - j;
                if (remaining_five - v[j].second - v[k].second >= exp && remaining_two - v[j].first - v[k].first >= exp) {
                    uint32_t factor = (i == k) ? 1 : ((i == j || j == k) ? 3 : 6);
                    result += factor;
                }
            }
        }

        return result;
    }
}