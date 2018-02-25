//
// Created by Alex Beccaro on 25/02/18.
//

#ifndef PROJECT_EULER_PROBLEM84_HPP
#define PROJECT_EULER_PROBLEM84_HPP

#include <string>

using uint = unsigned int;
using std::string;
using std::vector;
using std::map;

namespace problems {
    class problem84 {
    private:
        /**
         * Calculates all possible rolls and relative probabilities
         * @param sides The number of dices sides
         */
        static std::map<uint, float> init_rolls(uint sides);

        /**
         * Calculates the probability to end in each square when landing on given square
         * @param pos The landing square
         * @return The probabilities
         */
        static vector<float> turn_to(uint pos);

        /**
         * Calculates the probability to end in each square when starting turn on given square
         * @param pos The starting square
         * @return The probabilities
         */
        static vector<float> turn_from(uint pos, const map<uint, float>& rolls);

        /**
         * Calculates the probability to end in each square when starting from each possible square with given
         * probabilities
         * @param probabilities The probability distribution of starting square
         * @return The new probability distribution
         */
        static vector<float> turn(const vector<float>& probabilities, const map<uint, float>& rolls);
    public:
        /**
         * Solves problem
         * @param faces The number of dices sides
         * @return The solution
         */
        static string solve(uint sides = 4);
    };
}


#endif //PROJECT_EULER_PROBLEM84_HPP
