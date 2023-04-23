//
// Created by Alex Beccaro on 29/01/18.
//

#include "problem85.hpp"
#include "series/figurate_number.hpp"

using series::figurate_number;

namespace problems {
    uint32_t problem85::solve(uint32_t rectangles) {
        figurate_number<uint32_t> triangulars(3);
        uint32_t result = 0, min_diff = rectangles;

        for (uint32_t b = 1; triangulars[b] < rectangles; b++)
            for (uint32_t h = 0; h <= b; h++) {
                uint32_t rects = triangulars[b] * triangulars[h];
                uint32_t diff = rects < rectangles ? rectangles - rects : rects - rectangles;

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