//
// Created by Alex Beccaro on 25/11/2019.
//

#include "problem133.hpp"
#include "primes.hpp"

using std::vector;

using primes::prime_factors;
using generics::mod_pow;
using generics::int_pow;


namespace problems {

    uint32_t problem133::solve(uint32_t ub) {
        std::vector<uint32_t> primes = primes::primes_up_to<uint32_t>(ub);
        uint32_t res = 10; // 2 + 3 + 5

        uint32_t max_e = 1;
        for (uint32_t n = 2; n < ub; n *= 2, max_e++) {}

        for (auto it = primes.begin() + 3; it != primes.end(); it++) {
            uint32_t p = *it;

            if (mod_pow<uint64_t>(10, int_pow<uint64_t>(10, max_e), p) != 1)
                res += p;
        }

        return res;
    }

}