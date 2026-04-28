//
// Created by Alex Beccaro on 28/04/2026.
//

#include "problem178.hpp"

using num = std::tuple<bool, bool, uint32_t, uint32_t>;
using std::unordered_map;

namespace problems {
    unordered_map<num, uint64_t, tuple_hash<bool, bool, uint32_t, uint32_t>> problem178::mem;

    uint64_t problem178::count(const num& state) {
        if (get<3>(state) == 0) {
            return get<0>(state) && get<1>(state);
        }
        if (mem.contains(state)) {
            return mem[state];
        }

        uint64_t result = 0;
        if (get<2>(state) != 0) {
            result += count({
                get<0>(state) || get<2>(state) == 1,
                get<1>(state),
                get<2>(state) - 1,
                get<3>(state) - 1
            });
        }
        if (get<2>(state) != 9) {
            result += count({
                get<0>(state),
                get<1>(state) || get<2>(state) == 8,
                get<2>(state) + 1,
                get<3>(state) - 1
            });
        }
        mem[state] = result;
        return mem[state];
    }

    uint64_t problem178::solve(uint32_t ub) {
        uint64_t result = 0;

        mem.clear();
        for (uint32_t len = 10; len <= ub; len++) {
            for (uint32_t d = 1; d <= 9; d++) {
                result += count({false, d == 9, d, len - 1});
            }
        }

        return result;
    }
}