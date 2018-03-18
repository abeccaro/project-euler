//
// Created by Alex Beccaro on 12/12/17.
//

#include "problem12.hpp"
#include "series/figurate_number.hpp"
#include "generics.hpp"

using series::figurate_number;
using generics::divisors;

namespace problems {
    uint32_t problem12::solve(uint32_t divs) {
        figurate_number<uint32_t> triangulars(3);
        return triangulars.get_first([divs](uint32_t n){
            return divisors(n).size() > divs;
        });
    }
}