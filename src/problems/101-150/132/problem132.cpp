//
// Created by Alex Beccaro on 25/11/2019.
//

#include "problem132.hpp"
#include <primes.hpp>
#include <series/primes.hpp>


using primes::prime_factors;
using generics::mod_pow;
using generics::int_pow;


namespace problems {

    bool is_feasible(uint32_t len) {
        for (const auto& p : prime_factors(len)) {
            if (p != 2 && p != 5)
                return false;
        }
        return true;
    }

    uint32_t problem132::solve(uint32_t e, uint32_t n) {
        series::primes<uint64_t> ps;
        uint64_t res = 0;
        uint32_t found = 0;

        for (const auto& p : ps) {
            if (mod_pow<uint64_t>(10, int_pow<uint64_t>(10, e), 9 * p) == 1) {
                res += p;
                found++;
                if (found == n)
                    break;
            }
        }

        return res;

        /*
        series::primes<uint64_t> ps;
        uint64_t res = 0;
        uint32_t found = 0;

        for (const auto& p : ps) {
            uint64_t r = 0;
            uint32_t offset = 0;
            while (r < p) {
                r = r * 10 + 1;
                offset++;
            }
            r = r % p;
            int start = r == 0 ? 0 : -1;
            uint32_t len = 1;
            uint32_t p0 = r;
            for (uint32_t j = 1; ; j++) {
                r = (r * 10 + 1) % p;
                if (r == p0)
                    break;
                if (r == 0)
                    start = j;
                len++;
            }

            if (start < 0 || !is_feasible(len))
                continue;

            if ((k - offset) % len == start) {
                std::cout << p << " " << len << " " << start << std::endl;
                res += p;
                found++;
                if (found == n)
                    break;
            }
        }

        return res;
        */
    }

}