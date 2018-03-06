//
// Created by Alex Beccaro on 02/03/18.
//

#include "problem94.hpp"

using ulong = unsigned long;

namespace problems {
    uint problem94::solve(uint ub) {
        uint result = 0;

        ulong u = 1;
        ulong v = 2;
        ulong p = 4;

        for (int i = 1; ; i = -i) {
            ulong temp = 2 * u + v + i;

            v = 3 * u + 2 * v + i;
            u = temp;
            p = 3 * u + i;

            if (p > ub)
                break;

            ulong num = v * (u + i);
            if (num % 4 == 0)
                result += p;
        }

        return result;
    }
}