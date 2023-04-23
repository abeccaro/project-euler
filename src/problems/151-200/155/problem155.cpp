//
// Created by Alex Beccaro on 04/09/2022.
//

#include "problem155.hpp"
#include "fraction.hpp"
#include "vector"
#include "unordered_set"

using std::vector;
using std::unordered_set;
using fractions::fraction;


namespace problems {
    // Could probably be more efficient if instead of storing and looking up for whole fractions we use a bi-dimensional
    // array or a map num => dens so that lookup is faster
    uint32_t problem155::solve(uint32_t n) {
        vector<vector<fraction<uint32_t>>> circuits(n);
        unordered_set<fraction<uint32_t>> solutions;
        fraction<uint32_t>::auto_reduce(true);

        circuits[0].emplace_back(1);
        solutions.insert(1);
        for (uint32_t i = 2; i <= n; i++) {
            for (uint32_t j = 1; j <= i/2; j++) {
                for (const auto& c1 : circuits[j - 1]) {
                    for (const auto& c2 : circuits[i - j - 1]) {
                        fraction<uint32_t> sum = c1 + c2;
                        if (sum.numerator() > sum.denominator())
                            sum.invert();
                        auto inserted = solutions.insert(sum);
                        if (inserted.second) {
                            circuits[i - 1].push_back(sum);
                            circuits[i - 1].push_back(sum.inverse());
                        }
                    }
                }
            }
        }

        fraction<uint32_t>::auto_reduce(false);
        return solutions.size() * 2 - 1; // -1 cause the inverse of 1/1 is still 1/1
    }
}