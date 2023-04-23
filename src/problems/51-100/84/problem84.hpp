//
// Created by Alex Beccaro on 25/02/18.
//

#ifndef PROJECT_EULER_PROBLEM84_HPP
#define PROJECT_EULER_PROBLEM84_HPP

#include "string"

namespace problems {
    class problem84 {
    private:
        /**
         * Calculates all possible rolls and relative probabilities
         * @param sides The number of dices sides
         */
        static std::map<uint32_t, float> init_rolls(uint32_t sides);

        /**
         * Calculates the probability to end in each square when landing on given square
         * @param pos The landing square
         * @return The probabilities
         */
        static std::vector<float> turn_to(uint32_t pos);

        /**
         * Calculates the probability to end in each square when starting turn on given square
         * @param pos The starting square
         * @return The probabilities
         */
        static std::vector<float> turn_from(uint32_t pos, const std::map<uint32_t, float>& rolls);

        /**
         * Calculates the probability to end in each square when starting from each possible square with given
         * probabilities
         * @param probabilities The probability distribution of starting square
         * @return The new probability distribution
         */
        static std::vector<float> turn(const std::vector<float>& probabilities, const std::map<uint32_t, float>& rolls);
    public:
        /**
         * Solves problem
         * @param faces The number of dices sides
         * @return The solution
         */
        static std::string solve(uint32_t sides = 4);
    };
}


#endif //PROJECT_EULER_PROBLEM84_HPP
