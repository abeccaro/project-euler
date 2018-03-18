//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM51_HPP
#define PROJECT_EULER_PROBLEM51_HPP

#include <vector>

namespace problems {
    class problem51 {
    private:
        /**
         * Generates all masks with multiples of 3 elements out of n
         * @param size The size of the masks
         * @return The masks
         */
        static std::vector<std::vector<bool>> masks(uint32_t size);

        /**
         * Creates the family of given number using given mask and returns its size. This assumes the required family size is 8
         * to improve efficiency
         * @param digs The digits of the number
         * @param mask The mask to use
         * @return The size of generated family
         */
        static uint32_t get_family_size(const std::vector<uint32_t>& digs, const std::vector<bool>& mask);

        /**
         * Checks if given number has a family with at least 8 primes. This assumes the required family size is 8 to improve
         * efficiency
         * @param number The number to check
         * @return true if exists a family of number with at least 8 primes, false otherwise
         */
        static bool has_required_family(const uint32_t& number);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM51_HPP
