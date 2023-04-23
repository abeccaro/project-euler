//
// Created by Alex Beccaro on 22/01/18.
//

#ifndef PROJECT_EULER_PROBLEM71_HPP
#define PROJECT_EULER_PROBLEM71_HPP

#include "fraction.hpp"

namespace problems {
    class problem71 {
    public:
        /**
         * Solves problem
         * @param ub The upper bound for denominators to consider
         * @param ref The fraction to get as close as possible to
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1000000, fractions::fraction<uint64_t> ref = {3, 7});
    };
}


#endif //PROJECT_EULER_PROBLEM71_HPP
