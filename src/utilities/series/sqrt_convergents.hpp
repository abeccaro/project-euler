//
// Created by Alex Beccaro on 16/01/18.
//
#ifndef PROJECT_EULER_CONVERGENTS_HPP
#define PROJECT_EULER_CONVERGENTS_HPP

#include "lazy_series.hpp"
#include "template_conditions.hpp"
#include "fraction.hpp"

using template_conditions::is_any_integral;
using fractions::fraction;

namespace series {
    /**
     * Lazy series implementation for convergent fractions to irrational number.
     */
    template<class T, class = typename enable_if<is_any_integral<T>::value>::type>
    class sqrt_convergents : public lazy_series<fraction<T>> {
    public:
        explicit sqrt_convergents(const T& n) {
            auto a_0 = (T) sqrt(n);
            T a = a_0;
            T m = 0;
            T d = 1;

            do {
                m = d * a - m;
                d = (n - m * m) / d;
                a = (a_0 + m) / d;

                coeff.push_back(a);
            } while(coeff.back() != a_0 * 2);

            this->numbers.emplace_back(a_0);
            this->numbers.emplace_back(coeff.front() * a_0 + 1, coeff.front());
        }

    protected:
        fraction<T> next_element() final {
            auto n = this->numbers;
            uint s = n.size();

            T a = coeff[(this->numbers.size() - 1) % coeff.size()];
            T num = a * n[s-1].get_numerator() + n[s-2].get_numerator();
            T den = a * n[s-1].get_denominator() + n[s-2].get_denominator();

            return fraction<T>(num, den);
        }

    private:
        vector<T> coeff;
    };
}

#endif //PROJECT_EULER_CONVERGENTS_HPP
