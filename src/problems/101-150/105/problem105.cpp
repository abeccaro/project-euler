//
// Created by Alex Beccaro on 03/12/18.
//

#include "problem105.hpp"
#include <input.hpp>
#include <numeric>
#include <algorithm>
#include <generics.hpp>

using std::vector;
using std::accumulate;
using std::sort;
using std::adjacent_find;

using input::read_matrix;
using input::problems_folder;
using generics::combinations;


namespace problems {
    bool problem105::is_special_sum_set(const vector<uint32_t>& set) {
        vector<uint32_t> smaller_sums;

        uint64_t max_l = set.size() / 2 + set.size() % 2;
        for (uint32_t i = 2; i <= max_l; i++) {
            vector<vector<uint32_t>> subsets = combinations(set, i); // subsets of size i
            vector<uint32_t> sums(subsets.size()); // sums of subsets of size i

            // getting subsets sums
            std::transform (subsets.begin(), subsets.end(), sums.begin(), [](const vector<uint32_t>& s) {
                return accumulate(s.begin(), s.end(), 0);
            });

            // checking for duplicates sums
            sort(sums.begin(), sums.end());
            if (adjacent_find(sums.begin(), sums.end()) != sums.end())
                return false;

            // checking sums are bigger than smaller subsets sums
            for (const auto& s : sums)
                for (const auto& old_s : smaller_sums)
                    if (s <= old_s)
                        return false;

            // adding current sums to smaller subsets sums
            smaller_sums.insert(smaller_sums.end(), sums.begin(), sums.end());
        }

        return true;
    }

    uint32_t problem105::solve() {
        vector<vector<uint32_t>> sets = read_matrix<uint32_t>(problems_folder + "/101-150/105/input.txt");
        uint32_t result = 0;

        for (const auto& s : sets)
            if (is_special_sum_set(s))
                result += accumulate(s.begin(), s.end(), 0);

        return result;
    }
}