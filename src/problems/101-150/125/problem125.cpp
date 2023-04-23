//
// Created by Alex Beccaro on 22/01/2019.
//

#include "problem125.hpp"
#include "series/figurate_number.hpp"
#include "generics.hpp"
#include "numeric"


using series::figurate_number;
using generics::is_palindrome;


namespace problems {

    uint64_t problem125::solve(uint64_t ub) {
        figurate_number<uint64_t> squares(4);
        uint64_t ub_2 = ub / 2;
        std::vector<uint64_t> ns;

        // find palindromes that can be written as sum of consecutive squares
        for (uint32_t i = 1; squares[i - 1] < ub_2; i++) {
            uint64_t n = squares[i - 1];
            n += squares[i];

            for (uint32_t j = i; n < ub; j++, n += squares[j])
                if (is_palindrome(n))
                    ns.push_back(n);
        }

        // remove duplicates
        std::sort(ns.begin(), ns.end());
        ns.resize(std::unique(ns.begin(), ns.end()) - ns.begin());

        // return sum
        return std::accumulate(ns.begin(), ns.end(), (uint64_t) 0);
    }

}