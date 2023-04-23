//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM61_HPP
#define PROJECT_EULER_PROBLEM61_HPP

#include "cstdint"
#include "map"
#include "vector"

namespace problems {
    class problem61 {
        using couple = std::pair<uint32_t, uint32_t>; // (number of sides of figure, figurate number)

    private:
        /**
         * Search for a cycle of length = 'length' in given map starting from given solution and testing entry as
         * next element.
         * @param m The map with data
         * @param entry The next element entry to test
         * @param sol The partial solution found. Final solution will be stored here.
         * @param length The length of desired solution
         * @return
         */
        static bool find_cycle(const std::map<couple, std::vector<couple>>& m,
                               const std::pair<couple, std::vector<couple>>& entry,
                               std::vector<couple>& sol, uint32_t length);
    public:
        /**
         * Solves problem
         * @param n The size of required set
         * @return The solution
         */
        static uint32_t solve(uint32_t size = 6);
    };
}


#endif //PROJECT_EULER_PROBLEM61_HPP
