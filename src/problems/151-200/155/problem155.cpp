//
// Created by Alex Beccaro on 04/09/2022.
//

#include "problem155.hpp"
#include "fraction.hpp"
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;
using fractions::fraction;


namespace problems {
    uint32_t problem155::solve(uint32_t n) {
        vector<vector<fraction<uint32_t>>> circuits(n);
        unordered_set<fraction<uint32_t>> solutions;

        circuits[0].push_back(1);
        solutions.insert(1);
        for (uint32_t i = 2; i <= n; i++) {
            for (uint32_t j = 1; j <= i/2; j++) {
                for (const auto& c1 : circuits[j - 1]) {
                    for (const auto& c2 : circuits[i - j - 1]) {
                        fraction<uint32_t> parallel = c1 + c2;
                        parallel.reduce();
                        if (parallel.numerator() > parallel.denominator())
                            parallel.invert();
                        auto inserted = solutions.insert(parallel);
                        if (inserted.second) {
                            circuits[i - 1].push_back(parallel);
                            circuits[i - 1].push_back(parallel.inverse());
                        }
                    }
                }
            }
        }

        return solutions.size() * 2 - 1; // -1 for 1/1
    }
}