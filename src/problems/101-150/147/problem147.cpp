//
// Created by Alex Beccaro on 08/12/2020.
//

#include "problem147.hpp"


namespace problems {

    uint32_t problem147::solve(uint32_t x, uint32_t y) {
        uint32_t res = 0;

        if (x < y) {
            uint32_t tmp = x;
            x = y;
            y = tmp;
        }

        for (uint32_t w = 1; w <= x; w++) {
            uint32_t w2 = w * w;
            for (uint32_t h = 1; h <= w && h <= y; h++) {
                uint32_t h2 = h * h, h3 = h2 * h, h4 = h3 * h;

                // formula found by solving linear system with some examples (similar to Bibitono's comment on thread)
                uint32_t count = (3*w2*h2 + 16*w*h3 - 8*h4 + 3*w2*h + 3*w*h2 - 1*w*h + 2*h2 - 6*h) / 12;

                res += count;
                if (h != w && h <= x && w <= y)
                    res += count;
            }
        }

        return res;
    }

}