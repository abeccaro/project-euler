//
// Created by Alex Beccaro on 20/01/2019.
//

#include "problem121.hpp"
#include <fraction.hpp>


using std::string;
using std::next_permutation;

using fractions::fraction;


namespace problems {

    uint32_t problem121::solve(uint32_t n) {
        fraction<uint64_t>::auto_reduce(true);

        fraction<uint64_t> win_p;
        uint32_t blues_to_win = n / 2 + 1;

        for (uint32_t i = blues_to_win; i <= n; i++) {
            string bitmask(n - i, 0); // n - i leading 0s
            bitmask.resize(n, 1); // i trailing 1s

            do {
                uint64_t num = 1, den = 1;
                for (uint32_t j = 0; j < n; j++) {
                    den *= j + 2;
                    if (bitmask[j] == 0)
                        num *= j + 1;
                }
                win_p += {num, den};
            } while (next_permutation(bitmask.begin(), bitmask.end()));
        }

        return win_p.denominator() / win_p.numerator();
    }

}