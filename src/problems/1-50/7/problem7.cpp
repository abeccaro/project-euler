//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem7.hpp"
#include "series/primes.hpp"

using series::primes;

namespace problems {
    uint32_t problem7::solve(uint32_t position) {
        primes<uint32_t> p;
        return p[position - 1];
    }
}