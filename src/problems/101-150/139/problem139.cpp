//
// Created by Alex Beccaro on 08/12/2019.
//

#include "problem139.hpp"
#include "cmath"


namespace problems {

    uint64_t problem139::solve(uint64_t ub) {
        uint64_t res = 0;
        uint64_t m = 2, n = 1;

        while (m < sqrt(ub / 2)) {
            uint64_t sum = 2 * m * (m + n);
            for (uint64_t perim = sum; perim < ub; perim += sum)
                res++;

            uint64_t m_new = 2 * m + n;
            n = m;
            m = m_new;
        }

        return res;
    }

}