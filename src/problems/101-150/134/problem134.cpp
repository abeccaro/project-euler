//
// Created by Alex Beccaro on 28/11/2019.
//

#include "series/primes.hpp"
#include "generics.hpp"
#include "problem134.hpp"


using std::vector;

using generics::mod_pow;


namespace problems {

    uint64_t problem134::solve(uint64_t ub) {
        series::primes<uint64_t> ps;
        uint64_t res = 0;

        uint64_t a = 10;
        for (auto i = ps.begin() + 2; *i < ub; i++) {
            uint64_t p1 = *i;
            uint64_t p2 = *(i + 1);

            if (a < p1)
                a *= 10;

            uint64_t k = (mod_pow(a, p2 - 2, p2) * (p2 - p1)) % p2;
            res += k * a + p1;
        }

        return res;
    }

}