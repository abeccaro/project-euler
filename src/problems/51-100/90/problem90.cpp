//
// Created by Alex Beccaro on 28/02/18.
//

#include "problem90.hpp"
#include <generics.hpp>

using std::vector;
using generics::combinations;

namespace problems {
    void problem90::extend(vector<uint>& dice) {
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

    bool problem90::is_valid(const vector<uint>& d1, const vector<uint>& d2, const vector<uint>& tests) {
        for (uint t : tests) {
            uint n1 = t / 10;
            uint n2 = t % 10;

            auto contains = [](const vector<uint>& vec, uint val) {
                return std::find(vec.begin(), vec.end(), val) != vec.end();
            };

            if (!((contains(d1, n1) && contains(d2, n2)) || (contains(d2, n1) && contains(d1, n2))))
                return false;
        }
        return true;
    }

    uint problem90::solve(const vector<uint>& tests) {
        uint result = 0;
        const vector<uint> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<uint>> combs = combinations(digits, 6);

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