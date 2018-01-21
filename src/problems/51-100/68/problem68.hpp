//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM68_HPP
#define PROJECT_EULER_PROBLEM68_HPP

#include <vector>

using uint = unsigned int;
using std::vector;
using std::string;

namespace problems {
    class problem68 {
    private:
        /**
         * Checks if given 5-gon ring string representation is valid.
         * @param str The 5-gon ring string representation
         * @return True if str is valid, false otherwise
         */
        static bool is_valid(const vector<uint>& str);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static string solve();
    };
}


#endif //PROJECT_EULER_PROBLEM68_HPP
