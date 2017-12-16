//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_GENERICS_H
#define PROJECT_EULER_GENERICS_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using std::vector;
using namespace boost::multiprecision;

namespace generics {
    /**
     * Divides given number in a vector of ordered digits.
     * @param n The number to divide
     * @return The vector of ordered digits
     */
    template<class T>
    vector<unsigned short> digits(const T& n) {
        vector<unsigned short> digits;
        T copy = n;

        while (copy > 9) {
            unsigned short d = (unsigned short) (copy % 10);
            digits.push_back(d);
            copy /= 10;
        }
        digits.push_back((unsigned short) copy);

        reverse(digits.begin(), digits.end());
        return digits;
    }

    /**
     * Checks if given number is palindrome or not.
     * @param n The number to check
     * @return true if the number is palindrome, false otherwise
     */
    template<class T>
    bool is_palindrome(const T& n) {
        vector<unsigned short> dig = digits(n);
        vector<unsigned short> reversed_dig(dig.size());

        reverse_copy(dig.begin(), dig.end(), reversed_dig.begin());

        return dig == reversed_dig;
    }

    /**
     * Calculates lowest common multiple of given numbers.
     * This might not be so efficient for many numbers.
     * @param numbers The numbers
     * @return The lcm of given numbers
     */
    template<class T>
    T lcm(const vector<T> &numbers) {
        T product = 1;
        for (T i : numbers)
            product *= i;

        for (T i : numbers) {
            T n = product / i;
            bool divides_all = true;

            for (T j : numbers)
                if (n % j != 0) {
                    divides_all = false;
                    break;
                }

            if (divides_all)
                product = n;
        }

        return product;
    }

    /**
     * Finds all divisors of n
     * @param n The number
     * @return The vector of divisors
     */
    template<class T>
    vector<T> divisors(const T& n) {
        vector<T> divisors;
        auto root = sqrt(n);

        for (T i = 1; i < root; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                divisors.push_back(n / i);
            }
        }

        if (root == (T) root)
            divisors.push_back((T) root);

        return divisors;
    }

    /**
     * Calculates the factorial of given number
     * @param n The number
     * @return The factorial
     */
    template<class T>
    T factorial(const T& n) {
        if (n == 0)
            return 1;

        T result = 1;
        for (T i = 2; i <= n; i++)
            result *= i;

        return result;
    }

    /**
     * Calculates the binomial coefficient
     * @param n The first number
     * @param k The second number
     * @return The binomial coefficient
     */
    template<class T>
    T binomial_coefficient(const T& n, const T& k) {
        T num = 1;

        for (T i = n; i > n - k; i--)
            num *= i;

        T den = factorial(k);

        return num / den; // safe integer division, result is always integer
    }
}

#endif //PROJECT_EULER_GENERICS_H