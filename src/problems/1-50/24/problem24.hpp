//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM24_HPP
#define PROJECT_EULER_PROBLEM24_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem24 {
    public:
        /**
         * Solves problem
         * @param digs The digits to permute
         * @param n The ordinal number of required permutation
         * @return The solution
         */
        static std::vector<uint32_t> solve(const std::vector<uint32_t>& digs = {0,1,2,3,4,5,6,7,8,9},
                                           uint32_t n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM24_HPP
