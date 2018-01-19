//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem12.hpp"
#include "series/figurate_number.hpp"
#include "generics.hpp"

using series::figurate_number;
using generics::divisors;

namespace problems {
    uint problem12::solve(uint divs) {
        figurate_number<uint> triangulars(3);
        return triangulars.get_first([divs](uint n){return divisors(n).size() > divs;});
    }
}