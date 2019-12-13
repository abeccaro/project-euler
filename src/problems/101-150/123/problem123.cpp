//
// Created by Alex Beccaro on 22/01/2019.
//

#include "problem123.hpp"
#include <generics.hpp>
#include <series/primes.hpp>
#include <boost/multiprecision/cpp_int.hpp>


using generics::int_pow;
using generics::mod_pow;

using boost::multiprecision::uint128_t;


namespace problems {

    uint32_t problem123::solve(uint32_t exp_lb) {
        uint64_t lb = int_pow<uint64_t>(10, exp_lb);
        series::primes<uint64_t> ps;

        for (uint32_t i = 1; ; i++) {
            uint64_t p = ps[i - 1];
            uint64_t p2 = p * p;

            uint128_t x = (mod_pow<uint128_t>(p - 1, i, p2) + mod_pow<uint128_t>(p + 1, i, p2)) % p2;

            if (x > lb)
                return i;
        }
    }

}