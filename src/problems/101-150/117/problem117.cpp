//
// Created by Alex Beccaro on 07/01/2019.
//

#include "problem117.hpp"


using std::vector;


namespace problems {

    uint64_t problem117::fill_combinations(uint32_t l, uint32_t min_size, uint32_t max_size,
            const vector<uint64_t>& mem) {
        if (l < min_size)
            return 1;

        uint64_t res = mem[l - 1]; // black square

        uint32_t ub = std::min(max_size, l);
        for (uint32_t i = min_size; i <= ub; i++)
            res += mem[l - i];

        return res;
    }

    uint64_t problem117::solve(uint32_t length) {
        vector<uint64_t> combs(length + 1, 0);

        for (uint32_t i = 0; i <= length; i++)
            combs[i] = fill_combinations(i, 2, 4, combs);

        return combs[length];
    }

}