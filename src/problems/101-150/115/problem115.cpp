//
// Created by Alex Beccaro on 07/01/2019.
//

#include "problem115.hpp"


using std::vector;


namespace problems {

    uint64_t problem115::fill_combinations(uint32_t l, uint32_t m, vector<uint64_t>& mem) {
        if (l < m)
            return 1;

        uint64_t res = mem[l - 1]; // black square

        for (uint32_t size = m; size < l; size++)
            res += mem[l - size - 1]; // block of size "size" and a black block

        if (l >= m)
            res++; // block of size l

        return res;
    }

    uint64_t problem115::solve(uint32_t size, uint64_t ub) {
        vector<uint64_t> combs(1, 1);

        for (uint32_t l = 1; combs.back() <= ub; l++)
            combs.push_back(fill_combinations(l, size, combs));

        return combs.size() - 1;
    }

}