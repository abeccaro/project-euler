//
// Created by Alex Beccaro on 09/12/2020.
//

#ifndef PROJECT_EULER_PROBLEM148_HPP
#define PROJECT_EULER_PROBLEM148_HPP

#include <cstdint>


namespace problems {
    class problem148 {
    private:
        /**
         * Calculates the nth triangular number
         * @param n The requested triangular number index
         * @return The nth triangular number
         */
        static uint64_t triangular(uint64_t n);

    public:
        /**
         * Calculates the number of entries of the Pascal's triangle that are not divisible by 7 in the first n lines
         * @param n The number of lines to consider
         * @return The number of entries that are not divisible by 7 in the first n lines
         */
        static uint64_t solve(uint64_t n = 1000000000);
    };
}


#endif //PROJECT_EULER_PROBLEM148_HPP
