//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_GENERICS_H
#define PROJECT_EULER_GENERICS_H

#include <vector>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
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
            auto d = (unsigned short) (copy % 10);
            digits.push_back(d);
            copy /= 10;
        }
        digits.push_back((unsigned short) copy);

        reverse(digits.begin(), digits.end());
        return digits;
    }

    /**
     * Creates the number formed by concatenating given digits.
     * @param digits The ordered digits
     * @return The number
     */
    template<class T>
    T from_digits(const vector<unsigned short> &digits) {
        T result = 0;
        unsigned long length = digits.size();

        for (unsigned long i = 0; i < length; i++)
            result += digits[length - i - 1] * pow(10, i);

        return result;
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
     * Calculates the greatest common divisor of given numbers.
     * @param a The first number
     * @param b The second number
     * @return The gcd of given numbers
     */
    template<class T>
    T gcd(const T& a, const T& b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
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

    template<class T>
    bool areCoprime(const T& a, const T& b) {
        return gcd(a,b) == 1;
    }

    /**
     * Calculates the multiplicative order of n modulus mod.
     * Note that n and mod have to be coprimes. This is assumed by function.
     * @param n The number
     * @param mod The modulus
     * @return The multiplicative order
     */
    template<class T>
    T multiplicative_order(const T& n, const T& mod) {
        unsigned long exp = 1;
        while ((T) pow(n, exp) % mod != 1)
            exp++;
        return exp;
    }

    /**
     * Calculates all the rotation of given number, e.g.: 197 -> [197, 971, 719].
     * The first is given number itself (0-digits rotation)
     * @param n The number
     * @return All the rotations
     */
    template<class T>
    vector<T> rotations(T n) {
        vector<unsigned short> digs = digits(n);
        unsigned long length = digs.size();

        vector<T> result(length);
        result[0] = n;

        for (unsigned long i = 1; i < length; i++) {
            vector<unsigned short> ds(length);

            copy(digs.begin() + i, digs.end(), ds.begin());
            unsigned long copied = length - i;
            copy(digs.begin(), digs.begin() + i, ds.begin() + copied);

            result[i] = from_digits<T>(ds);
        }

        return result;
    }
}

#endif //PROJECT_EULER_GENERICS_H