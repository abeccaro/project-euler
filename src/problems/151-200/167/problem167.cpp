//
// Created by Alex Beccaro on 02/05/2023.
//

#include "problem167.hpp"
#include "set"
#include "vector"


using std::count;
using std::pair;
using std::set;
using std::vector;

namespace problems {
    // Based off https://doi.org/10.1016/0097-3165(92)90042-S
    pair<uint64_t, uint64_t> problem167::find_period(uint64_t v) {
        vector<bool> b(v, false);
        b.push_back(true);

        uint32_t zeros = 0;
        for (uint64_t i = v ; ; i++) {
            bool next = b[i] != b[i - v];
            if (next) {
                if (zeros == v) {
                    uint64_t total_difference = 2 * (b.size() - v);
                    uint64_t length = count(b.begin(), b.end(), true);
                    return {length, total_difference};
                }
                zeros = 0;
            } else
                zeros++;
            b.push_back(next);
        }
    }

    // Calculates nth Ulam number of a sequence U(2,v) with v odd >= 5.
    // Uses the fact that these sequences have only 2 even values at indices 1 and (v + 7) / 2 and are then regular.
    uint64_t problem167::ulam2(uint64_t v, uint64_t k) {
        // even numbers
        uint64_t even1 = 2;
        uint64_t even2 = 2 * v + 2;
        uint64_t even2_index = (v + 7) / 2;

        // special cases for first values
        if (k == 1)
            return even1;
        if (k < even2_index)
            return v + 2 * (k - 2);
        if (k == even2_index)
            return even2;

        // calculate period properties
        auto [period_length, period_total_difference] = find_period(v);
        uint64_t period_start_index = even2_index + 1;

        // calculate terms up to (k - period_start_index) % period_length + period_start_index
        set<uint64_t> sums;
        uint64_t n = v;
        uint64_t limit = (k - period_start_index) % period_length + period_start_index;

        for (uint64_t i = 3; i < limit; i++) {
            if (sums.contains(n + even1))
                sums.erase(n + even1);
            else
                sums.insert(n + even1);

            if (sums.contains(n + even2))
                sums.erase(n + even2);
            else
                sums.insert(n + even2);

            n = *sums.begin();
            sums.erase(sums.begin());
        }

        // use period data to calculate final answer
        return n + period_total_difference * ((k - period_start_index) / period_length);
    }

    uint64_t problem167::solve(uint32_t n, uint64_t k) {
        uint64_t v_max = 2 * n + 1;
        uint64_t res = 0;

        for (uint64_t v = 5; v <= v_max; v += 2)
            res+= ulam2(v, k);

        return res;
    }
}