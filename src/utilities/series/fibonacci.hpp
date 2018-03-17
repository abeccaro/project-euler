//
// Created by Alex Beccaro on 13/12/17.
//
#ifndef PROJECT_EULER_FIBONACCI_H
#define PROJECT_EULER_FIBONACCI_H

#include "lazy_series.hpp"
#include "template_conditions.hpp"

namespace series {
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    /**
     * lazy_series implementation for fibonacci sequence.
     */
    class fibonacci : public lazy_series<T> {
    public:
        /**
         * Default constructor that adds first 2 numbers.
         */
        fibonacci();
    protected:
        /**
         * Calculates the next number in the sequence as the sum of the last 2 added.
         * @return The next fibonacci number
         */
        T next_element() final;
    };

}

#include "fibonacci.ipp"

#endif //PROJECT_EULER_FIBONACCI_H
