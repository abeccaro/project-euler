//
// Created by Alex Beccaro on 22/01/18.
//

#ifndef PROJECT_EULER_PROBLEM73_HPP
#define PROJECT_EULER_PROBLEM73_HPP

#include <fraction.hpp>

using fractions::fraction;
using range = std::pair<fraction<uint>, fraction<uint>>;

using uint = unsigned int;

namespace problems {
    class problem73 {
    public:
        /**
         * Solves problem
         * @param den_ub The upper bound for denominators to consider
         * @param interval The interval to consider
         * @return The solution
         */
        static uint solve(uint den_ub = 12000, const range& interval = {{1,3},{1,2}});
    };
}


#endif //PROJECT_EULER_PROBLEM73_HPP
