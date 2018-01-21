//
// Created by Alex Beccaro on 16/12/17.
//

#include "problem14.hpp"

namespace problems {
    uint problem14::collatz_length(uint n, vector<uint> &memory) {
        if (n == 1)
            return 1;

        if (memory.size() > n && memory[n] != 0)
            return memory[n];

        uint l = 1 + collatz_length(n % 2 == 0 ? n / 2 : 3 * n + 1, memory);
        if (memory.size() > n)
            memory[n] = l;
        return l;
    }

    uint problem14::solve(uint ub) {
        uint max_length = 0;
        uint max_length_start = 0;
        vector<uint> memory(ub);

        for (uint i = 1; i < ub; i += 2) {
            uint length = collatz_length(i, memory);
            if (length > max_length) {
                max_length = length;
                max_length_start = i;
            }
        }
        return max_length_start;
    }
}