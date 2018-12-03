//
// Created by Alex Beccaro on 03/12/18.
//

#ifndef PROJECT_EULER_PROBLEM105_HPP
#define PROJECT_EULER_PROBLEM105_HPP

#include <cstdint>
#include <vector>

namespace problems {
    class problem105 {
    private:
        /**
         * Checks if given set satisfies problem conditions.
         * @param set The set to check
         * @return true if set satisfies both conditions, false otherwise
         */
        static bool is_special_sum_set(const std::vector<uint32_t>& set);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM105_HPP
