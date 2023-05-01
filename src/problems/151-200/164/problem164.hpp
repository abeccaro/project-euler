//
// Created by Alex Beccaro on 29/04/2023.
//

#ifndef PROJECT_EULER_PROBLEM164_HPP
#define PROJECT_EULER_PROBLEM164_HPP


#include "cstdint"
#include "hash_functions.hpp"
#include "unordered_map"

namespace problems {
    class problem164 {
    private:
        /**
         * Map for counts of requested numbers from the last 2 current digits and the number of remaining digits.
         */
        static std::unordered_map<
                std::pair<std::pair<uint32_t, uint32_t>, uint32_t>,
                uint64_t,
                pair_hash<std::pair<uint32_t, uint32_t>, uint32_t>
        > mem;

        /**
         * Counts how many 20 digit numbers exist such that no three consecutive digits of n have a sum greater than 9
         * given a partial state of the two last digits and the number of remaining digits
         * @param last_pair The last 2 digits of the partial number
         * @param remaining The number of remaining digits
         * @return The number of 20 digit numbers that satisfy the requisite
         */
        static uint64_t count(const std::pair<uint32_t, uint32_t>& last_pair, uint32_t remaining);
    public:
        /**
         * Counts how many 20 digit numbers exist such that no three consecutive digits of n have a sum greater than 9
         * @return The count
         */
        static uint64_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM164_HPP
