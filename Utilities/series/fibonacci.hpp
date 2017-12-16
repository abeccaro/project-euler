//
// Created by Alex Beccaro on 13/12/17.
//
#ifndef PROJECT_EULER_FIBONACCI_H
#define PROJECT_EULER_FIBONACCI_H

#include "lazy_series.hpp"
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

namespace series {
    template<class T>
    /**
     * lazy_series implementation for fibonacci sequence.
     */
    class fibonacci : public lazy_series<T> {
    public:
        /**
         * Default constructor that adds first 2 numbers.
         */
        fibonacci() {
            this->numbers.emplace_back(1);
            this->numbers.emplace_back(1);
        }
    protected:
        /**
         * Calculates the next number in the sequence as the sum of the last 2 added.
         * @return The next fibonacci number
         */
        T next_element() final {
            unsigned long count = this->numbers.size();

            return this->numbers[count-2] + this->numbers[count-1];
        }
    };

}


#endif //PROJECT_EULER_FIBONACCI_H
