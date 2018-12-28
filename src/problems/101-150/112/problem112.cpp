//
// Created by Alex Beccaro on 27/12/18.
//

#include "problem112.hpp"
#include <generics.hpp>

using generics::digits;

namespace problems {
    bool problem112::is_bouncy(uint32_t n) {
        bool increasing = false, decreasing = false;
        std::vector<uint32_t> digs = digits(n);

        for (uint32_t i = 1; i < digs.size(); i++) {
            if (digs[i-1] < digs[i]) {
                increasing = true;
                if (decreasing)
                    return true;
            } else if (digs[i-1] > digs[i]) {
                decreasing = true;
                if (increasing)
                    return true;
            }
        }

        return false;
    }

    uint32_t problem112::solve(double percentage) {
        double bouncy = 0;
        for (uint32_t i = 100; ; i++) {
            if (is_bouncy(i))
                bouncy++;

            if (bouncy / i >= percentage)
                return i;
        }
    }
}