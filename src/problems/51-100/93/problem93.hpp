//
// Created by Alex Beccaro on 01/03/18.
//

#ifndef PROJECT_EULER_PROBLEM93_HPP
#define PROJECT_EULER_PROBLEM93_HPP

#include <vector>
#include <map>
#include <set>

using std::map;
using std::vector;
using std::set;
using std::string;
using uint = unsigned int;

namespace problems {
    class problem93 {
    private:
        /**
         * Apply all basic operators (+, -, *, /) combinations to the first digit and all outputs of other digits
         * @param digits The ordered digits
         * @param m The memory of already calculated results
         * @return All possible outputs of operator application
         */
        static vector<float> apply_operators_first(const vector<uint>& digits, map<vector<uint>, vector<float> >& m);

        /**
         * Apply all basic operators (+, -, *, /) combinations to all outputs of first n-1 digits and the last digit
         * @param digits The ordered digits
         * @param m The memory of already calculated results
         * @return All possible outputs of operator application
         */
        static vector<float> apply_operators_last(const vector<uint>& digits, map<vector<uint>, vector<float> >& m);

        /**
         * Apply all basic operators (+, -, *, /) combinations to given digits maintaining number order
         * @param digits The ordered digits
         * @param m The memory of already calculated results
         * @return All possible outputs of operator application
         */
        static vector<float> apply_operators(const vector<uint>& digits, map<vector<uint>, vector<float> >& m);

        /**
         * Calculates the number of consecutive numbers in the set starting from 1
         * @param numbers The set of numbers
         * @return The number of consecutive numbers starting from 1
         */
        static uint consecutive_int_length(const set<uint>& numbers);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static string solve();
    };
}


#endif //PROJECT_EULER_PROBLEM93_HPP
