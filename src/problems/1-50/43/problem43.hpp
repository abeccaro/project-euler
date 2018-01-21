//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM43_HPP
#define PROJECT_EULER_PROBLEM43_HPP

#include <vector>

using uint = unsigned int;
using ulong = unsigned long;
using std::vector;

namespace problems {
    class problem43 {
    private:
        /**
         * Checks divisibility properties required by problem
         * @param digs The ordered digits of pandigital number
         * @return True if it satisfies all properties, false otherwise
         */
        static bool has_required_properties(const vector<uint>& digs);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static ulong solve();
    };
}


#endif //PROJECT_EULER_PROBLEM43_HPP
