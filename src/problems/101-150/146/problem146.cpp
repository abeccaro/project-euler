//
// Created by Alex Beccaro on 20/01/2020.
//

#include "problem146.hpp"
#include "primes.hpp"
#include "boost/multiprecision/cpp_int.hpp"


using std::vector;
using boost::multiprecision::uint128_t;

using primes::is_prime;


namespace problems {

    const vector<uint64_t> problem146::first_primes = primes::primes_up_to(10000ULL);

    bool problem146::is_candidate(uint64_t n) {
        // check n is not a multiple of 3 or 7 because n = 0 (mod p) => n^2 + n = 0 (mod p)
        if (n % 3 == 0 || n % 7 == 0)
            return false;

        /*
         * fast check using fermat's little theorem:
         * n^2 + x prime => n^2 ≠ x (mod p) => p - n^2 != x (mod p)
         */
        n *= n;
        for (const auto& p : first_primes) {
            uint64_t m = p - (n % p);
            if (m == 1 || m == 3 || m == 7 || m == 9 || m == 13 || m == 27)
                return false;
        }

        return true;
    }

    uint64_t problem146::solve(uint64_t ub) {
        uint64_t res = 10;

        for (uint64_t n = 20; n < ub; n += 10) {
            // fast check if at least one value is not prime
            if (!is_candidate(n))
                continue;

            // actual check for all values for valid candidates
            uint64_t n2 = n * n;
            if (is_prime<uint128_t>(n2 + 1) && is_prime<uint128_t>(n2 + 3) &&
                       is_prime<uint128_t>(n2 + 7) && is_prime<uint128_t>(n2 + 9) &&
                       is_prime<uint128_t>(n2 + 13) && is_prime<uint128_t>(n2 + 27) &&
                       !is_prime<uint128_t>(n2 + 19) && !is_prime<uint128_t>(n2 + 21))
                res += n;
        }

        return res;
    }

}