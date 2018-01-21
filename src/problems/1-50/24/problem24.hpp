//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM24_HPP
#define PROJECT_EULER_PROBLEM24_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem24 {
    public:
        /**
         * Solves problem
         * @param digs The digits to permute
         * @param n The ordinal number of required permutation
         * @return The solution
         */
        static vector<uint> solve(const vector<uint>& digs = {0,1,2,3,4,5,6,7,8,9}, uint n = 1000000);
    };
}


#endif //PROJECT_EULER_PROBLEM24_HPP
