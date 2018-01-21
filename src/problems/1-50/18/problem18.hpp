//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM18_HPP
#define PROJECT_EULER_PROBLEM18_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem18 {
    private:
        /**
         * Calculates the sum of the number in the highest sum path in given triangle from top to bottom.
         * @param triangle The triangle
         * @param row The starting element row
         * @param col The starting element column
         * @return The sum of the best path
         */
        static uint best_path_sum(const vector<vector<uint>> &triangle, uint row = 0, uint col = 0);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM18_HPP
