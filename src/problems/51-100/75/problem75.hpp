//
// Created by Alex Beccaro on 23/01/18.
//

#ifndef PROJECT_EULER_PROBLEM75_HPP
#define PROJECT_EULER_PROBLEM75_HPP

#include <vector>
#include <unordered_map>

using uint = unsigned int;
using std::unordered_map;

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
        static void sums_up_to(uint ub, unordered_map<uint, uint>& sums, uint a = 3, uint b = 4, uint c = 5);
    public:
        /**
         * Solves problem
         * @param ub The upper bound for wire length
         * @return The solution
         */
        static uint solve(uint ub = 1500000);
    };
}


#endif //PROJECT_EULER_PROBLEM75_HPP
