//
// Created by Alex Beccaro on 05/01/18.
//

#include "problem40.hpp"
#include "generics.hpp"

using std::vector;
using generics::digits;

namespace problems {
    uint32_t problem40::solve() {
        vector<uint32_t> d;

        for (uint32_t i = 1; d.size() < 1000000; i++) {
            vector<uint32_t> digs = digits(i);
            d.insert(d.end(), digs.begin(), digs.end());
        }

        return d[0] * d[9] * d[99] * d[999] * d[9999] * d[99999] * d[999999];
    }
}