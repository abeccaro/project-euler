//
// Created by Alex Beccaro on 28/02/18.
//

#ifndef PROJECT_EULER_PROBLEM89_HPP
#define PROJECT_EULER_PROBLEM89_HPP

#include "string"
#include "map"

namespace problems {
    class problem89 {
    private:
        /**
         * Values of roman letters
         */
        static std::map<char, uint32_t> letterValues;

        /**
         * Converts a roman number to an integer
         * @param roman The roman number
         * @return The integer value
         */
        static uint32_t from_roman(const std::string& roman);

        /**
         * Converts an integer to a roman number in its minimal form
         * @param roman The integer
         * @return The roman number
         */
        static std::string to_roman(uint32_t n);
    public:
        /**
         * Solves problem
         * @return The solution
         */
        static uint32_t solve();
    };
}


#endif //PROJECT_EULER_PROBLEM89_HPP
