//
// Created by Alex Beccaro on 16/12/17.
//

#include "problem15.hpp"
#include "generics.hpp"

using generics::binomial_coefficient;

namespace problems {
    uint128_t problem15::solve(uint32_t width, uint32_t height) {
        return binomial_coefficient<uint128_t>(width + height, width);
    }
}