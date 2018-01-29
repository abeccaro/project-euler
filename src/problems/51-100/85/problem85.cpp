//
// Created by Alex Beccaro on 29/01/18.
//

#include "problem85.hpp"
#include <series/figurate_number.hpp>

using series::figurate_number;

namespace problems {
    uint problem85::solve(uint rectangles) {
        figurate_number<uint> triangulars(3);
        uint result = 0, min_diff = rectangles;

        for (uint b = 1; triangulars[b] < rectangles; b++)
            for (uint h = 0; h <= b; h++) {
                uint rects = triangulars[b] * triangulars[h];
                uint diff = rects < rectangles ? rectangles - rects : rects - rectangles;

                if (diff < min_diff) {
                    min_diff = diff;
                    result = (b+1) * (h+1);
                }

                if (rects > rectangles)
                    break;
            }

        return result;
    }
}