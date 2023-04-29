//
// Created by Alex Beccaro on 29/04/2023.
//

#include "problem164.hpp"


using std::pair;
using std::unordered_map;

namespace problems {
    unordered_map<pair<pair<uint32_t, uint32_t>, uint32_t>, uint64_t, pair_hash<pair<uint32_t, uint32_t>, uint32_t>> problem164::mem;

    uint64_t problem164::count(const pair<uint32_t, uint32_t>& last_pair, uint32_t remaining) {
        pair<pair<uint32_t, uint32_t>, uint32_t> key(last_pair, remaining);

        if (mem.contains(key))
            return mem[key];

        uint64_t result = 0;
        if (remaining == 1)
            result = 9 - last_pair.first - last_pair.second + 1;
        else {
            for (uint32_t i = 0; i <= 9 - last_pair.first - last_pair.second; i++)
                result += count({last_pair.second, i}, remaining - 1);
        }

        mem[key] = result;
        return result;
    }

    uint64_t problem164::solve() {
        mem = {};
        uint64_t result = 0;

        for (uint32_t i = 1; i < 10; i++) {
            for (uint32_t j = 0; j + i < 10; j++)
                    result += count({i, j}, 18);
        }

        return result;
    }
}