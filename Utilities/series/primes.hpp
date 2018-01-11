//
// Created by Alex Beccaro on 13/12/17.
//
#ifndef PROJECT_EULER_PRIMES_H
#define PROJECT_EULER_PRIMES_H

#include "lazy_series.hpp"
#include "template_conditions.hpp"

using template_conditions::is_any_integral;

using ulong = unsigned long;

namespace series {
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    /**
     * Lazy series implementation for prime numbers.
     * It is less performant than utilities function primes::get and primes::getUpTo.
     * The advantages are in the lazyness.
     */
    class primes : public lazy_series<T>{
    public:
        /**
         * Default constructor that adds first 2 numbers.
         */
        primes() {
            this->numbers.emplace_back(2);
            next_multiples.emplace_back(0); // multiples of 2 are ignored

            this->numbers.emplace_back(3);
            next_multiples.emplace_back(9);
        }

    protected:
        /**
         * Calculates next prime number.
         * @return The next prime number
         */
        T next_element() final {
            ulong size = this->numbers.size();
            ulong n = size + 1;
            T ub = n < 6 ? 14 : (T) (n * (log(n) + log(log(n))));

            prime_checks.resize((ulong) (ub / 2), true);
            auto root = sqrt(ub);

            for (ulong i = 1; this->numbers[i] < root && i < size; i++) {
                while (next_multiples[i] < ub) {
                    // FIXME: cast might be lossy! (very very high values)
                    prime_checks[(ulong) (next_multiples[i] / 2)] = false;
                    next_multiples[i] += 2 * this->numbers[i];
                }
            }

            for (T i = this->numbers.back() + 2; ; i += 2)
                // FIXME: cast might be lossy (very very high values)
                if (prime_checks[(ulong) (i / 2)]) {
                    next_multiples.emplace_back(i * i);
                    return i;
                }
        }

    private:
        /**
         * Vector for odd numbers only. If a value is false it means that the n-th odd number is not prime.
         * If value is true it can be both prime or not.
         */
        vector<bool> prime_checks{};

        /**
         * The highest multiple of the n-th prime that has been set as not prime.
         */
        vector<T> next_multiples{};
    };
}


#endif //PROJECT_EULER_PRIMES_H
