//
// Created by Alex Beccaro on 20/01/18.
//

#ifndef PROJECT_EULER_PROBLEM51_HPP
#define PROJECT_EULER_PROBLEM51_HPP

#include <vector>

using uint = unsigned int;
using ulong = unsigned long;
using std::vector;

namespace problems {
    class problem51 {
    private:
        /**
         * Generates all masks with multiples of 3 elements out of n
         * @param size The size of the masks
         * @return The masks
         */
        static vector<vector<bool>> masks(uint size);

        /**
         * Creates the family of given number using given mask and returns its size. This assumes the required family size is 8
         * to improve efficiency
         * @param digs The digits of the number
         * @param mask The mask to use
         * @return The size of generated family
         */
        static uint get_family_size(const vector<uint>& digs, const vector<bool>& mask);

        /**
         * Checks if given number has a family with at least 8 primes. This assumes the required family size is 8 to improve
         * efficiency
         * @param number The number to check
         * @return true if exists a family of number with at least 8 primes, false otherwise
         */
        static bool has_required_family(const uint& number);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint solve();
    };
}


#endif //PROJECT_EULER_PROBLEM51_HPP
