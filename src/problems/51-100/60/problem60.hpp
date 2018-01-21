//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM60_HPP
#define PROJECT_EULER_PROBLEM60_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem60 {
    private:
        /**
         * Adds to n the first prime taken from p > lb that concatenated with any element of n in both ways gives a prime.
         * @param p The list of all primes
         * @param n The list of already present primes
         * @param lb The lower bound
         * @return true if a new element is added, false otherwise
         */
        static bool add_next(const vector<uint>& p, vector<uint>& n, uint lb);

        /**
         * Finds a quintuplet of primes that satisfy problem requirements.
         * @param ub The upper bound for primes
         * @return The quintuplet
         */
        static vector<uint> find_tuple(uint ub, uint size);
    public:
        /**
         * Solves problem
         * @param n The number of primes in the requested set
         * @return The solution
         */
        static uint solve(uint n = 5);
    };
}


#endif //PROJECT_EULER_PROBLEM60_HPP
