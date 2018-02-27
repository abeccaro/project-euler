//
// Created by Alex Beccaro on 27/02/18.
//

#include "problem88.hpp"
#include <set>
#include <cmath>

namespace problems {
    void problem88::calculate_mps_recursive(vector<uint>& mps, uint ub, vector<uint>& a, uint sum, uint product) {
        uint last = a.back();

        for (uint p = product * last; p < ub; p = product * last) {
            uint s = sum + last;
            a.push_back(last);

            // calculate k
            uint k = a.size() + p - s;

            // update mps ok k if necessary
            mps[k-1] = std::min(mps[k-1], p);

            // recursive call
            calculate_mps_recursive(mps, ub, a, s, p);
            a.resize(a.size() - 1);

            last++;
        }
    }

    vector<uint> problem88::calculate_mps(uint ub) {
        vector<uint> mps(ub, 2 * ub); // result vector
        mps[0] = 0; // skip k = 1
        uint root = (uint) std::sqrt(2 * ub); // upper bound for min a[i] != 1

        for (uint i = 2; i <= root; i++) {
            vector<uint> a(1, i);
            calculate_mps_recursive(mps, 2 * ub, a, i, i);
        }

        return mps;
    }

    uint problem88::solve(uint ub) {
        vector<uint> mps = calculate_mps(ub);

        // remove duplicates
        std::set<uint> mps_set(std::make_move_iterator(mps.begin()),
                               std::make_move_iterator(mps.end()));

        // sum
        uint result = 0;
        for (uint x : mps_set)
            result += x;

        return result;
    }
}