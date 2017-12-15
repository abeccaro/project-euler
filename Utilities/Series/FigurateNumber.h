//
// Created by Alex Beccaro on 15/12/17.
//
#ifndef PROJECT_EULER_FIGURATENUMBER_H
#define PROJECT_EULER_FIGURATENUMBER_H

#include "../../Utilities/Series/LazySeries.h"

namespace series {
    /**
     * LazySeries implementation for figurate numbers sequence.
     */
    class FigurateNumber : public LazySeries<unsigned long> {
    public:
        /**
         * Constructor that takes the number of sides of the shape (3 for triangular numbers,
         * 4 for squares, 5 for pentagonal, ...)
         * @param sides The number of sides of the shape
         */
        explicit FigurateNumber(unsigned long sides);

    protected:
        /**
         * Calculates the next number in the sequence.
         * @return The next number in the sequence
         */
        unsigned long nextElement() final;

    private:
        /**
         * The number to add to current last element to get next element
         */
        unsigned long nextIncrement;

        /**
         * The number to add to increment at each generated element
         */
        unsigned long incrementStep;
    };

}

#endif //PROJECT_EULER_FIGURATENUMBER_H
