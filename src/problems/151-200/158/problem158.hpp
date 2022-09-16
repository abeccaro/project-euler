//
// Created by Alex Beccaro on 13/09/2022.
//

#ifndef PROJECT_EULER_PROBLEM158_HPP
#define PROJECT_EULER_PROBLEM158_HPP


#include <cstdint>
#include <map>

namespace problems {
    class problem158 {
    private:
        /**
         * descending_sequence_count(level, max) cache
         */
        static std::map<std::tuple<uint64_t, uint64_t>, uint64_t> dsc;

        /**
         * requested_permutations_count cache
         */
        static std::map<uint64_t, uint64_t> pc;

        /**
         * Counts how many descending sequences of length len can be formed with values up to max
         * @param len The length of the sequences
         * @param max The maximum value
         * @return The number of descending sequences
         */
        static uint64_t descending_sequences_count(uint64_t len, uint64_t max);

        /**
         * Counts how many permutations of numbers from 1 to n only have one ascending neighbour pair
         * @param n The number of values
         * @return The number of permutations
         */
        static uint64_t requested_permutations_count(uint64_t n);

    public:
        /**
         * Calculates the maximum value of p(n) for n up to n_max
         * @param n_max the maximum length of considered strings
         * @return The maximum p(n) with n <= n_max
         */
        static uint64_t solve(uint64_t n_max = 26);
    };
}


#endif //PROJECT_EULER_PROBLEM158_HPP
