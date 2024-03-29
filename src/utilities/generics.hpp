//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_GENERICS_H
#define PROJECT_EULER_GENERICS_H

#include "template_conditions.hpp"

namespace generics {
    /**
     * Divides given number in a vector of ordered digits.
     * @param n The number to divide
     * @return The vector of ordered digits
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<uint32_t> digits(const T& n);

    /**
     * Creates the number formed by concatenating given digits.
     * @param digits The ordered digits
     * @return The number
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T from_digits(const std::vector<uint32_t>& digits);

    /**
     * Checks if given number is palindrome or not. It doesn't take into account sign.
     * @param n The number to check
     * @return true if the number is palindrome, false otherwise
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    bool is_palindrome(const T& n);

    /**
     * Calculates the greatest common divisor of given numbers.
     * @param a The first number
     * @param b The second number
     * @return The gcd of given numbers
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T gcd(const T& a, const T& b);

    /**
     * Calculates the greatest common divisor of given numbers.
     * @param numbers The numbers
     * @return The gcd of given numbers
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T gcd(const std::vector<T>& numbers);

    /**
     * Calculates lowest common multiple of given numbers.
     * @param a The first number
     * @param b The second number
     * @return The lcm of given numbers
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T lcm(const T& a, const T& b);

    /**
     * Calculates lowest common multiple of given numbers.
     * @param numbers The numbers
     * @return The lcm of given numbers
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T lcm(const std::vector<T>& numbers);

    /**
     * Finds all divisors of n
     * @param n The number
     * @return The vector of divisors
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<T> divisors(const T& n);

    /**
     * Finds the number of divisors of n
     * @param n The number
     * @return The number of divisors of n
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T divisors_count(const T& n);

    /**
     * Calculates the factorial of given number
     * @param n The number
     * @return The factorial
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T factorial(const T& n);

    /**
     * Calculates the binomial coefficient
     * @param n The first number
     * @param k The second number
     * @return The binomial coefficient
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T binomial_coefficient(const T& n, const T& k);

    /**
     * Checks if given numbers are coprime.
     * @param a The first number
     * @param b The second number
     * @return True if given numbers are coprime, false otherwise
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    bool are_coprime(const T& a, const T& b);

    /**
     * Generates all the coprime pairs with numbers up to given limit (n-th Farey sequence).
     * @param n The upper bound for numbers
     * @return All the coprime pairs with numbers up to given limit n
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<std::pair<T, T>> coprime_pairs(const T& n);

    /**
     * Calculates the multiplicative order of n modulo mod.
     * Note that n and mod have to be coprimes. This is assumed by function.
     * @param n The number
     * @param mod The modulo
     * @return The multiplicative order
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T multiplicative_order(const T& base, const T& mod);

    /**
     * Calculates all the rotation of given number, e.g.: 197 -> [197, 971, 719].
     * The first is given number itself (0-digits rotation)
     * @param n The number
     * @return All the rotations
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<T> rotations(const T& n);

    /**
     * Converts given number from base 10 to given base
     * @param n The number
     * @param base The base to convert the number to
     * @return The converted number's digits
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<uint32_t> to_base(const T& n, uint32_t base);

    /**
     * Converts given number from given base to base 10
     * @param n The number
     * @param base The number's base
     * @return The number base 10
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T from_base(const T& n, uint32_t base);

    /**
     * Template version of std::abs that allows unsigned types to have a non ambiguous call.
     * This is needed in some template instantiations.
     * @param n The number
     * @return The absolute value of n
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T abs(const T& n);

    /**
     * Calculates the number of x <= n coprimes with n
     * @param n The number
     * @return The number of x <= n coprimes with n
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T totient(const T& n);

    /**
     * Generates all possible combinations of k items from given elements.
     * Elements are supposed all different and are treated as such.
     * @tparam T The type of elements
     * @param elements The elements to choose from
     * @param k The number of elements to choose
     * @return All the combinations
     */
    template<class T>
    std::vector<std::vector<T>> combinations(const std::vector<T>& elements, uint64_t k);

    /**
     * Generates all possible combinations (with possible repetitions) of k items from given elements.
     * Elements are supposed all different and are treated as such.
     * @tparam T The type of elements
     * @param elements The elements to choose from
     * @param k The number of elements to choose
     * @return All the combinations
     */
    template<class T>
    std::vector<std::vector<T>> combinations_repetition(const std::vector<T>& elements, uint64_t k, const std::vector<T>& prefix = {});

    /**
     * Calculates b^exp efficiently for integers
     * @param b The base
     * @param exp The exponent
     * @return The result of b^exp
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T int_pow(T b, T exp);

    /**
     * Calculates (base ^ exponent) mod modulo
     * @param base The base
     * @param exponent The exponent
     * @param modulo The modulo
     * @return The result
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    T mod_pow(T base, T exponent, const T& modulo);

    /**
     *
     */
    template<class T, class = typename std::enable_if<template_conditions::is_any_integral<T>::value>::type>
    std::vector<T> continued_fraction(T num, T den);
}

#include "generics.ipp"

#endif //PROJECT_EULER_GENERICS_H