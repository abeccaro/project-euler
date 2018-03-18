//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem62.hpp"
#include <generics.hpp>
#include <map>

using generics::digits;
using std::map;
using std::vector;

namespace problems {
    uint64_t problem62::solve(uint32_t n) {
        map<vector<uint32_t>, vector<uint64_t>> m;

        for (uint64_t i = 1; ; i++) {
            uint64_t cube = i * i * i;
            vector<uint32_t> digs = digits(cube);
            sort(digs.begin(), digs.end());

            vector<uint64_t>& cubes = m[digs];
            cubes.push_back(cube);

            if (cubes.size() >= n)
                return cubes.front();
        }
    }
}