//
// Created by Alex Beccaro on 22/03/18.
//

#include "problem103.hpp"
#include "input.hpp"
#include "unordered_set"
#include "numeric"
#include "generics.hpp"
#include "map"

using std::vector;
using std::unordered_set;
using std::multimap;
using std::accumulate;
using std::iota;

using generics::combinations;

namespace problems {
    bool problem103::check_first_condition(const vector<uint32_t> &set) {
        for (uint32_t i = 2; i <= ceil(set.size() / 2.0); i++) {
            vector<vector<uint32_t>> subsets = combinations(set, i); // subsets of size i
            unordered_set<uint32_t> sums; // sums of subsets of size i

            // getting and looking for duplicate subsets sums
            for (const auto& ss : subsets) {
                uint32_t sum = (uint32_t) accumulate(ss.begin(), ss.end(), 0);
                if (sums.find(sum) != sums.end())
                    return false; // found duplicate subset sum
                sums.insert(sum);
            }
        }

        return true;
    }

    vector<uint32_t> problem103::optimum_special_sum_set(uint32_t n) {
        if (n == 1)
            return {1};

        vector<uint32_t> prev = optimum_special_sum_set(n - 1);

        // getting possible numbers in set
        uint32_t min_cand = prev[prev.size() / 2];
        uint32_t max_cand = prev.back() * 2; // empirical
        vector<uint32_t> candidates(max_cand - min_cand + 1);
        iota(candidates.begin(), candidates.end(), min_cand);

        // creating all possible sets
        vector<vector<uint32_t>> combs = combinations(candidates, n);
        multimap<uint32_t, vector<uint32_t>> map;

        // filtering sets on second condition
        if (n % 2 == 0) {
            for (const auto& c : combs) {
                int32_t left = accumulate(c.begin(), c.begin() + n / 2, 0);
                int32_t right = accumulate(c.rbegin(), c.rbegin() + n / 2 - 1, 0);

                if (left > right) {
                    uint32_t sum = (uint32_t) accumulate(c.begin(), c.end(), 0);
                    map.insert(std::pair<uint32_t, vector<uint32_t>>(sum, c));
                }
            }
        } else {
            for (const auto& c : combs) {
                int32_t left = accumulate(c.begin(), c.begin() + ceil(n / 2.0), 0);
                int32_t right = accumulate(c.rbegin(), c.rbegin() + floor(n / 2.0), 0);

                if (left - right == 1) {
                    uint32_t sum = (uint32_t) accumulate(c.begin(), c.end(), 0);
                    map.insert(std::pair<uint32_t, vector<uint32_t>>(sum, c));
                }
            }
        }

        // checking remaining possible sets
        for (const auto& c : map) {
            if (check_first_condition(c.second))
                return c.second;
        }

        return {};
    }

    vector<uint32_t> problem103::solve(uint32_t size) {
        return optimum_special_sum_set(size);
    }
}