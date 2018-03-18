//
// Created by Alex Beccaro on 09/01/18.
//

#include "problem52.hpp"
#include <generics.hpp>

using generics::digits;

namespace problems {
    uint32_t problem52::solve(uint32_t multiples) {
        for (uint32_t i = 1; true; i++) {
            auto digs = digits(i);
            sort(digs.begin(), digs.end());
            bool ok = true;

            for (uint32_t j = 2; j <= multiples; j++) {
                auto multiple_digs = digits(i * j);
                sort(multiple_digs.begin(), multiple_digs.end());

                if (digs != multiple_digs) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return i;
        }
    }
}