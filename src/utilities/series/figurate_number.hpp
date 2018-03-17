//
// Created by Alex Beccaro on 15/12/17.
//
#ifndef PROJECT_EULER_FIGURATE_NUMBER_H
#define PROJECT_EULER_FIGURATE_NUMBER_H

#include "lazy_series.hpp"
#include "template_conditions.hpp"

namespace series {
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    /**
     * lazy_series implementation for figurate numbers sequence.
     */
    class figurate_number : public lazy_series<T> {
    public:
        /**
         * Constructor that takes the number of sides of the shape (3 for triangular numbers,
         * 4 for squares, 5 for pentagonal, ...)
         * @param sides The number of sides of the shape
         */
        explicit figurate_number(const T& sides);

    protected:
        /**
         * Calculates the next number in the sequence.
         * @return The next number in the sequence
         */
        T next_element() final;

    private:
        /**
         * The number to add to current last element to get next element
         */
        T next_increment;

        /**
         * The number to add to increment at each generated element
         */
        T increment_step;
    };

}

#include "figurate_number.ipp"

#endif //PROJECT_EULER_FIGURATE_NUMBER_H
