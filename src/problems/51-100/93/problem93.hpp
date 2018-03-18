//
// Created by Alex Beccaro on 01/03/18.
//

#ifndef PROJECT_EULER_PROBLEM93_HPP
#define PROJECT_EULER_PROBLEM93_HPP

#include <vector>
#include <map>
#include <set>

namespace problems {
    class problem93 {
    private:
        /**
         * Apply all basic operators (+, -, *, /) combinations to the first digit and all outputs of other digits
         * @param digits The ordered digits
         * @param m The memory of already calculated results
         * @return All possible outputs of operator application
         */
        static std::vector<float> apply_operators_first(const std::vector<uint32_t>& digits,
                                                   std::map<std::vector<uint32_t>, std::vector<float> >& m);

        /**
         * Apply all basic operators (+, -, *, /) combinations to all outputs of first n-1 digits and the last digit
         * @param digits The ordered digits
         * @param m The memory of already calculated results
         * @return All possible outputs of operator application
         */
        static std::vector<float> apply_operators_last(const std::vector<uint32_t>& digits,
                                                       std::map<std::vector<uint32_t>, std::vector<float> >& m);

        /**
         * Apply all basic operators (+, -, *, /) combinations to given digits maintaining number order
         * @param digits The ordered digits
         * @param m The memory of already calculated results
         * @return All possible outputs of operator application
         */
        static std::vector<float> apply_operators(const std::vector<uint32_t>& digits,
                                             std::map<std::vector<uint32_t>, std::vector<float> >& m);

        /**
         * Calculates the number of consecutive numbers in the set starting from 1
         * @param numbers The set of numbers
         * @return The number of consecutive numbers starting from 1
         */
        static uint32_t consecutive_int_length(const std::set<uint32_t>& numbers);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static std::string solve();
    };
}


#endif //PROJECT_EULER_PROBLEM93_HPP
