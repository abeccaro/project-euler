//
// Created by Alex Beccaro on 22/01/18.
//

#ifndef PROJECT_EULER_PROBLEM73_HPP
#define PROJECT_EULER_PROBLEM73_HPP

#include "fraction.hpp"

namespace problems {
    class problem73 {
        using range = std::pair<fractions::fraction<uint32_t>, fractions::fraction<uint32_t>>;

    public:
        /**
         * Solves problem
         * @param den_ub The upper bound for denominators to consider
         * @param interval The interval to consider
         * @return The solution
         */
        static uint32_t solve(uint32_t den_ub = 12000, const range& interval = {{1,3},{1,2}});
    };
}


#endif //PROJECT_EULER_PROBLEM73_HPP
