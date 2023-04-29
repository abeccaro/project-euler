//
// Created by Alex Beccaro on 29/04/2023.
//

#include "problem163.hpp"
#include "vector"


using std::vector;
using series::figurate_number;

namespace problems {
    figurate_number<uint32_t> problem163::triangular(3);

    vector<uint32_t> problem163::coefficients = {
            18, 58, 39, 40, 42, 46, 33, 52, 36, 46, 33, 58, 24, 52, 45, 34, 42, 52, 27, 58,
            30, 46, 39, 52, 30, 46, 45, 40, 36, 58, 21, 58, 36, 40, 45, 46, 30, 52, 39, 46,
            30, 58, 27, 52, 42, 34, 45, 52, 24, 58, 33, 46, 36, 52, 33, 46, 42, 40, 39, 58
    };

    uint32_t problem163::solve(uint32_t n) {
        uint32_t res = 0;

        for (uint32_t i = 0; i < n; i++)
            res += coefficients[i % coefficients.size()] * triangular[n - i - 1];

        // offset the coefficients for n and n-1
        if (n > 0) {
            res -= 2 * triangular[n - 1];
            if (n > 1)
                res -= 2 * triangular[n - 2];
        }

        return res;
    }
}