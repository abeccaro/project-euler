//
// Created by Alex Beccaro on 18/01/18.
//

#ifndef PROJECT_EULER_PROBLEM13_HPP
#define PROJECT_EULER_PROBLEM13_HPP

#include <vector>

using std::vector;

using uint = unsigned int;

namespace problems {
    class problem13 {
    public:
        /**
         * Solves problem
         * @param d The number of starting digits to return
         * @return The solution
         */
        static vector<uint> solve(uint d = 10);
    };
}


#endif //PROJECT_EULER_PROBLEM13_HPP
