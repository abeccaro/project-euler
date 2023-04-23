//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM43_HPP
#define PROJECT_EULER_PROBLEM43_HPP

#include "cstdint"
#include "vector"

namespace problems {
    class problem43 {
    private:
        /**
         * Checks divisibility properties required by problem
         * @param digs The ordered digits of pandigital number
         * @return True if it satisfies all properties, false otherwise
         */
        static bool has_required_properties(const std::vector<uint32_t>& digs);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint64_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM43_HPP
