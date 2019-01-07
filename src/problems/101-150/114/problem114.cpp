//
// Created by Alex Beccaro on 07/01/2019.
//

#include "problem114.hpp"


using std::vector;


namespace problems {

    uint64_t problem114::fill_combinations(uint32_t l, const vector<uint64_t>& mem) {
        uint64_t res = mem[l - 1]; // black square

        for (uint32_t size = 3; size < l; size++)
            res += mem[l - size - 1]; // block of size "size" and a black block

        if (l > 2)
            res++; // block of size l

        return res;
    }

    uint64_t problem114::solve(uint32_t length) {
        vector<uint64_t> combs(length + 1, 0);

        for (uint32_t i = 0; i <= length; i++)
            combs[i] = i < 3 ? 1 : fill_combinations(i, combs);

        return combs[length];
    }

}