//
// Created by Alex Beccaro on 28/02/18.
//

#ifndef PROJECT_EULER_PROBLEM90_HPP
#define PROJECT_EULER_PROBLEM90_HPP

#include <vector>

using uint = unsigned int;
using std::vector;

namespace problems {
    class problem90 {
    private:
        /**
         * Extends dice values with 9 if dice contains 6 and vice versa
         * @param dice The dice values
         */
        static void extend(vector<uint>& dice);

        /**
         * Checks if given dices can form all numbers in tests
         * @param d1 The first dice values
         * @param d2 The second dice values
         * @param tests The numbers to be able to form
         * @return True if all test numbers can be formed, false otherwise
         */
        static bool is_valid(const vector<uint>& d1, const vector<uint>& d2, const vector<uint>& tests);
    public:
        /**
         * Solves problem
         * @param tests The number to be able to form with 2 dices
         * @return The solution
         */
        static uint solve(const vector<uint>& tests = {1, 4, 9, 16, 25, 36, 49, 64, 81});
    };
}


#endif //PROJECT_EULER_PROBLEM90_HPP
