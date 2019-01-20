//
// Created by Alex Beccaro on 15/01/18.
//
#ifndef PROJECT_EULER_FRACTION_HPP
#define PROJECT_EULER_FRACTION_HPP

#include <template_conditions.hpp>

namespace fractions {

    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    class fraction {

    private:
        T num; // numerator
        T den; // denominator

        static bool auto_red; // if true fraction is reduced automatically when necessary

    public:

        /// region constructors

        /**
         * Default constructor for 0.
         */
        fraction();

        /**
         * Constructor for integer numbers
         * @param n The number to represent as fraction
         */
        fraction(T n);

        /**
         * Constructor for integer numbers
         * @param n The number to represent as fraction
         */
        template<class U, class = typename std::enable_if<std::is_convertible<U, T>::value>::type>
        fraction(U n);

        /**
         * Complete constructor for a fraction
         * @param n The numerator
         * @param d The denominator
         */
        fraction(T n, T d);

        /**
         * Copy constructor
         * @param f The fraction to copy
         */
        template<class U, class = typename std::enable_if<std::is_convertible<U, T>::value>::type>
        fraction(const fraction<U>& f);

        /// endregion constructors

        /**
         * Reduces this fraction to lowest terms and adjusts signs (if fraction < 0 then numerator will be negative
         * and denominator positive, otherwise both will be positive).
         */
        void reduce();

        /**
         * Inverts this fraction
         */
        void invert();


        ///region getters and setters

        /**
         * Sets auto reduction to specified value (false by default).
         * @param b The auto reduction state to set
         */
        static void auto_reduce(bool b);

        /**
         * Gets the numerator value
         * @return The numerator
         */
        T numerator() const;

        /**
         * Gets the denominator value
         * @return The denominator
         */
        T denominator() const;

        /**
         * Sets the numerator to specified value
         * @param n The numerator to set
         */
        void numerator(const T &n);

        /**
         * Sets the denominator to specified value
         * @param n The denominator to set
         */
        void denominator(const T &d);

        /**
         * Returns the value of the function as a single number
         * @return The value
         */
        double value() const;

        ///endregion

        ///region operators

        /**
         * Assignment operator
         * @param f The value to assign
         * @return The reference to this object
         */
        fraction<T>& operator = (const fraction<T>& f);

        /**
         * Equality check, takes into account possible reductions.
         * @param f The other fraction
         * @return True if they are equal, false otherwise
         */
        bool operator == (fraction<T> f2) const;

        /**
         * Inequality check, takes into account possible reductions.
         * @param f The other fraction
         * @return True if they are not equal, false otherwise
         */
        bool operator != (fraction<T> f2) const;

        /**
         * Less than check by value
         * @param f The other fraction
         * @return True if this is less than f, false otherwise
         */
        bool operator < (const fraction<T>& f) const;

        /**
         * Less than or equal check by value
         * @param f The other fraction
         * @return True if this is equal to or less than f, false otherwise
         */
        bool operator <= (const fraction<T>& f) const;

        /**
         * Greater than check by value
         * @param f The other fraction
         * @return True if this is greater than f, false otherwise
         */
        bool operator > (const fraction<T>& f) const;

        /**
         * Greater than or equal check by value
         * @param f The other fraction
         * @return True if this is equal to or greater than f, false otherwise
         */
        bool operator >= (const fraction<T>& f) const;

        /**
         * Sum operator.
         * @param other The fraction to add
         * @return The sum of this and other fractions
         */
        fraction<T> operator +(const fraction<T>& other) const;

        /**
          * Shorthand for sum and auto assignment
          * @param other The fraction to sum
          * @return This fraction reference
          */
        fraction<T>& operator +=(const fraction<T>& other);

        /**
         * Difference operator.
         * @param other The fraction to subtract
         * @return The difference of this and other fractions
         */
        fraction<T> operator -(const fraction<T>& other) const;

        /**
          * Shorthand for difference and auto assignment
          * @param other The fraction to subtract
          * @return This fraction reference
          */
        fraction<T>& operator -=(const fraction<T>& other);

        /**
         * Product operator.
         * @param other The fraction to multiply
         * @return The product of this and other fractions
         */
        fraction<T> operator *(const fraction<T>& other) const;

        /**
          * Shorthand for product and auto assignment
          * @param other The fraction to multiply
          * @return This fraction reference
          */
        fraction<T>& operator *=(const fraction<T>& other);

        /**
         * Division operator.
         * @param other The fraction to divide
         * @return The division of this and other fractions
         */
        fraction<T> operator /(fraction<T> other) const;

        /**
          * Shorthand for division and auto assignment
          * @param other The fraction to divide
          * @return This fraction reference
          */
        fraction<T>& operator /=(fraction<T> other);

        /**
         * Negation operator
         * @return The opposite of this fraction
         */
        fraction<T> operator -() const;

        ///endregion

        /**
         * Cast to another type
         * @return The closest representation of this fraction in type U
         */
        template<class U, class = typename std::enable_if<std::is_convertible<T, U>::value>::type>
        explicit operator U () const;

    };


    /**
     * Output stream operator.
     * @param os The stream
     * @param f The fraction
     * @return The stream with this fraction representation
     */
    template<class T>
    std::ostream& operator<<(std::ostream& os, const fraction<T>& f);

    /**
     * Fraction stl extension for pow
     * @param f The fraction
     * @param exp The exponent
     */
    template<class T>
    void pow(fraction<T>& f, const T& exp);

    /**
     * Fraction stl extension for max
     * @param f1 The first fraction
     * @param f2 The second fraction
     * @return f1 if f1 > f2, otherwise f2
     */
    template<class T>
    fraction<T> max(const fraction<T>& f1, const fraction<T>& f2);

    /**
     * Fraction stl extension for min
     * @param f1 The first fraction
     * @param f2 The second fraction
     * @return f1 if f1 < f2, otherwise f2
     */
    template<class T>
    fraction<T> min(const fraction<T>& f1, const fraction<T>& f2);

    /**
     * Fraction stl extension for abs
     * @param f The fraction
     * @return The absolute value of f
     */
    template<class T>
    fraction<T> abs(const fraction<T>& f);

    /**
     * Fraction stl extension for floor
     * @param f The fraction
     * @return The nearest integer not greater than f
     */
    template<class T>
    fraction<T> floor(const fraction<T>& f);

    /**
     * Fraction stl extension for ceil
     * @param f The fraction
     * @return The nearest integer not less than f
     */
    template<class T>
    fraction<T> ceil(const fraction<T>& f);

    /**
     * Fraction stl extension for round
     * @param f The fraction
     * @return The nearest integer to f
     */
    template<class T>
    fraction<T> round(const fraction<T>& f);

}

#include "fraction.ipp"

#endif //PROJECT_EULER_FRACTION_HPP
