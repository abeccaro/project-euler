//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem78.hpp"

namespace problems {
    long problem78::partitions(uint n, vector<int>& memory, vector<uint>& p) {
        long sum = 0;
        int sign = 1;

        for (uint k = 1; p[k-1] <= n; k += 2) {
            int i1 = n - p[k-1];
            if (i1 >= 0)
                sum += sign * memory[i1];

            if (p[k] <= n) {
                int i2 = n - p[k];
                if (i2 >= 0)
                    sum += sign * memory[i2];
            }

            sign = -sign;
        }

        return sum;
    }

    uint problem78::solve(uint n) {
        vector<int> memory(2, 1);

        vector<uint> gen_pentagons;
        for (uint i = 1; i == 1 || gen_pentagons.back() <= n; i++) {
            gen_pentagons.push_back((3 * i * i - i) / 2);
            gen_pentagons.push_back((3 * i * i + i) / 2);
        }

        for (uint i = 2; ; i++) {
            memory.push_back(partitions(i, memory, gen_pentagons) % n);
            if (memory[i] == 0)
                return i;
        }
    }
}