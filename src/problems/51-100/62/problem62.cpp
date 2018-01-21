//
// Created by Alex Beccaro on 14/01/18.
//

#include "problem62.hpp"
#include <generics.hpp>
#include <map>

using generics::digits;

using numtype = unsigned long;
using uint = unsigned int;
using std::map;
using std::vector;

namespace problems {
    ulong problem62::solve(uint n) {
        map<vector<uint>, vector<ulong>> m;

        for (ulong i = 1; true; i++) {
            ulong cube = i * i * i;
            vector<uint> digs = digits(cube);
            sort(digs.begin(), digs.end());

            vector<ulong>& cubes = m[digs];
            cubes.push_back(cube);

            if (cubes.size() >= n)
                return cubes.front();
        }
    }
}