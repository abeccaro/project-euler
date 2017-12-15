//
// Created by Alex Beccaro on 13/12/17.
//

#include "Fibonacci.h"

namespace series {
    Fibonacci::Fibonacci() {
        numbers.push_back(1);
        numbers.push_back(1);
    }

    unsigned long Fibonacci::nextElement() {
        unsigned long count = numbers.size();

        return numbers[count-2] + numbers[count-1];
    }
}
