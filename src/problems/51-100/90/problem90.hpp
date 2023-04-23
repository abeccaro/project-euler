//
// Created by Alex Beccaro on 28/02/18.
//

#ifndef PROJECT_EULER_PROBLEM90_HPP
#define PROJECT_EULER_PROBLEM90_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem90 {
    private:
        /**
         * Extends dice values with 9 if dice contains 6 and vice versa
         * @param dice The dice values
         */
        static void extend(std::vector<uint32_t>& dice);

        /**
         * Checks if given dices can form all numbers in tests
         * @param d1 The first dice values
         * @param d2 The second dice values
         * @param tests The numbers to be able to form
         * @return True if all test numbers can be formed, false otherwise
         */
        static bool is_valid(const std::vector<uint32_t>& d1, const std::vector<uint32_t>& d2,
                             const std::vector<uint32_t>& tests);
    public:
        /**
         * Solves problem
         * @param tests The number to be able to form with 2 dices
         * @return The solution
         */
        static uint32_t solve(const std::vector<uint32_t>& tests = {1, 4, 9, 16, 25, 36, 49, 64, 81});
    };
}


#endif //PROJECT_EULER_PROBLEM90_HPP
