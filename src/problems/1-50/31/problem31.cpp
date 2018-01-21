//
// Created by Alex Beccaro on 18/12/17.
//

#include "problem31.hpp"

using std::vector;

namespace problems {
    uint problem31::coins_combination(uint pence, const rev_it& coin) {
        if (*coin == 1)
            return 1;

        uint count = 0;
        for (uint i = 0; i <= pence / (*coin); i++) {
            uint remaining = pence - i * (*coin);
            count += coins_combination(remaining, (coin + 1));
        }
        return count;
    }

    uint problem31::solve(uint pence) {
        vector<uint> coins = {1, 2, 5, 10, 20, 50, 100, 200};

        return coins_combination(pence, coins.rbegin());
    }
}