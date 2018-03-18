//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem78.hpp"

using std::vector;

namespace problems {
    int64_t problem78::partitions(uint32_t n, vector<int32_t>& memory, vector<uint32_t>& p) {
        int64_t sum = 0;
        int32_t sign = 1;

        for (uint32_t k = 1; p[k-1] <= n; k += 2) {
            int32_t i1 = n - p[k-1];
            if (i1 >= 0)
                sum += sign * memory[i1];

            if (p[k] <= n) {
                int32_t i2 = n - p[k];
                if (i2 >= 0)
                    sum += sign * memory[i2];
            }

            sign = -sign;
        }

        return sum;
    }

    uint32_t problem78::solve(uint32_t n) {
        vector<int32_t> memory(2, 1);

        vector<uint32_t> gen_pentagons;
        for (uint32_t i = 1; i == 1 || gen_pentagons.back() <= n; i++) {
            gen_pentagons.push_back((3 * i * i - i) / 2);
            gen_pentagons.push_back((3 * i * i + i) / 2);
        }

        for (uint32_t i = 2; ; i++) {
            memory.push_back(partitions(i, memory, gen_pentagons) % n);
            if (memory[i] == 0)
                return i;
        }
    }
}