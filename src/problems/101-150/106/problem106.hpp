//
// Created by Alex Beccaro on 03/12/18.
//

#ifndef PROJECT_EULER_PROBLEM106_HPP
#define PROJECT_EULER_PROBLEM106_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem106 {
    private:
        /**
         * Checks if given subsets needs to be tested for sum equality.
         * Subset are assumed of same size and ss1[0] < ss2[0].
         * @param ss1 The first subset
         * @param ss2 The second subset
         * @return true if subsets pair needs to be tested, false otherwise
         */
        static bool needs_test(const std::vector<uint32_t>& ss1, const std::vector<uint32_t>& ss2);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve(uint32_t n = 12);
    };
}


#endif //PROJECT_EULER_PROBLEM106_HPP
