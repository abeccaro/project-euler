//
// Created by Alex Beccaro on 01/03/18.
//

#include "problem92.hpp"

namespace problems {
    bool problem92::chains_to_89(uint n, vector<uint>& mem) {
        if (mem[n-1] == 89)
            return true;

        if (mem[n-1] == 1)
            return false;

        uint sum = 0;
        uint copy = n;
        while (copy != 0) {
            uint d = copy % 10;
            sum += d * d;
            copy /= 10;
        }

        bool result = chains_to_89(sum, mem);
        mem[n-1] = result ? 89 : 1;
        return result;
    }

    uint problem92::solve(uint ub) {
        uint result = 0;
        vector<uint> mem(ub - 1);
        mem[0] = 1;
        mem[88] = 89;

        for (uint i = 1; i < ub; i++)
            if (chains_to_89(i, mem))
                result++;

        return result;
    }
}