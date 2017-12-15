//
// Created by Alex Beccaro on 13/12/17.
//
#ifndef PROJECT_EULER_FIBONACCI_H
#define PROJECT_EULER_FIBONACCI_H

#include "LazySeries.h"

namespace series {
    /**
     * LazySeries implementation for fibonacci sequence.
     */
    class Fibonacci : public LazySeries<unsigned long > {
    public:
        /**
         * Default constructor that adds first 2 numbers.
         */
        Fibonacci();
    protected:
        /**
         * Calculates the next number in the sequence as the sum of the last 2 added.
         * @return The next fibonacci number
         */
        unsigned long nextElement() final;
    };

}


#endif //PROJECT_EULER_FIBONACCI_H
