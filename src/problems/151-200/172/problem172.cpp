//
// Created by Alex Beccaro on 21/05/2023.
//

#include "problem172.hpp"
#include "vector"


using std::vector;

namespace problems {
    uint64_t problem172::solve(uint32_t digits) {
        // precalculate factorials for efficiency
        vector<uint64_t> factorials(digits + 1);
        for (uint64_t n = 0, f = 1; n <= digits; n++, f *= n)
            factorials[n] = f;

        // for each digit try using 0 to 3 of them
        uint64_t result = 0;
        for (uint64_t zeros = 0; zeros <= 3; zeros++) {
            for (uint64_t ones = 0; ones <= 3; ones++) {
                for (uint64_t twos = 0; twos <= 3; twos++) {
                    for (uint64_t threes = 0; threes <= 3; threes++) {
                        for (uint64_t fours = 0; fours <= 3; fours++) {
                            for (uint64_t fives = 0; fives <= 3; fives++) {
                                for (uint64_t sixes = 0; sixes <= 3; sixes++) {
                                    for (uint64_t sevens = 0; sevens <= 3; sevens++) {
                                        for (uint64_t eights = 0; eights <= 3; eights++) {
                                            uint64_t nines = digits - zeros - ones - twos - threes - fours - fives -
                                                    sixes - sevens - eights;

                                            // checks if nines are less than 3 and if there are not too many other
                                            // digits (nines would be < 0) using underflow
                                            if (nines > 3)
                                                continue;

                                            // formula for permutations of multisets
                                            // https://en.wikipedia.org/wiki/Permutation#Permutations_of_multisets
                                            result += factorials[digits] / (factorials[zeros] * factorials[ones] *
                                                    factorials[twos] * factorials[threes] * factorials[fours] *
                                                    factorials[fives] * factorials[sixes] * factorials[sevens] *
                                                    factorials[eights] * factorials[nines]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        // remove the ones starting with a 0 and return
        result = result * 9 / 10;
        return result;
    }
}