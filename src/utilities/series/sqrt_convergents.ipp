//
// Created by Alex Beccaro on 17/03/18.
//

namespace series {

    template<class T, class U>
    sqrt_convergents<T, U>::sqrt_convergents(const T &n) {
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

    template<class T, class U>
    fractions::fraction<T> sqrt_convergents<T, U>::next_element() {
        auto n = this->numbers;
        uint s = n.size();

        T a = coeff[(this->numbers.size() - 1) % coeff.size()];
        T num = a * n[s-1].numerator() + n[s-2].numerator();
        T den = a * n[s-1].denominator() + n[s-2].denominator();

        return {num, den};
    }

}