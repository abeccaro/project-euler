//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem7.hpp"
#include "series/primes.hpp"

using series::primes;

namespace problems {
    uint problem7::solve(ulong position) {
        primes<uint> p;
        return p[position - 1];
    }
}