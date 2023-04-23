//
// Created by Alex Beccaro on 21/01/2019.
//

#ifndef PROJECT_EULER_PROBLEM122_HPP
#define PROJECT_EULER_PROBLEM122_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem122 {
    private:
        /**
         * Calculates the minimum lengths of the addition chains that end with a number <= 'ub'.
         * For ub >= 12509 results might not be correct.
         *
         * @param ub The maximum number computed chains can end with
         */
        static std::vector<uint32_t> addition_chain(uint32_t ub);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 200);
    };
}


#endif //PROJECT_EULER_PROBLEM122_HPP
