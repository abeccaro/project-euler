//
// Created by Alex Beccaro on 27/02/18.
//

#ifndef PROJECT_EULER_PROBLEM88_HPP
#define PROJECT_EULER_PROBLEM88_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem88 {
    private:
        /**
         * Calculates all ps that have a as first numbers (not considering 1s). Numbers are considered sorted and will
         * eventually be added to keep a sorted. It updates mps if it finds lower values.
         * @param mps The vector of currently evaluated mps
         * @param ub The upper bound that values n can't exceed
         * @param a The vector of currently considered numbers
         * @param sum The sum of considered numbers. Passed for efficiency
         * @param product The product of considered numbers. Passed for efficiency
         */
        static void calculate_mps_recursive(std::vector<uint32_t>& mps, uint32_t ub, std::vector<uint32_t>& a, uint32_t sum, uint32_t product);

        /**
         * Calculates all minimal product-sum for k <= ub
         * @param ub The upper bound
         * @return A vector containing mps of k in position k-1
         */
        static std::vector<uint32_t> calculate_mps(uint32_t ub);
    public:
        /**
         * Solves problem
         * @param ub The upper bound of # of numbers in sums and products to check
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 12000);
    };
}


#endif //PROJECT_EULER_PROBLEM88_HPP
