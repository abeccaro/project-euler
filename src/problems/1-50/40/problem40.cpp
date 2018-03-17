//
// Created by Alex Beccaro on 05/01/18.
//

#include "problem40.hpp"
#include <generics.hpp>

using generics::digits;

namespace problems {
    uint problem40::solve() {
        std::vector<uint> d;

        for (uint i = 1; d.size() < 1000000; i++) {
            std::vector<uint> digs = digits(i);
            d.insert(d.end(), digs.begin(), digs.end());
        }

        return d[0] * d[9] * d[99] * d[999] * d[9999] * d[99999] * d[999999];
    }
}