//
// Created by Alex Beccaro on 11/12/17.
//
#ifndef PROJECT_EULER_GENERICS_H
#define PROJECT_EULER_GENERICS_H

#include <vector>
#include "template_conditions.hpp"
#include "primes.hpp"

using namespace std;
using namespace template_conditions;
using primes::prime_factors;

using uint = unsigned int;
using ulong = unsigned long;

namespace generics {
    /**
     * Divides given number in a vector of ordered digits.
     * @param n The number to divide
     * @return The vector of ordered digits
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<uint> digits(const T& n) {
        vector<uint> digits;
        T copy = n;

        if (copy < 0)
            copy *= -1;

        while (copy > 9) {
            auto d = (uint) (copy % 10);
            digits.push_back(d);
            copy /= 10;
        }
        digits.push_back((uint) copy);

        reverse(digits.begin(), digits.end());
        return digits;
    }

    /**
     * Creates the number formed by concatenating given digits.
     * @param digits The ordered digits
     * @return The number
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T from_digits(const vector<uint> &digits) {
        assert(all_of(digits.begin(), digits.end(), [](uint n){return n < 10;}) &&
                       "At least a non digit number (> 10)");

        T result = 0;
        ulong length = digits.size();

        for (ulong i = 0; i < length; i++)
            result += digits[length - i - 1] * pow(10, i);

        return result;
    }

    /**
     * Checks if given number is palindrome or not. It doesn't take into account sign.
     * @param n The number to check
     * @return true if the number is palindrome, false otherwise
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    bool is_palindrome(const T& n) {
        vector<uint> dig = digits(n);
        vector<uint> reversed_dig(dig.size());

        reverse_copy(dig.begin(), dig.end(), reversed_dig.begin());

        return dig == reversed_dig;
    }

    /**
     * Calculates the greatest common divisor of given numbers.
     * @param a The first number
     * @param b The second number
     * @return The gcd of given numbers
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T gcd(const T& a, const T& b) {
        assert (a >= 0 && b >= 0 && "Numbers can't be negative");

        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    /**
     * Calculates the greatest common divisor of given numbers.
     * @param numbers The numbers
     * @return The gcd of given numbers
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T gcd(const vector<T>& numbers) {
        assert (numbers.size() > 0 && "At least one number is required");

        T partial_gcd = numbers[0];

        for (auto i = numbers.begin() + 1; i < numbers.end(); i++)
            partial_gcd = gcd(partial_gcd, *i);

        return partial_gcd;
    }

    /**
     * Calculates lowest common multiple of given numbers.
     * @param a The first number
     * @param b The second number
     * @return The lcm of given numbers
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T lcm(const T& a, const T& b) {
        return (a * b) / gcd(a, b);
    };

    /**
     * Calculates lowest common multiple of given numbers.
     * @param numbers The numbers
     * @return The lcm of given numbers
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T lcm(const vector<T> &numbers) {
        assert (numbers.size() > 0 && "At least one number is required");

        T partial_lcm = numbers[0];

        for (auto i = numbers.begin() + 1; i < numbers.end(); i++)
            partial_lcm = lcm(partial_lcm, *i);

        return partial_lcm;
    }

    /**
     * Finds all divisors of n
     * @param n The number
     * @return The vector of divisors
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<T> divisors(const T& n) {
        assert (n > 0 && "Numbers must be positive");

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
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T factorial(const T& n) {
        assert(n >= 0 && "Number can't be negative");

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
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T binomial_coefficient(const T& n, const T& k) {
        assert(n >= 0 && k >= 0 && "Numbers must be positive");
        assert(n >= k && "Invalid arguments values");

        T num = 1;

        for (T i = n; i > n - k; i--)
            num *= i;

        T den = factorial(k);

        return num / den; // safe integer division, result is always integer
    }

    /**
     * Checks if given numbers are coprime.
     * @param a The first number
     * @param b The second number
     * @return True if given numbers are coprime, false otherwise
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    bool are_coprime(const T &a, const T &b) {
        return gcd(a,b) == 1;
    }

    /**
     * Calculates the multiplicative order of n modulo mod.
     * Note that n and mod have to be coprimes. This is assumed by function.
     * @param n The number
     * @param mod The modulo
     * @return The multiplicative order
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T multiplicative_order(const T& base, const T& mod) {
        assert(mod > 1 && "Modulo must be greater than 1");
        assert(are_coprime(base, mod) && "Multiplicative order is not defined for given values");

        ulong exp = 1;
        while ((T) pow(base, exp) % mod != 1)
            exp++;
        return exp;
    }

    /**
     * Calculates all the rotation of given number, e.g.: 197 -> [197, 971, 719].
     * The first is given number itself (0-digits rotation)
     * @param n The number
     * @return All the rotations
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<T> rotations(const T& n) {
        vector<uint> digs = digits(n);
        ulong length = digs.size();

        vector<T> result(length);
        result[0] = n;

        for (ulong i = 1; i < length; i++) {
            vector<uint> ds(length);

            copy(digs.begin() + i, digs.end(), ds.begin());
            ulong copied = length - i;
            copy(digs.begin(), digs.begin() + i, ds.begin() + copied);

            result[i] = from_digits<T>(ds);
        }

        return result;
    }

    /**
     * Converts given number from base 10 to given base
     * @param n The number
     * @param base The base to convert the number to
     * @return The converted number's digits
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<uint> to_base(const T& n, uint base) {
        assert (base > 0 && "Base must be positive");

        vector<uint> digits;
        T copy = n;

        while (copy > 0) {
            digits.push_back(copy % base);
            copy = copy / base;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    };

    /**
     * Converts given number from given base to base 10
     * @param n The number
     * @param base The number's base
     * @return The number base 10
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T from_base(const T& n, uint base) {
        assert (base > 0 && "Base must be positive");

        T result = 0;
        vector<uint> digs = digits(n);
        ulong size = digs.size();

        for (ulong i = 0; i < size; i++)
            result += digs[size-i-1] * pow(base, i);

        return result;
    };

    /**
     * Converts given number from a base to another base
     * @param n The number
     * @param from The current base
     * @param to The base to convert the number to
     * @return The converted number's digits
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    vector<uint> to_base(const T& n, uint from, uint to) {
        from_base(from_digits<T>(to_base(n, 2)), 2);
    };

    /**
     * Template version of std::abs that allows unsigned types to have a non ambiguous call.
     * This is needed in some template instantiations.
     * @param n The number
     * @return The absolute value of n
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T abs(const T& n) {
        return n < 0 ? -n : n;
    };

    /**
     * Calculates the number of x <= n coprimes with n
     * @param n The number
     * @return The number of x <= n coprimes with n
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    T totient(const T& n) {
        vector<T> p = prime_factors<T>(n);

        T num = 1;
        T den = 1;
        for (const auto& prime : p) {
            num *= prime - 1;
            den *= prime;
        }

        return n * num / den;
    };
}

#endif //PROJECT_EULER_GENERICS_H