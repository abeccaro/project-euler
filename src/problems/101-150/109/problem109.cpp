//
// Created by Alex Beccaro on 27/12/18.
//

#include <vector>
#include "problem109.hpp"
#include "generics.hpp"

using std::vector;
using generics::combinations;

namespace problems {
    uint32_t problem109::solve(uint32_t ub) {
        vector<uint32_t> all;
        for (uint32_t i = 1; i <= 20; i++) {
            all.push_back(i);
            all.push_back(i * 2);
            all.push_back(i * 3);
        }
        all.push_back(25);
        all.push_back(50);

        vector<uint32_t> combs, doubles;
        for (const auto& c : combinations(all, 2))
            combs.push_back(c[0] + c[1]);
        for (const auto& n : all)
            doubles.push_back(2 * n);

        all.push_back(0); // 2 misses
        all.insert(all.end(), doubles.begin(), doubles.end()); // 2 same hit
        all.insert(all.end(), combs.begin(), combs.end()); // 2 different hits

        uint32_t sol = 0;

        // 1 miss 1 hit
        for (const auto& score : all) {
            int diff = (int) ub - (int) score;

            if (diff > 0) {
                sol += (std::min<int>(diff - 1, 40)) / 2;
                if (diff > 50)
                    sol++;
            }
        }

        return sol;
    }
}