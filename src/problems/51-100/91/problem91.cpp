//
// Created by Alex Beccaro on 28/02/18.
//

#include "problem91.hpp"

namespace problems {
    bool problem91::has_right_angle(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) {
        // check right angle in origin
        if (y2 == 0 && x1 == 0)
            return true;

        // cross product
        int dx = x1 - x2;
        int dy = y1 - y2;
        if (dx * x2 + dy * y2 == 0)
            return true;
        if (dx * x1 + dy * y1 == 0)
            return true;

        return false;
    }

    uint32_t problem91::solve(uint32_t max_x, uint32_t max_y) {
        uint32_t result = 0;

        for (uint32_t x1 = 0; x1 <= max_x; x1++)
            for (uint32_t y1 = 0; y1 <= max_y; y1++) {
                if (x1 == 0 && y1 == 0)
                    continue;

                for (uint32_t x2 = x1; x2 <= max_x; x2++)
                    for (uint32_t y2 = x2 == x1 ? y1 + 1 : 0; y2 <= max_y; y2++)
                        if (has_right_angle(x1, y1, x2, y2))
                            ++result;
            }

        return result;
    }
}