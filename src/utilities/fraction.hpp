//
// Created by Alex Beccaro on 15/01/18.
//
#ifndef PROJECT_EULER_FRACTION_HPP
#define PROJECT_EULER_FRACTION_HPP

#include "template_conditions.hpp"
#include "generics.hpp"

using namespace template_conditions;
using namespace generics;


namespace fractions {

    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    class fraction {

    private:
        T num; // numerator
        T den; // denominator

        static bool auto_reduce; // if true fraction is reduced automatically when necessary

    public:

        /**
         * Default constructor for 0.
         */
        fraction() : num(0), den(1) {}

        /**
         * Constructor for integer numbers
         * @param n The number to represent as fraction
         */
        fraction(T n) : num(n), den(1) {}

        /**
         * Constructor for integer numbers
         * @param n The number to represent as fraction
         */
        template<class U, class = typename enable_if<is_convertible<U, T>::value>::type>
        fraction(U n) : num(n), den(1) {}

        /**
         * Complete constructor for a fraction
         * @param n The numerator
         * @param d The denominator
         */
        fraction(T n, T d) : num(n), den(d) {
            assert(den != 0 && "Denominator can't be 0");

            if (auto_reduce)
                reduce();
        }

        /**
         * Copy constructor
         * @param f The fraction to copy
         */
        template<class U, class = typename enable_if<is_convertible<U, T>::value>::type>
        fraction(const fraction<U>& f) : num(f.get_numerator()), den(f.get_denominator()) {}



        /**
         * Reduces this fraction to lowest terms and adjusts signs (if fraction < 0 then numerator will be negative
         * and denominator positive, otherwise both will be positive).
         */
        void reduce() {
            if (num < 0 && den < 0) {
                num = abs(num);
                den = abs(den);
            } else if (den < 0) {
                den = abs(den);
                num *= -1;
            }

            T g = generics::gcd<T>(abs(num), den);
            if (g != 1) {
                num /= g;
                den /= g;
            }
        }

        /**
         * Inverts this fraction
         */
        void invert() {
            assert(num != 0 && "Can't invert 0");

            T temp = num;
            num = den;
            den = temp;
        }


        ///region getters and setters

        /**
         * Sets auto reduction to specified value (true by default).
         * @param b The auto reduction state to set
         */
        static void set_auto_reduce(bool b) {
            auto_reduce = b;
        }

        /**
         * Gets the numerator value
         * @return The numerator
         */
        T get_numerator() const {
            return num;
        }

        /**
         * Gets the denominator value
         * @return The denominator
         */
        T get_denominator() const {
            return den;
        }

        /**
         * Sets the numerator to specified value
         * @param n The numerator to set
         */
        void set_numerator(const T& n) {
            num = n;
            if (auto_reduce)
                reduce();
        }

        /**
         * Sets the denominator to specified value
         * @param n The denominator to set
         */
        void set_denominator(const T& d) {
            assert(d != 0 && "Denominator can't be 0");

            den = d;
            if (auto_reduce)
                reduce();
        }

        /**
         * Returns the value of the function as a single number
         * @return The value
         */
        double get_value() const {
            return (double) *this;
        }

        ///endregion

        ///region operators

        /**
         * Assignment operator
         * @param f The value to assign
         * @return The reference to this object
         */
        fraction& operator = (const fraction<T>& f) {
            num = f.num;
            den = f.den;
            return *this;
        }

        /**
         * Equality check, takes into account possible reductions.
         * @param f The other fraction
         * @return True if they are equal, false otherwise
         */
        bool operator == (fraction<T> f2) const {
            fraction f1 = *this;
            f1.reduce();
            f2.reduce();

            return f1.num == f2.num && f1.den == f2.den;
        }

        /**
         * Inequality check, takes into account possible reductions.
         * @param f The other fraction
         * @return True if they are not equal, false otherwise
         */
        bool operator != (fraction<T> f2) const {
            return !(*this == f2);
        }

        /**
         * Less than check by value
         * @param f The other fraction
         * @return True if this is less than f, false otherwise
         */
        bool operator < (const fraction<T>& f) const {
            return get_value() < f.get_value();
        }

        /**
         * Less than or equal check by value
         * @param f The other fraction
         * @return True if this is equal to or less than f, false otherwise
         */
        bool operator <= (const fraction<T>& f) const {
            return *this == f || *this < f;
        }

        /**
         * Greater than check by value
         * @param f The other fraction
         * @return True if this is greater than f, false otherwise
         */
        bool operator > (const fraction<T>& f) const {
            return get_value() > f.get_value();
        }

        /**
         * Greater than or equal check by value
         * @param f The other fraction
         * @return True if this is equal to or greater than f, false otherwise
         */
        bool operator >= (const fraction<T>& f) const {
            return *this == f || *this > f;
        }

        /**
         * Sum operator.
         * @param other The fraction to add
         * @return The sum of this and other fractions
         */
        fraction operator +(const fraction<T>& other) const {
            T d = generics::lcm<T>(den, other.get_denominator());
            T n1 = num * d / den;
            T n2 = other.get_numerator() * d / other.get_denominator();
            fraction res(n1 + n2, d);

            return res;
        }

        /**
          * Shorthand for sum and auto assignment
          * @param other The fraction to sum
          * @return This fraction reference
          */
        fraction& operator +=(const fraction<T>& other) {
            T d = generics::lcm<T>(den, other.get_denominator());
            T n1 = num * d / den;
            T n2 = other.get_numerator() * d / other.get_denominator();

            num = n1 + n2;
            den = d;

            if (auto_reduce)
                reduce();

            return *this;
        }

        /**
         * Difference operator.
         * @param other The fraction to subtract
         * @return The difference of this and other fractions
         */
        fraction operator -(const fraction<T>& other) const {
            T d = generics::lcm<T>(den, other.get_denominator());
            T n1 = num * d / den;
            T n2 = other.get_numerator() * d / other.get_denominator();
            fraction res(n1 - n2, d);

            return res;
        }

        /**
          * Shorthand for difference and auto assignment
          * @param other The fraction to subtract
          * @return This fraction reference
          */
        fraction& operator -=(const fraction<T>& other) {
            T d = generics::lcm<T>(den, other.get_denominator());
            T n1 = num * d / den;
            T n2 = other.get_numerator() * d / other.get_denominator();

            num = n1 - n2;
            den = d;

            if (auto_reduce)
                reduce();

            return *this;
        }

        /**
         * Product operator.
         * @param other The fraction to multiply
         * @return The product of this and other fractions
         */
        fraction operator *(const fraction<T>& other) const {
            T n = num * other.get_numerator();
            T d = den * other.get_denominator();
            fraction res(n, d);

            return res;
        }

        /**
          * Shorthand for product and auto assignment
          * @param other The fraction to multiply
          * @return This fraction reference
          */
        fraction& operator *=(const fraction<T>& other) {
            num *= other.get_numerator();
            den *= other.get_denominator();

            if (auto_reduce)
                reduce();

            return *this;
        }

        /**
         * Division operator.
         * @param other The fraction to divide
         * @return The division of this and other fractions
         */
        fraction operator /(fraction<T> other) const {
            assert(other != 0 && "Can't divide by 0");

            other.invert();
            return *this * other;
        }

        /**
          * Shorthand for division and auto assignment
          * @param other The fraction to divide
          * @return This fraction reference
          */
        fraction& operator /=(fraction<T> other) {
            assert(other != 0 && "Can't divide by 0");

            other.invert();
            return *this *= other;
        }

        /**
         * Negation operator
         * @return The opposite of this fraction
         */
        fraction operator -() const {
            return fraction(-num, den);
        }

        ///endregion

        /**
         * Cast to another type
         * @return The closest representation of this fraction in type U
         */
        template<class U, class = typename enable_if<is_convertible<T, U>::value>::type>
        explicit operator U () const {
            return (U) num / den;
        }

    };

    template<class T, class U>
    bool fraction<T, U>::auto_reduce = true;


    /**
     * Output stream operator.
     * @param os The stream
     * @param f The fraction
     * @return The stream with this fraction representation
     */
    template<class T>
    ostream& operator<<(ostream& os, const fraction<T>& f) {
        os << f.get_numerator();
        T den = f.get_denominator();
        if (den != 1)
            os << "/" << den;
        return os;
    }

    /**
     * Fraction stl extension for pow
     * @param f The fraction
     * @param exp The exponent
     */
    template<class T>
    void pow(fraction<T>& f, const T& exp) {
        f.set_numerator(std::pow(f.get_numerator(), exp));
        f.set_denominator(std::pow(f.get_denominator(), exp));
    }

    /**
     * Fraction stl extension for max
     * @param f1 The first fraction
     * @param f2 The second fraction
     * @return f1 if f1 > f2, otherwise f2
     */
    template<class T>
    fraction<T> max(const fraction<T>& f1, const fraction<T>& f2) {
        return f1 < f2 ? f2 : f1;
    }

    /**
     * Fraction stl extension for min
     * @param f1 The first fraction
     * @param f2 The second fraction
     * @return f1 if f1 < f2, otherwise f2
     */
    template<class T>
    fraction<T> min(const fraction<T>& f1, const fraction<T>& f2) {
        return f1 < f2 ? f1 : f2;
    }

    /**
     * Fraction stl extension for abs
     * @param f The fraction
     * @return The absolute value of f
     */
    template<class T>
    fraction<T> abs(const fraction<T>& f) {
        return f < 0 ? -f : f;
    }

    /**
     * Fraction stl extension for floor
     * @param f The fraction
     * @return The nearest integer not greater than f
     */
    template<class T>
    fraction<T> floor(const fraction<T>& f) {
        T x = (T) f;
        if (f == x)
            return f;
        return fraction<T>(f < 0 ? x - 1 : x);
    }

    /**
     * Fraction stl extension for ceil
     * @param f The fraction
     * @return The nearest integer not less than f
     */
    template<class T>
    fraction<T> ceil(const fraction<T>& f) {
        T x = (T) f;
        if (f == x)
            return f;
        return fraction<T>(f < 0 ? x : x + 1);
    }

    /**
     * Fraction stl extension for round
     * @param f The fraction
     * @return The nearest integer to f
     */
    template<class T>
    fraction<T> round(const fraction<T>& f) {
        double v = f.get_value();
        if (v >= 0)
            return v - (T) v < 0.5 ? floor(f) : ceil(f);
        return v - (T) v <= -0.5 ? floor(f) : ceil(f);
    }

}

#endif //PROJECT_EULER_FRACTION_HPP
