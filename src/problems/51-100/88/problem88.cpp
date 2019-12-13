//
// Created by Alex Beccaro on 27/02/18.
//

#include "problem88.hpp"
#include <unordered_set>
#include <cmath>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::min;

namespace problems {
    void problem88::calculate_mps_recursive(vector<uint32_t>& mps, uint32_t ub, vector<uint32_t>& a, uint32_t sum, uint32_t product) {
        uint32_t last = a.back();

        for (uint32_t p = product * last; p < ub; p = product * last) {
            uint32_t s = sum + last;
            a.push_back(last);

            // calculate k
            uint64_t k = a.size() + p - s;

            // if k is greater then considered ones stop
            if (k > mps.size()) {
                a.resize(a.size() - 1);
                break;
            }

            // update mps of k if necessary
            mps[k-1] = min(mps[k-1], p);

            // recursive call
            calculate_mps_recursive(mps, ub, a, s, p);
            a.resize(a.size() - 1);

            last++;
        }
    }

    vector<uint32_t> problem88::calculate_mps(uint32_t ub) {
        vector<uint32_t> mps(ub, 2 * ub); // result vector
        mps[0] = 0; // skip k = 1
        uint32_t root = (uint32_t) std::sqrt(2 * ub); // upper bound for min a[i] != 1

        for (uint32_t i = 2; i <= root; i++) {
            vector<uint32_t> a(1, i);
            calculate_mps_recursive(mps, 2 * ub, a, i, i);
        }

        return mps;
    }

    uint32_t problem88::solve(uint32_t ub) {
        vector<uint32_t> mps2 = calculate_mps(ub);

        // remove duplicates
        unordered_set<uint32_t> mps_set(std::make_move_iterator(mps2.begin()),
                                        std::make_move_iterator(mps2.end()));

        // sum
        uint32_t result = 0;
        for (uint32_t x : mps_set)
            result += x;

        return result;
    }
}