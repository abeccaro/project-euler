//
// Created by Alex Beccaro on 29/04/2023.
//

#ifndef PROJECT_EULER_problem163_HPP
#define PROJECT_EULER_problem163_HPP


#include "series/figurate_number.hpp"

namespace problems {
    class problem163 {
    private:
        /**
         * Triangular numbers used in calculations
         */
        static series::figurate_number<uint32_t> triangular;

        /**
         * Coefficients used in calculations in a loop for T_n, T_(n-1), etc
         */
         static std::vector<uint32_t> coefficients;
    public:
        /**
         *
         * @param n
         * @return
         */
        static uint32_t solve(uint32_t n = 36);
    };
}


#endif //PROJECT_EULER_problem163_HPP
