//
// Created by Alex Beccaro on 23/01/18.
//

#ifndef PROJECT_EULER_PROBLEM75_HPP
#define PROJECT_EULER_PROBLEM75_HPP

#include <vector>
#include <unordered_map>

namespace problems {
    class problem75 {
    private:
        /**
         * Populates given map with the number of triples with sum n (map of type: sum => count).
         * @param ub The upper bound (inclusive)
         * @param sums The map to populate
         * @param a The first number of the triple
         * @param b The second number of the triple
         * @param c The third number of the triple
         */
        static void sums_up_to(uint32_t ub, std::unordered_map<uint32_t, uint32_t>& sums, uint32_t a = 3, uint32_t b = 4, uint32_t c = 5);
    public:
        /**
         * Solves problem
         * @param ub The upper bound for wire length
         * @return The solution
         */
        static uint32_t solve(uint32_t ub = 1500000);
    };
}


#endif //PROJECT_EULER_PROBLEM75_HPP
