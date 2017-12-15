//
// Created by Alex Beccaro on 15/12/17.
//

#include "FigurateNumber.h"

namespace series {
    FigurateNumber::FigurateNumber(unsigned long sides) {
        numbers.push_back(1);

        nextIncrement = sides - 1;
        incrementStep = sides - 2;
    }

    unsigned long FigurateNumber::nextElement() {
        unsigned long n = numbers.back() + nextIncrement;
        nextIncrement += incrementStep;
        return n;
    }
}