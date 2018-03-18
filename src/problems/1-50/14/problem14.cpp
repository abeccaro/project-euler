//
// Created by Alex Beccaro on 16/12/17.
//

#include "problem14.hpp"

using std::vector;

namespace problems {
    uint32_t problem14::collatz_length(uint32_t n, vector<uint32_t>& memory) {
        if (n == 1)
            return 1;

        if (memory.size() > n && memory[n] != 0)
            return memory[n];

        uint32_t l = 1 + collatz_length(n % 2 == 0 ? n / 2 : 3 * n + 1, memory);
        if (memory.size() > n)
            memory[n] = l;
        return l;
    }

    uint32_t problem14::solve(uint32_t ub) {
        uint32_t max_length = 0;
        uint32_t max_length_start = 0;
        vector<uint32_t> memory(ub);

        for (uint32_t i = 1; i < ub; i += 2) {
            uint32_t length = collatz_length(i, memory);
            if (length > max_length) {
                max_length = length;
                max_length_start = i;
            }
        }
        return max_length_start;
    }
}