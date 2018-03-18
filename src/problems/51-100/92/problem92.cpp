//
// Created by Alex Beccaro on 01/03/18.
//

#include "problem92.hpp"

using std::vector;

namespace problems {
    bool problem92::chains_to_89(uint32_t n, vector<uint32_t>& mem) {
        if (mem[n-1] == 89)
            return true;

        if (mem[n-1] == 1)
            return false;

        uint32_t sum = 0;
        uint32_t copy = n;
        while (copy != 0) {
            uint32_t d = copy % 10;
            sum += d * d;
            copy /= 10;
        }

        bool result = chains_to_89(sum, mem);
        mem[n-1] = result ? 89 : 1;
        return result;
    }

    uint32_t problem92::solve(uint32_t ub) {
        uint32_t result = 0;
        vector<uint32_t> mem(ub - 1);
        mem[0] = 1;
        mem[88] = 89;

        for (uint32_t i = 1; i < ub; i++)
            if (chains_to_89(i, mem))
                result++;

        return result;
    }
}