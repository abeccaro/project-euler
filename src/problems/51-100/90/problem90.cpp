//
// Created by Alex Beccaro on 28/02/18.
//

#include "problem90.hpp"
#include <generics.hpp>

using std::vector;
using generics::combinations;

namespace problems {
    void problem90::extend(vector<uint32_t>& dice) {
        bool six = false, nine = false;

        for (const auto& n : dice) {
            if (n == 6)
                six = true;
            else if (n == 9)
                nine = true;
        }

        if (six && !nine)
            dice.push_back(9);
        else if (nine && !six)
            dice.push_back(6);
    }

    bool problem90::is_valid(const vector<uint32_t>& d1, const vector<uint32_t>& d2, const vector<uint32_t>& tests) {
        for (uint32_t t : tests) {
            uint32_t n1 = t / 10;
            uint32_t n2 = t % 10;

            auto contains = [](const vector<uint32_t>& vec, uint32_t val) {
                return std::find(vec.begin(), vec.end(), val) != vec.end();
            };

            if (!((contains(d1, n1) && contains(d2, n2)) || (contains(d2, n1) && contains(d1, n2))))
                return false;
        }
        return true;
    }

    uint32_t problem90::solve(const vector<uint32_t>& tests) {
        uint32_t result = 0;
        const vector<uint32_t> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<uint32_t>> combs = combinations(digits, 6);

        for (auto i = combs.begin(); i < combs.end(); i++) {
            extend(*i);
            for (auto j = i; j < combs.end(); j++) {
                extend(*j);
                if (is_valid(*i, *j, tests))
                    result++;
            }
        }

        return result;
    }
}