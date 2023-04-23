//
// Created by Alex Beccaro on 06/12/2019.
//

#include "problem137.hpp"
#include "series/fibonacci.hpp"


using series::fibonacci;


namespace problems {

    uint64_t problem137::solve(uint32_t n) {
        fibonacci<uint64_t> fibs;
        return fibs[2 * n - 1] * fibs[2 * n];
    }

}