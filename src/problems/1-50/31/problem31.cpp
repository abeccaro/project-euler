//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem31.hpp"

using std::vector;

namespace problems {
    uint32_t problem31::coins_combination(uint32_t pence, const vector<uint32_t>::reverse_iterator& coin) {
        if (*coin == 1)
            return 1;

        uint32_t count = 0;
        for (uint32_t i = 0; i <= pence / (*coin); i++) {
            uint32_t remaining = pence - i * (*coin);
            count += coins_combination(remaining, (coin + 1));
        }
        return count;
    }

    uint32_t problem31::solve(uint32_t pence) {
        vector<uint32_t> coins = {1, 2, 5, 10, 20, 50, 100, 200};

        return coins_combination(pence, coins.rbegin());
    }
}