//
// Created by Alex Beccaro on 23/01/2019.
//

#include "problem126.hpp"
#include "vector"
#include "series/figurate_number.hpp"


using std::vector;

using series::figurate_number;


namespace problems {

    uint64_t problem126::solve(uint32_t n) {
        figurate_number<uint32_t> t(3);
        const uint32_t UB = 20 * n;
        vector<uint32_t> counts(UB, 0);

        for (uint32_t a = 1; a < UB; a++)
            for (uint32_t b = 1; b <= a && a * b < UB; b++)
                for (uint32_t c = 1; c <= b; c++) {
                    uint32_t x = 2 * (a * b + a * c + b * c);
                    uint32_t y = 4 * (a + b + c);

                    if (x >= UB)
                        continue;
                    counts[x]++;

                    for (uint32_t i = 3, l = x + y; l < UB; i++) {
                        counts[l]++;

                        l = x + (i - 1) * y + 8 * t[i - 3];
                    }
                }

        for (uint32_t i = 0; i < UB; i++)
            if (counts[i] == n)
                return i;

        return 0; // not found
    }

}