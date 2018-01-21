//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM49_HPP
#define PROJECT_EULER_PROBLEM49_HPP

#include <vector>

using uint = unsigned int;
using ulong = unsigned long;
using std::vector;

namespace problems {
    class problem49 {
    private:
        /**
         * Finds all permutations of given number that are prime
         * @param prime The number. It is supposed to be a prime with 4 digits
         * @return The vector of permutations that are prime
         */
        static vector<uint> permutation_primes(const uint& prime);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static ulong solve();
    };
}


#endif //PROJECT_EULER_PROBLEM49_HPP
