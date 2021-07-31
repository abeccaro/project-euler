//
// Created by Alex Beccaro on 09/12/2020.
//

#ifndef PROJECT_EULER_PROBLEM148_HPP
#define PROJECT_EULER_PROBLEM148_HPP

#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>


namespace problems {
    class problem148 {
    private:
        /**
         * Calculates the nth triangular number
         * @param n The requested triangular number index
         * @return The nth triangular number
         */
        static boost::multiprecision::cpp_int triangular(const boost::multiprecision::cpp_int& n);

    public:
        /**
         * Calculates the number of entries of the Pascal's triangle that are not divisible by 7 in the first n lines
         * @param n The number of lines to consider
         * @return The number of entries that are not divisible by 7 in the first n lines
         */
        static boost::multiprecision::cpp_int solve(const boost::multiprecision::cpp_int& n = 1000000000);
    };
}


#endif //PROJECT_EULER_PROBLEM148_HPP
