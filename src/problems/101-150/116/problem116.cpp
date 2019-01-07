//
// Created by Alex Beccaro on 07/01/2019.
//

#include "problem116.hpp"


using std::vector;


namespace problems {

    uint64_t problem116::fill_combinations(uint32_t l, uint32_t size, const vector<uint64_t>& mem) {
        if (l < size)
            return 1;

        return mem[l - 1] + mem[l - size];
    }

    uint64_t problem116::solve(uint32_t length) {
        vector<vector<uint64_t>> combs(3, {1});

        for (uint32_t l = 1; l <= length; l++)
            for (uint32_t i = 0; i < combs.size(); i++)
                combs[i].push_back(fill_combinations(l, i + 2, combs[i]));

        // sum of results minus all black squares combinations
        return combs[0][length] + combs[1][length] + combs[2][length] - 3;
    }

}