//
// Created by Alex Beccaro on 21/01/18.
//

#ifndef PROJECT_EULER_PROBLEM67_HPP
#define PROJECT_EULER_PROBLEM67_HPP

#include <vector>
#include <map>

using uint = unsigned int;
using std::vector;
using std::map;
using std::pair;

namespace problems {
    class problem67 {
    private:
        static uint calculate_best_paths(const vector<vector<uint>>& matrix,
                                         map<pair<uint, uint>, uint>& memory,
                                         uint row, uint col);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM67_HPP
