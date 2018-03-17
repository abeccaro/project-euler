//
// Created by Alex Beccaro on 16/01/18.
//
#ifndef PROJECT_EULER_CONVERGENTS_HPP
#define PROJECT_EULER_CONVERGENTS_HPP

#include "lazy_series.hpp"
#include "template_conditions.hpp"
#include "fraction.hpp"

namespace series {
    /**
     * Lazy series implementation for convergent fractions to irrational number.
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    class sqrt_convergents : public lazy_series<fractions::fraction<T>> {
    public:
        explicit sqrt_convergents(const T& n);

    protected:
        fractions::fraction<T> next_element() final;

    private:
        std::vector<T> coeff;
    };
}

#include "sqrt_convergents.ipp"

#endif //PROJECT_EULER_CONVERGENTS_HPP
