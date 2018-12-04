//
// Created by Alex Beccaro on 01/04/18.
//

#ifndef PROJECT_EULER_PROBLEM103_HPP
#define PROJECT_EULER_PROBLEM103_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem103 {
    private:
        /**
         * Checks if all subset of the same size in given set have different sums
         * @param set The set to check
         * @return true, if all subset of the same size in given set have different sums, false otherwise
         */
        static bool check_first_condition(const std::vector<uint32_t>& set);
        /**
         * Calculates the optimum special sum set of size 'n'
         * @param n The size of the set
         * @return The optimum special sum
         */
        static std::vector<uint32_t> optimum_special_sum_set(uint32_t n);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static std::vector<uint32_t> solve(uint32_t size = 7);
    };
}


#endif //PROJECT_EULER_PROBLEM103_HPP
