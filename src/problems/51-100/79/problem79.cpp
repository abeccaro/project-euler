//
// Created by Alex Beccaro on 18/12/17.
//
// Actually solved by hand
//

#include "problem79.hpp"
#include <input.hpp>
#include <unordered_set>

using std::vector;
using std::unordered_set;

using input::read_matrix;
using input::problems_folder;

namespace problems {
    vector<uint32_t> problem79::solve() {
        vector<vector<uint32_t>> codes = read_matrix<uint32_t>(problems_folder + "51-100/79/input.txt");

        unordered_set<uint32_t> possible_digits;
        // assuming all digits in passcode have been requested at least once
        // otherwise problem would be impossible
        for (const auto& c : codes)
            for (const auto& d : c)
                possible_digits.insert(d);

        vector<uint32_t> result(possible_digits.size());
        for (uint32_t i = 0; i < result.size(); i++) {
            // possible next digit to insert in passcode is among these
            unordered_set<uint32_t> possible_next = possible_digits;

            // selecting next digit to insert in passcode
            for (const auto& c : codes)
                for (auto it = c.begin() + 1; it != c.end(); it++)
                    possible_next.erase(*it);

            // should have only one digit (or problem is ambiguous)
            uint32_t next = *possible_next.begin();

            // removing next occurrencies to not scan them later
            for (auto it = codes.begin(); it != codes.end();) {
                vector<uint32_t>& c = *it;

                if (c[0] == next)
                    c.erase(c.begin());

                if (c.empty())
                    it = codes.erase(it);
                else
                    it++;
            }

            // adding digit to passcode
            result[i] = next;
            possible_digits.erase(next);
        }

        return result;
    }
}