//
// Created by Alex Beccaro on 17/08/2022.
//

#ifndef PROJECT_EULER_PROBLEM152_HPP
#define PROJECT_EULER_PROBLEM152_HPP


#include <cstdint>
#include <vector>
#include "fraction.hpp"

namespace problems {
    class problem152 {
    private:
        class group {
        public:
            /**
             * The fractions included in this group
             */
            std::vector<fractions::fraction<uint64_t>> fractions;

            /**
             * The sum of the fractions in this group
             */
            fractions::fraction<uint64_t> sum;

            /**
             * Creates an empty group
             */
            group();

            /**
             * Creates a group with a single fraction
             * @param f The fraction
             */
            explicit group(const fractions::fraction<uint64_t>& f);

            /**
             * Creates a group that merges all given groups fractions. This does not check for duplicates.
             * It also sorts the fractions
             * @param groups The groups to merge
             */
            explicit group(const std::vector<group>& groups);

            /**
             * Checks if there are duplicate fractions. If there are it returns false, otherwise true
             * @return true if there are no duplicates, false otherwise
             */
            bool is_valid() const;

            /**
             * Override for equality operator. Checks if fractions are the same, both groups are supposed to be ordered.
             * @param g2 The other group to compare
             * @return true if the groups have the same fractions
             */
            bool operator == (const group& g2) const;

            /**
             * Override for less than operator. Checks groups fraction vector, both groups are supposed to be ordered.
             * @param g2 The other group to compare
             * @return true if this group fraction vector is less than the other group fractions vector
             */
            bool operator < (const group& g2) const;
        };

        /**
         * Generates a sorted vector of single fraction groups 1/d where d is a multiple of given set of numbers.
         * The result stop when d reaches given upper bound ub
         * @param factors The prime factors to generate fractions from
         * @param ub The upper bound for generated fractions
         * @return The ordered vector of fraction groups
         */
        static std::vector<group> from_prime_factors(const std::vector<uint64_t>& factors, uint64_t ub);

        /**
         * Aggregates all given groups by their sum
         * @param groups The groups to aggregate
         * @return A map where the keys are the sums and the values are vectors of the groups with that sum
         */
        static std::map<fractions::fraction<uint64_t>, std::vector<group>> group_by_sum(const std::vector<group>& groups);

    public:
        /**
         * Calculates the number of ways to write 1/2 as a sum of inverse squares using distinct integers between
         * 2 and n inclusive
         * @param ub The upper bound for integers to use
         * @return The number of ways
         */
        static uint32_t solve(uint32_t ub = 80);
    };
}


#endif //PROJECT_EULER_PROBLEM152_HPP
