//
// Created by Alex Beccaro on 28/04/2026.
//

#ifndef PROJECT_EULER_PROBLEM178_HPP
#define PROJECT_EULER_PROBLEM178_HPP


#include "cstdint"
#include "tuple"
#include "unordered_map"
#include "hash_functions.hpp"

namespace problems {
    class problem178 {
    private:
        /**
         * Memory of counts for different states containing [visited_0, visited_9, last_visited, remaining]
         */
        static std::unordered_map<std::tuple<bool, bool, uint32_t, uint32_t>, uint64_t, tuple_hash<bool, bool, uint32_t, uint32_t>> mem;

        /**
         * Counts the pandigital step numbers from a starting number state
         * @param state The state of the numbers, containing [visited_0, visited_9, last_visited, remaining]
         * @return the count of pandigital step numbers from this state
         */
        static uint64_t count(const std::tuple<bool, bool, uint32_t, uint32_t>& state);

    public:
        /**
         * Counts the pandigital step numbers less than 10^ub
         * @return The number of pandigital step numbers less than 10^ub
         */
        static uint64_t solve(uint32_t);
    };
}


#endif //PROJECT_EULER_PROBLEM178_HPP
