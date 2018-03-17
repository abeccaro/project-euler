//
// Created by Alex Beccaro on 17/03/18.
//

#include "primes.hpp"

namespace series {

    template<class T, class U>
    primes<T, U>::primes() {
        this->numbers.emplace_back(2);
        next_multiples.emplace_back(0); // multiples of 2 are ignored

        this->numbers.emplace_back(3);
        next_multiples.emplace_back(9);
    }

    template<class T, class U>
    T primes<T, U>::next_element() {
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

}