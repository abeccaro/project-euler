//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM31_HPP
#define PROJECT_EULER_PROBLEM31_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem31 {
    private:
        /**
         * Counts the possible different ways in which 'pence' pence can be obtained using coins equal or less valuable
         * than given one. Coins in collection are supposed in order of value
         * @param pence The pence to make
         * @param coin The maximum value coin to use
         * @return The number of different ways to make 'pence' pence
         */
        static uint32_t coins_combination(uint32_t pence, const std::vector<uint32_t>::reverse_iterator& coin);
    public:
        /**
         * Solves problem
         * @param pence The total pence
         * @return The solution
         */
        static uint32_t solve(uint32_t pence = 200);
    };
}


#endif //PROJECT_EULER_PROBLEM31_HPP
