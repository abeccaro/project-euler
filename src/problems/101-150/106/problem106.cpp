//
// Created by Alex Beccaro on 03/12/18.
//

#include "problem106.hpp"
#include "input.hpp"
#include "numeric"
#include "generics.hpp"

using std::vector;
using std::iota;

using generics::combinations;
using generics::binomial_coefficient;


namespace problems {
    bool problem106::needs_test(const std::vector<uint32_t>& ss1, const std::vector<uint32_t>& ss2) {
        for (uint32_t i = 1; i < ss1.size(); i++)
            if (ss1[i] > ss2[i])
                return true;

        return false;
    }

    uint32_t problem106::solve(uint32_t n) {
        uint32_t result = 0;

        vector<uint32_t> v(n); // vector containing positions in set
        iota (v.begin(), v.end(), 1);

        for (uint32_t l = 2; l <= n / 2; l++) {
            // generate subsets of size l
            vector<vector<uint32_t>> subsets = combinations(v, l);

            for (const auto& ss : subsets) {
                // getting positions not in ss (could be done together with subsets generation for more efficiency)
                vector<uint32_t> others(n - l);
                set_difference (v.begin(), v.end(), ss.begin(), ss.end(), others.begin());

                // removing other's positions before ss' first element
                uint32_t to_remove = 0;
                while (to_remove < others.size() && others[to_remove] < ss[0])
                    to_remove++;

                others.erase(others.begin(), others.begin() + to_remove);

                if (others.size() < l)
                    continue;

                // generating other subsets that might need to be tested
                vector<vector<uint32_t>> compares = combinations(others, l);

                // counting how many need test
                for (const auto& c : compares)
                    if (needs_test(ss, c))
                        result++;
            }
        }

        return result;
    }
}